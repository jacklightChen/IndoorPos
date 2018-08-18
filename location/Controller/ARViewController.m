//
//  ARViewController.m
//  location
//
//  Created by 陈之豪 on 2018/8/9.
//  Copyright © 2018年 陈之豪. All rights reserved.
//

#import "ARViewController.h"
#import "Coordination.h"

@interface ARViewController () <ARSCNViewDelegate>

@property (nonatomic, strong) IBOutlet ARSCNView *sceneView;
@property (weak, nonatomic) NSMutableArray *route;

@end

@implementation ARViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    [self showRoute:_route];
}

-(void)showRoute:(NSMutableArray *)array{
    SCNScene *scene=[SCNScene new];
    SCNScene *arrow=[SCNScene sceneNamed:@"art.scnassets/arrow.scn"];
    SCNNode *target=arrow.rootNode.childNodes[0];
    NSMutableArray *nodes=[NSMutableArray array];
    for(Coordination * temp in array){
        /*transform*/
        double x=temp.x;
        double y=temp.y;
        SCNNode * node = target.clone;
        node.scale=SCNVector3Make(0.5, 0.5, 0.5);
        node.position=SCNVector3Make(x, 0, -y);
        [self initForward:node];
        [nodes addObject:node];
        [scene.rootNode addChildNode:node];
    }
    
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
    
    self.sceneView.scene=scene;
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

- (void)viewWillAppear:(BOOL)animated{
    [super viewWillAppear:animated];
    ARWorldTrackingConfiguration *config=[ARWorldTrackingConfiguration new];
    
    /*ARSession需要先配置configuratoin*/
    [self.sceneView.session runWithConfiguration:config];
}

/*button*/
- (IBAction)prepareForSegue:(UIStoryboardSegue *)segue{
    NSLog(@"%@",segue.sourceViewController);
}

@end
