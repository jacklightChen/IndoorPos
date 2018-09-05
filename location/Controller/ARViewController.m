//
//  ARViewController.m
//  location
//
//  Created by 陈之豪 on 2018/8/9.
//  Copyright © 2018年 陈之豪. All rights reserved.
//

#import "ARViewController.h"
#import "Coordination.h"

@interface ARViewController ()
@property(nonatomic,strong)ARSCNView *sceneView;

//AR会话，负责管理相机追踪配置及3D相机坐标
@property(nonatomic,strong)ARSession *arSession;

//会话追踪配置：负责追踪相机的运动
@property(nonatomic,strong)ARWorldTrackingConfiguration *arWorldTrackingConfiguration;

@property(nonatomic,weak)IBOutlet UILabel *resultLabel;
@end

@implementation ARViewController
@synthesize map;

- (void)viewDidLoad {
    [super viewDidLoad];
    /* 路径只用到一次*/
    NaviResult *res=[map getNavi];
    [self showRoute:res.array];
    
    [NSTimer scheduledTimerWithTimeInterval:1.5 target:self selector:@selector(showDisText) userInfo:nil repeats:YES];

}


-(void)showRoute:(NSMutableArray *)array{
    SCNScene *arrow=[SCNScene sceneNamed:@"art.scnassets/arrow.scn"];
    SCNNode *target=arrow.rootNode.childNodes[1];
    SCNNode *flag=arrow.rootNode.childNodes[2];
    
    /* 保存所有节点*/
    NSMutableArray *nodes=[NSMutableArray array];
    double tilespacing=3;

    for(int i=0;i<array.count;i++){
        Coordination *temp=[array objectAtIndex:i];
        /* transform*/
        double x=temp.y;
        double y=temp.x;
        SCNNode * node = target.clone;
//        node.scale=SCNVector3Make(0.01, 0.005, 0.01);
        node.position=SCNVector3Make(x+2, -2, y);
        [self initForward:node];
        [nodes addObject:node];
        [self.arSCNView.scene.rootNode addChildNode:node];
        /* 在箭头和箭头之间插入箭头
         * 但显示不友好 注掉了
         * 使导航路线看起来更紧密 */
        if(i==array.count-1)continue;
        Coordination *next=[array objectAtIndex:i+1];
        double offsetX=next.x-temp.x;
        double offsetY=next.y-temp.y;

//        for(int i=0;i<offsetX/tilespacing;i++){
//            SCNNode * node=target.clone;
//            node.scale=SCNVector3Make(0.1, 0.05, 0.1);
//            node.position=SCNVector3Make(x+i*tilespacing, 0, -(y+i*tilespacing/offsetX*offsetY));
//            [self initForward:node];
//            [nodes addObject:node];
//            [self.arSCNView.scene.rootNode addChildNode:node];
//        }
    }
    
    /* 角度有小bug 没时间调了*/
    for(int i=0;i<nodes.count-1;i++){
        SCNNode *now=[nodes objectAtIndex:i];
        SCNNode *aft=[nodes objectAtIndex:i+1];
        SCNVector3 vec1=SCNVector3Make(0, 0, -1);
        SCNVector3 vec2=[self generateVector:now.position :aft.position];
        double angle=[self angleBetweenVector:vec1 :vec2];
        [now runAction:
         [SCNAction repeatAction:
          [SCNAction rotateByX:0 y:-angle z:0 duration:0] count:1]];
    }
    
    /* 添加终点的旗帜*/
    Coordination *temp=[array objectAtIndex:array.count-1];
    /* transform*/
    double x=temp.y;
    double y=temp.x;
    flag.position=SCNVector3Make(x+2, -2, y);
    [self.arSCNView.scene.rootNode addChildNode:flag];
}

-(void)initForward:(SCNNode *)node{
    node.scale=SCNVector3Make(0.3, 0.3, 0.3);
    [node runAction:
     [SCNAction repeatAction:
      [SCNAction rotateByX:0 y:-M_PI_4 z:0 duration:0] count:1]];
}
-(SCNVector3)generateVector :(SCNVector3)vec1 :(SCNVector3)vec2{
    SCNVector3 vec3;
    vec3.x=vec2.x-vec1.x;
    vec3.y=vec2.y-vec1.y;
    vec3.z=vec2.z-vec1.z;
    return vec3;
}

-(double)lengthOfVector :(SCNVector3)vec{
    return sqrt(vec.x*vec.x+vec.y*vec.y+vec.z*vec.z);
}

-(double)angleBetweenVector :(SCNVector3)vec1 :(SCNVector3)vec2{
    double up=vec1.x*vec2.x+vec1.y*vec2.y+vec1.z*vec2.z;
    double down=[self lengthOfVector:vec1]*[self lengthOfVector:vec2];
    return acos(up/down);
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (void)viewDidAppear:(BOOL)animated
{
    [super viewDidAppear:animated];

    //1.将AR视图添加到当前视图
    [self.view addSubview:self.arSCNView];

    //2.开启AR会话（此时相机开始工作）
    [self.arSession runWithConfiguration:self.arSessionConfiguration options:ARSessionRunOptionResetTracking|ARSessionRunOptionRemoveExistingAnchors];
  
    [self.view addSubview:_resultLabel];

}
/*识别指定图像 ios11.3以上 测试机没有= = 初始朝向解决方案*/
-(void)renderer:(id<SCNSceneRenderer>)renderer didAddNode:(SCNNode *)node forAnchor:(ARAnchor *)anchor{
//    if(!_flag){
//        /*重新开启session*/
//        /*并放置物体*/
//        NSMutableArray *array=[map getNavi].array;
//        [self showRoute:array];
//        _flag=YES;
//    }
}

-(void)showDisText{
    double sumDis=map.getNavi.sumDis;
    _resultLabel.text=[[NSString alloc]initWithFormat:@"距终点 %.2f 米",sumDis];
}
#pragma mark -搭建ARKit环境


/* 懒加载会话追踪配置*/
- (ARWorldTrackingConfiguration *)arSessionConfiguration
{
    if (_arWorldTrackingConfiguration != nil) {
        return _arWorldTrackingConfiguration;
    }
    
    ARWorldTrackingConfiguration *configuration = [[ARWorldTrackingConfiguration alloc] init];
    configuration.planeDetection = ARPlaneDetectionHorizontal;
    
//       NSSet<ARReferenceImage *> *image=[ARReferenceImage referenceImagesInGroupNamed:@"AR Resources" bundle:nil];
//    configuration.detectionImages=image;
//
    _arWorldTrackingConfiguration = configuration;
    _arWorldTrackingConfiguration.lightEstimationEnabled = YES;
    
    return _arWorldTrackingConfiguration;

}

/* 懒加载拍摄会话*/
- (ARSession *)arSession
{
    if(_arSession != nil)
    {
        return _arSession;
    }
    _arSession = [[ARSession alloc] init];
    return _arSession;
}

/* 创建AR视图*/
- (ARSCNView *)arSCNView
{
    if (_sceneView != nil) {
        return _sceneView;
    }
    _sceneView = [[ARSCNView alloc] initWithFrame:self.view.bounds];
    _sceneView.session = self.arSession;
    _sceneView.automaticallyUpdatesLighting = YES;
    return _sceneView;
}

@end
