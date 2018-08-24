//
//  MapViewController.m
//  location
//
//  Created by 陈之豪 on 2018/8/8.
//  Copyright © 2018年 陈之豪. All rights reserved.
//

#import "MapViewController.h"
#import "FMMapKit.h"
#import "BRTBeaconScan.h"
#import "ARViewController.h"

@interface MapViewController () <FMKMapViewDelegate>
{
    FMKMapView *_mapView;
    BOOL _isFinishLoadingMap;
    /// 地图路径分析对象
    FMKNaviAnalyser *_naviAnalyser;
    
    FMKImageLayer *_imageLayer;
    FMKImageMarker *_startMarker;
    FMKImageMarker *_endMarker;
    
    FMKGeoCoord _startCoord;
    FMKGeoCoord _endCoord;
    
    /// 定位标注
    FMKLocationMarker *_locationMarker;
}
@end

@implementation MapViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    /*开始扫描ibeacon*/
    BRTBeaconScan *scan=[BRTBeaconScan new];
    [scan start:self];
    
    // 离线地图加载
    NSString *dataPath = [[NSBundle mainBundle] pathForResource:@"cmbintern" ofType:@"fmap"];
    _mapView = [[FMKMapView alloc] initWithFrame:CGRectMake(0, 64, [UIScreen mainScreen].bounds.size.width, [UIScreen mainScreen].bounds.size.height-64) path:dataPath delegate:self];
//    [_mapView.map setZoomLevel:5 animated:NO];
    _mapView.enable3D = NO;
    if (!_isFinishLoadingMap) {
        return;
    }
    [self.view addSubview:_mapView];
    
    // 通过地图数据路径初始化路径分析
    _naviAnalyser = [[FMKNaviAnalyser alloc] initWithMapPath:dataPath];

    _imageLayer = [[FMKImageLayer alloc] initWithGroupID:@"1"];
    [_mapView.map addLayer:_imageLayer];
    
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

#pragma mark - FMKMapViewDelegate
- (void)mapViewDidFinishLoadingMap:(FMKMapView *)mapView {
    NSLog(@"地图加载完成");
    _isFinishLoadingMap = YES;
//    [SVProgressHUD showWithStatus:@"识别中"];
//    [SVProgressHUD showSuccessWithStatus:@"识别成功 开始导航!"];
    
}
- (void)mapViewDidFailLoadingMap:(FMKMapView *)mapView withError:(NSError *)error {
    NSLog(@"地图加载失败-%@", error);
}
- (void)mapView:(FMKMapView *)mapView didSingleTapWithPoint:(CGPoint)point {
    // 屏幕坐标转换为地理坐标
    FMKGeoCoord coord = [_mapView coverPoint:point];
    double curx=[BRTBeaconScan getCurX];
    double cury=[BRTBeaconScan getCurY];
    
    FMKGeoCoord start = FMKGeoCoordMake(1, FMKMapPointMake(curx, cury));
    if(curx==0&&cury==0){start = [_mapView coverPoint:point];}
    // 可以根据 coord.mapPoint.x == 0 && coord.mapPoint.y == 0 判断触摸点是否在地图上
    if (coord.mapPoint.x == 0 && coord.mapPoint.y == 0) return;
    
  
        // 删除原来的marker和路径
        [_imageLayer removeMarker:_startMarker];
        _startMarker = nil;
        [_imageLayer removeMarker:_endMarker];
        _endMarker = nil;
        // 删除所有线标注
        [_mapView.map.lineLayer removeAll];
        
        // 添加起点
        _startMarker = [[FMKImageMarker alloc] initWithImage:[UIImage imageNamed:@"start"] Coord:coord.mapPoint];
        _startMarker.imageSize = CGSizeMake(30, 30);
        _startMarker.offsetMode = FMKImageMarker_USERDEFINE;
        _startMarker.imageOffset = 5.0f;
        [_imageLayer addMarker:_startMarker];
        _startCoord = start;
   
        // 添加终点
        _endMarker = [[FMKImageMarker alloc] initWithImage:[UIImage imageNamed:@"end"] Coord:coord.mapPoint];
        _endMarker.imageSize = CGSizeMake(30, 30);
        _endMarker.offsetMode = FMKImageMarker_USERDEFINE;
        _endMarker.imageOffset = 5.0f;
        [_imageLayer addMarker:_endMarker];
        _endCoord = coord;
        
        // 添加线标注，规划路径
        [self naviRouteAnalyserWithStart:_startCoord end:_endCoord];
    
}

#pragma mark - 路径规划
/// 路径规划 并返回路径的长度
- (NaviResult *)naviRouteAnalyserWithStart:(FMKGeoCoord)start end:(FMKGeoCoord)end {
    NSMutableArray *result = [NSMutableArray array];
    // sumDis:路径总长度
    double sumDis=0;
    //返回的包装类
    NaviResult *navi=[[NaviResult alloc]init];
    
    // 路径分析类型设置
    FMKRouteSetting routeSetting;
    routeSetting.naviModule = MODULE_BEST;
    routeSetting.routeCrossGroupPriority = FMKROUTE_CGP_DEFAULT;
    // 进行路径计算分析
    FMKRouteCalculateResultType type = [_naviAnalyser analyseRouteWithStartCoord:start end:end type:routeSetting routeResult:&result];
    //若分析结果不成功，直接返回
    
    // array:保存路径规划得到的点
    NSMutableArray *array=[[NSMutableArray alloc]init];
    switch (type) {
        case IROUTE_SUCCESS: {
            // 初始化线标注
            FMKLineMarker *line = [[FMKLineMarker alloc] init];
            /*传递点集在SceneKit中放置箭头*/
            for (FMKNaviResult *navi in result) {
                for(NSValue *value in navi.pointArray){
                    FMKMapPoint point;
                    [value getValue:&point];
                    point.x+=13544225.0;
                    point.y+=3665146.5;
                    Coordination* c=[[Coordination alloc]initWithX:point.x andY:point.y];
                    [array addObject:c];
                }
                //利用分析结果添加segment
                FMKSegment *segment = [[FMKSegment alloc] initWithGroupID:navi.groupID pointArray:navi.pointArray];
                //在直线中添加segment
                [line addSegment:segment];
                //计算路径总长度
                sumDis+=segment.length;
            }
            line.width=1;
            [_mapView.map.lineLayer addMarker:line];
        }
            break;
        default:
            break;
    }
    navi.sumDis=sumDis;
    navi.array=array;
    return navi;
}

-(void)showPointWithX:(double)x andY:(double)y{
    FMKMapPoint point = FMKMapPointMake(x, y);
    //3665146.5 13544226.7
    
    FMKGeoCoord coord = FMKGeoCoordMake(1, point);
    // 初始化定位标注
    _locationMarker = [[FMKLocationMarker alloc] initWithPointerImageName:@"active.png" DomeImageName:@""];
    
    // 添加定位标注到定位标注层(必须先添加，然后设置定位标注的大小和位置，否则设置无效！)
    // 地图定位标注层 _mapView.map.locateLayer (直接获取 ，不支持创建)
    [_mapView.map.locationLayer addMarker:_locationMarker];
    
    _locationMarker.size = CGSizeMake(30, 30);
    // 模拟定位
    [_locationMarker locateWithGeoCoord:coord];
    // 更新定位方向
    [_locationMarker updateRotate:90];
    
}

/*获得离终点的距离*/
-(NaviResult *)getNavi{
    FMKGeoCoord start = FMKGeoCoordMake(1, FMKMapPointMake(curx, cury));
    return [self naviRouteAnalyserWithStart:start end:_endCoord];
}

/*button*/
- (IBAction)unwindSegue:(UIStoryboardSegue *)sender{
    NSLog(@"unwindSegue %@", sender);
}

- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    if([segue.identifier isEqualToString:@"sendValue"]){
        ARViewController* page2 = segue.destinationViewController;
        // 对page2中的变量设置值
        [page2 setMap:self];
    }
}
@end
