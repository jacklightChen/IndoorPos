//
//  BRTBeaconScan.h
//  location
//
//  Created by 陈之豪 on 2018/8/1.
//  Copyright © 2018年 陈之豪. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "Coordination.h"
#import "LocationUtil.h"
#import "BRTBeaconSDK.h"
#import "MapViewController.h"

/* 提供给map显示计算出测量位置的坐标*/
static double curx;
static double cury;

@interface BRTBeaconScan : NSObject
/* 保存每个beacon的绝对坐标*/
@property(strong,nonatomic)NSMutableDictionary *dic;
//@property(strong,nonatomic)
/* 每一个beacon的距离队列 为了过滤最低和最高值的波动 再求平均值*/
@property(strong,nonatomic)NSMutableArray *distanceInfo;
@property(assign,nonatomic)int sumTime;

/* 向地图传参*/
@property(strong,nonatomic) MapViewController *map;
- (void)start:(MapViewController *)map;
+ (double)getCurX;
+ (double)getCurY;
@end
