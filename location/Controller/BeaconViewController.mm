/*
 *  废弃代码 使用系统库扫描rssi
 *
 */
////
////  BeaconViewController.m
////  location
////
////  Created by 陈之豪 on 2018/7/24.
////  Copyright © 2018年 陈之豪. All rights reserved.
////
//
//#import "BeaconViewController.h"
//#import <iostream>
//#import <Eigen/Dense>
//
//using namespace std;
//using namespace Eigen;
//
//#define MY_UUID @"E2C56DB5-DFFB-48D2-B060-d0f5a71096e0"
//#define MY_REGION_IDENTIFIER @"cmb"
//
//@interface BeaconViewController ()
//
//@end
//
//@implementation BeaconViewController
//
//- (void)viewDidLoad {
//    [super viewDidLoad];
//    [self turnOnBeacon];
//}
//
//- (void)didReceiveMemoryWarning {
//    [super didReceiveMemoryWarning];
//    // Dispose of any resources that can be recreated.
//}
//
///*先挤在一起写吧*/
//- (void)initProperty{
//    info=[[IbeaconInfo alloc]init];
//}
//
//
//#pragma mark - Beacons Methods
//- (void) turnOnBeacon{
//    [self initLocationManager];
//    [self initProperty];
//    [self initDetectedBeaconsList];
//    [self initBeaconRegion];
//    [self startBeaconRanging];
//}
//
//#pragma mark Init Beacons
//- (void) initLocationManager{
//    if (!_locationManager) {
//        _locationManager = [[CLLocationManager alloc] init];
//        _locationManager.delegate = self;
//        [self checkLocationAccessForRanging];
//    }
//}
//
//- (void) initDetectedBeaconsList{
//    if (!_detectedBeacons) {
//        _detectedBeacons = [[NSArray alloc] init];
//    }
//}
//
//- (void) initBeaconRegion{
//    if (_region)
//        return;
//
//    NSUUID *proximityUUID = [[NSUUID alloc] initWithUUIDString:MY_UUID];
//    _region = [[CLBeaconRegion alloc] initWithProximityUUID:proximityUUID identifier:MY_REGION_IDENTIFIER];
//    _region.notifyEntryStateOnDisplay = YES;
//}
//
//#pragma mark Beacons Ranging
//
//- (void) startBeaconRanging{
//    if (!_locationManager || !_region) {
//        return;
//    }
//    if (_locationManager.rangedRegions.count > 0) {
//        NSLog(@"Didn't turn on ranging: Ranging already on.");
//        return;
//    }
//    [_locationManager startRangingBeaconsInRegion:_region];
//}
//
//- (void) stopBeaconRanging{
//    if (!_locationManager || !_region) {
//        return;
//    }
//    [_locationManager stopRangingBeaconsInRegion:_region];
//}
//
////Location manager delegate method
//- (void)locationManager:(CLLocationManager *)manager didRangeBeacons:(NSArray *)beacons inRegion:(CLBeaconRegion *)region{
//
//    //记录时间
//    _sumTime++;
//
//    if (beacons.count == 0) {
//        NSLog(@"No beacons found nearby.");
//    } else {
//        _detectedBeacons = beacons;
////        NSLog(@"beacons count:%lu", beacons.count);
//        [info processInfo:beacons];
////        for(CLBeacon *beacon in beacons){
////            NSLog(@"%@ %f",[self detailsStringForBeacon:beacon],[info getDisByRSSI:beacon.rssi :80 :3]);
////        }
//    }
//    if(_sumTime%3==0){
//        NSMutableArray *array=[info getBeaconDetail];
//        if(array.count>=3){
//            Coordination *person=[self getRealCoordination:array];
//            NSLog(@"%f %f %d",person.x,person.y,_sumTime/3);
//        }
//    }
//}
//
////计算获得人所在的真实位置
//-(Coordination *)getRealCoordination:(NSMutableArray *)infos{
//    if(infos.count<=2)return nil;
////    for(int i=0;i<infos.count;i++){
////        Coordination *temp=[infos objectAtIndex:i];
////        NSLog(@"%f %f 距离:%f",temp.x,temp.y,temp.dis);
////    }
//    NSUInteger n=infos.count;
//    MatrixXd left(n,2);
//    MatrixXd right(n,1);
//    Coordination *last=[infos objectAtIndex:n-1];
//    /*build matrix a*/
//    for(int i=0;i<n-1;i++){
//        Coordination *cur=[infos objectAtIndex:i];
//        double value1=2*(cur.x - last.x);
//        left(i,0)=value1;
//        double value2=2*(cur.y - last.y);
//        left(i,1)=value2;
//    }
//    /*build matrix b*/
//    for(int i=0;i<n-1;i++){
//        Coordination *cur=[infos objectAtIndex: i];
//        double value=[self pow2:cur.x]-[self pow2:last.x]
//        +[self pow2:cur.y]-[self pow2:last.y]
//        +[self pow2:last.dis]-[self pow2:cur.dis];
//        right(i,0)=value;
//    }
//
//    /*a的转置*/
//    MatrixXd leftT=left.transpose();
//    MatrixXd temp=leftT*left;
//    /*按公式计算
//     * (A^T*A)^(-1)*A^T*B=X*/
//    MatrixXd tempInv=temp.inverse();
//    MatrixXd temp2=tempInv*leftT;
//
//    /*中间结果乘以最后的right矩阵*/
//    MatrixXd resultMatrix=temp2*right;
//    Coordination * target =[[Coordination alloc]initWithX:resultMatrix(0,0) andY:resultMatrix(1,0) andDis:0];
//    return target;
//}
//
//
//-(double)pow2:(double) target
//{
//    return target*target;
//}
//
//
//
//#pragma mark Process Beacon Information
////将beacon的信息转换为NSString并返回
//- (NSString *)detailsStringForBeacon:(CLBeacon *)beacon
//{
//
//    NSString *format = @"%@ • %@  • %f • %li";
//    return [NSString stringWithFormat:format, beacon.major, beacon.minor, beacon.accuracy, beacon.rssi];
//}
//
//- (void)checkLocationAccessForRanging {
//    if ([_locationManager respondsToSelector:@selector(requestWhenInUseAuthorization)]) {
//        [_locationManager requestWhenInUseAuthorization];
//    }
//}
//@end
