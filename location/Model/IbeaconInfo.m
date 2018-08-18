////
////  IbeaconInfo.m
////  location
////
////  Created by 陈之豪 on 2018/7/27.
////  Copyright © 2018年 陈之豪. All rights reserved.
////
//
//#import "IbeaconInfo.h"
//
//@implementation IbeaconInfo
//
///*更新队列信息*/
//-(void)processInfo:(NSArray *)beacons{
//    for(CLBeacon *beacon in beacons){
//        int key=beacon.major.intValue*100000+beacon.minor.intValue;
//        NSString *str=[NSString stringWithFormat:@"%d",key];
//        NSNumber *num=[_map objectForKey:str];
//        if(num==nil){
//            for(int i=0;i<20;i++){
//                if([_judge[i] isEqual:@(1)]){
//                    [_map setValue:@(i) forKey:str];
//                    _judge[i]=@(0);
//                    break;
//                }
//                
//            }
//        }
//        NSNumber* rssi=[NSNumber numberWithInt:beacon.rssi];
//        NSNumber* index=[_map objectForKey:str];
//        NSUInteger length=[_array[index.intValue] count];
//        /*每一个队列的长度限定为5s*/
//        if(length==5){
//            [_array[index.intValue] removeObjectAtIndex:0];
//        }
//        [_array[index.intValue] addObject:rssi];
//    }
//}
//
///*通过队列获得每个ibeacon的坐标的均值rssi*/
//-(NSMutableArray *)getBeaconDetail{
//    NSMutableArray * result=[NSMutableArray array];
//    NSMutableDictionary * dic=[NSMutableDictionary dictionaryWithDictionary:_map];
//    
//    for(NSString *str in dic){
//        int index=[[_map objectForKey:str] intValue];
//        int sum=0;
//        for(int i=0;i<[_array[index] count];i++){
//            sum+=[[_array[index] objectAtIndex:i] intValue];
//        }
//        if(sum==0){
//            [_map removeObjectForKey:str];
//            _judge[index]=@(1);
//            [_array[index] removeAllObjects];
//        }else{
//            Coordination *c=[[Coordination alloc]init];
//            NSUInteger count=[_array[index] count];
//            sum=(int)sum*1.0/count;
//            if([str isEqualToString:@"0"]){
//                c.x=0;
//                c.y=1800;
//                continue;
//            }
//            NSNumber* temp=@(123*100000+123);
//            if([str isEqualToString:temp.stringValue]){
//                c.x=1800;
//                c.y=0;
//            }
//            temp=@(10094*100000+13315);
//            if([str isEqualToString:temp.stringValue]){
//                c.x=1800;
//                c.y=1800;
//            }
//            temp=@(10094*100000+13431);
//            if([str isEqualToString:temp.stringValue]){
//                c.x=0;
//                c.y=1800;
//            }
//            
//            c.dis=[self getDisByRSSI:sum:80 :3.0];
//            [result addObject:c];
//        }
//    }
//    return result;
//}
//
////d = 10^((abs(RSSI) - A) / (10 * n))
////A:发射端和接收端相隔1米时的信号强度 n:2.0?
//-(double)getDisByRSSI:(double) RSSI :(double)A :(double)n
//{
//    double IRSSI=abs(RSSI);
//    return pow(10, (IRSSI-A)/(10*n))*1000;
//}
//
///*初始化信息*/
//-(instancetype)init{
//    self = [super init];
//    if (self) {
//        _judge=[[NSMutableArray alloc]init];
//        _map=[[NSMutableDictionary alloc]init];
//        _array=[[NSMutableArray alloc]init];
//        for(int i=0;i<20;i++){
//            [_judge addObject:@(1)];
//        }
//       
//        /*初始化队列滤波的容器 每个容器限制为5求均值*/
//        for(int i=0;i<20;i++){
//            [_array addObject:[[NSMutableArray alloc]init]];
//        }
//    }
//    return self;
//}
//@end
