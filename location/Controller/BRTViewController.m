/*
 *  废弃代码
 *
 */
////
////  BRTViewController.m
////  location
////
////  Created by 陈之豪 on 2018/8/1.
////  Copyright © 2018年 陈之豪. All rights reserved.
////
//
//#import "BRTViewController.h"
//
//@implementation BRTViewController
//- (void)viewDidLoad {
//    [super viewDidLoad];
//    [self turnOnMap];
//    [self turnOnBeacon];
//}
//
//-(void) turnOnMap{
//    self.mapView = [[BRTMapView alloc] initWithFrame:self.view.bounds];
//    [self.view addSubview:self.mapView];
//    [self.mapView setDelegate:self];
//    [self.mapView loadWithBuilding:@"ZS030002" appkey:@"ZSYSJZ83ce7c4cf094cd17d170b3d880"];
//}
//
//#pragma mark - Beacons Methods
//- (void) turnOnBeacon{
//    //初始化定位数据
//    _locationManager = [[BRTLocationManager alloc]initWithBuildingID:@"ZS030002" initAngle:1 appKey:@"ZSYSJZ83ce7c4cf094cd17d170b3d880"];
//    [self.locationManager setRssiThreshold:-90];
//    _locationManager.delegate = self;
//    //定位超时错误回调时间（秒）
//    self.locationManager.requestTimeOut =  10;
//    //限制最大定位设备个数5个
//    [self.locationManager setMaxBeaconNumberForProcessing:5];
//    [self.locationManager setLimitBeaconNumber:YES];
//    //关闭定位热力数据上传
//    [self.locationManager enableHeatData:NO];
//    [_locationManager startUpdateLocation];
//}
//
//#pragma mark - **************** 定位回调方法
//
////返回beacon定位，固定1s/次
//- (void)BRTLocationManager:(BRTLocationManager *)manager didUpdateImmediateLocation:(BRTLocalPoint *)newImmediateLocation {
//    //不要和didUpdateLocation同时显示位置，会导致位置跳动
//    //[self.mapView showLocation:newImmediateLocation];
////    NSLog(@"2");
//}
//
////返回beacon + 传感器优化定位，最快0.2s/次
//- (void)BRTLocationManager:(BRTLocationManager *)manager didUpdateLocation:(BRTLocalPoint *)newLocation {
//    [self.mapView showLocation:newLocation];
////    NSLog(@"1");
//}
///**
// *  位置更新失败事件回调
// *
// *  @param manager 定位引擎实例
// */
//- (void)BRTLocationManager:(BRTLocationManager *)manager didFailUpdateLocation:(NSError *)error {
//    NSLog(@"定位失败：%@",error);
//}
//
///**
// *  Beacon扫描结果事件回调，返回符合扫描参数的所有Beacon
// *
// *  @param manager 定位引擎实例
// *  @param beacons Beacon数组，[BRTBeacon]
// */
//- (void)BRTLocationManager:(BRTLocationManager *)manager didRangedBeacons:(NSArray *)beacons {
//        NSLog(@"all beacons find:%@",beacons);
//}
//
///**
// *  定位Beacon扫描结果事件回调，返回符合扫描参数的定位Beacon，定位Beacon包含坐标信息。此方法可用于辅助巡检，以及基于定位beacon的相关触发事件。
// *
// *  @param manager 定位引擎实例
// *  @param beacons 定位Beacon数组，[BRTPublicBeacon]
// */
//- (void)BRTLocationManager:(BRTLocationManager *)manager didRangedLocationBeacons:(NSArray *)beacons {
//    //显示扫描到的Beacon设备信息
//    [self.mapView removeAnnotations:self.mapView.annotations];
//    NSMutableArray *marray = [NSMutableArray array];
//    NSInteger i = 0;
//    for (BRTPublicBeacon *pb in beacons) {
//        if (pb.location.floor == self.mapView.currentFloor) {
//            MGLPointAnnotation *ann = [[MGLPointAnnotation alloc] init];
//            ann.coordinate = pb.location.coordinate;
//            ann.title = [pb.minor.stringValue stringByAppendingFormat:@",%d(%ld)",pb.rssi,++i];
//            [marray addObject:ann];
//        }
//    }
//    [self.mapView addAnnotations:marray];
//}
//
///**
// *  设备方向改变事件回调。处理方向箭头等功能。
// *
// *  @param manager    定位引擎实例
// *  @param mapHeading 新的方向结果
// */
//- (void)BRTLocationManager:(BRTLocationManager *)manager didUpdateMapHeading:(double)mapHeading {
//    NSLog(@"地图北偏角：%f",mapHeading);
//    [self.mapView processDeviceRotation:mapHeading];
//}
//@end
//
//
//
