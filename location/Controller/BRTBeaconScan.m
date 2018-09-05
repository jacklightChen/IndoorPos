//
//  BRTBeaconScan.m
//  location
//
//  Created by 陈之豪 on 2018/8/1.
//  Copyright © 2018年 陈之豪. All rights reserved.
//

#import "BRTBeaconScan.h"
#import "location-Swift.h"

@implementation BRTBeaconScan

/* 需要扫描一系列ibeacon的UUID
 * 智石科技sdk可传一系列ibaecon的UUID数组
 */
#define MY_UUID @"E2C56DB5-DFFB-48D2-B060-d0f5a71096e0"
#define MY_REGION_IDENTIFIER @"cmb"

- (void)start:(MapViewController *)map {
    [self initProperty];
    _sumTime=0;
    [self startBeaconRanging];
    _map=map;
}

-(void)startBeaconRanging{
    [BRTBeaconSDK setInvalidTime:1];
    [BRTBeaconSDK setScanResponseTime:1];
    /* 每隔一秒扫描得到BRTBeacon的回调函数*/
    [BRTBeaconSDK scanBleServices:nil onCompletion:^(NSArray *beacons, NSError *error){
//        for(BRTBeacon * beacon in beacons){
//            NSLog(@"%@ %@ %d %f",beacon.major,beacon.minor,beacon.rssi,beacon.distance.floatValue);
//        }
        [self processBeaconInfo:beacons];
    }];
}

/* 解析接收到的ibeacon信息 并过滤有效值后
 * 因为人是走的 这边略微做了一点处理
 * 然后把定位得到的坐标在地图中显示
 **/
-(NSMutableArray *)processBeaconInfo:(NSArray *)beacons{
    NSMutableArray * array=[NSMutableArray array];
    for(BRTBeacon * beacon in beacons){
        Coordination *temp=[[Coordination alloc]init];
        NSString *major=[beacon.major stringValue];
        NSString *minor=[beacon.minor stringValue];
        NSString *string=[[major stringByAppendingString:@"&"] stringByAppendingString:minor];
        Coordination *target=[_dic objectForKey:string];
        if(target!=nil){
            temp.x=target.x;
            temp.y=target.y;
            int identifier=target.identifier;
            NSUInteger length=[[_distanceInfo objectAtIndex:identifier] count];
            if(length>=5){
                [[_distanceInfo objectAtIndex:identifier] removeObjectAtIndex:0];
            }
            NSNumber *dis=[NSNumber numberWithFloat:beacon.distance.floatValue];
            [[_distanceInfo objectAtIndex:identifier] addObject:dis];
            temp.dis=[self getAveDis:[_distanceInfo objectAtIndex:identifier]];
            [array addObject:temp];
        }
    }
    /* 大于三点进行定位算法*/
    if(array.count>=3){
        PositionUtilSwift *pos=[[PositionUtilSwift alloc]init];
         Coordination *t=[pos calPositionWithInfos:array];
        /*fengmap的地图偏移值*/
        t.x+=13544230.0271;
        t.y+=3665146.9586;
        curx=t.x;
        cury=t.y;
        [_map showPointWithX:t.x andY:t.y];
    }
    return array;
}
-(float)getAveDis:(NSMutableArray *)array{
    double sum=0;
    if(array.count<=2){
        for(int i=0;i<array.count;i++){
            NSNumber * temp=[array objectAtIndex:i];
            sum+=temp.floatValue;
        }
        sum/=array.count;
    }else{
        NSArray* sorted=[array sortedArrayUsingSelector:@selector(compare:)];
        for(int i=1;i<sorted.count-1;i++){
            NSNumber * temp=[sorted objectAtIndex:i];
            sum+=temp.floatValue;
        }
        sum/=(sorted.count-2);
    }
    return sum;
}
/* 设置放置的各个ibeacon的位置*/
-(void)initProperty{
    _dic=[NSMutableDictionary dictionary];
    [_dic setValue:[[Coordination alloc]initWithX:0.940 andY:-1.400 andId:0] forKey:@"10094&13315"];
    [_dic setValue:[[Coordination alloc]initWithX:0.940 andY:-2.600 andId:1] forKey:@"10094&13431"];
    [_dic setValue:[[Coordination alloc]initWithX:1.440 andY:-2.000 andId:2] forKey:@"123&123"];
    _distanceInfo=[NSMutableArray array];
    for(int i=0;i<25;i++){
        [_distanceInfo addObject:[NSMutableArray array]];
    }
}
 
+ (double)getCurX{
    return curx;
}
+ (double)getCurY{
    return cury;
}
@end
