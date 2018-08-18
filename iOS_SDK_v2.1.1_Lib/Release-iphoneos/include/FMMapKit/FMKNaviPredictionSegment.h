//
//  FMKNaviPredictionSegment.h
//  FMMapKit
//
//  Created by FengMap on 16/5/9.
//  Copyright © 2016年 FengMap. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "FMKGeometry.h"

@class FMKModelSearchResult,FMKFacilitySearchResult;

/**
 路径规划结果文字导航数据，该结果通过路径规划结果FMKNaviResult得到
 */
@interface FMKNaviPredictionSegment : NSObject

///路段起点
@property (nonatomic, assign) FMKGeoCoord startCoord;

///路段终点
@property (nonatomic, assign) FMKGeoCoord endCoord;

///该路段距离
@property (nonatomic, assign) float distance;

///该路段起点绝对方向 东南西北
@property (nonatomic, copy, nonnull) NSString * startDirection;

///该路段终点相对方向，相对下一个路段的方向 前后左右
@property (nonatomic, copy, nullable) NSString * endDirection;

///距离线段终点最近的模型
@property (nonatomic, strong, nullable) FMKModelSearchResult * nearestModel;

///距离线段终点最近的直梯 电梯或楼梯
@property (nonatomic, strong, nullable) FMKFacilitySearchResult * nearestFacility;

@end
