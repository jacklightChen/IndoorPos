//
//  FMKActualNavigation.h
//  FMMapKit
//
//  Created by smallLabel on 2017/10/25.
//  Copyright © 2017年 Fengmap. All rights reserved.
//

#import "FMKNavigation.h"

/**
 真实导航功能类
 该类支持在接入真实定位系统后，对转化到fengmap坐标的定位进行导航数据处理
 */
@interface FMKActualNavigation : FMKNavigation

/**
 当前定位点经过分析后的位置
 */
@property (nonatomic, readonly) FMKGeoCoord position;

/**
 当前定位角度朝向
 */
@property (nonatomic, readonly) CGFloat angle;

/**
 对定位结果进行分析处理，分析结果参见回调 navigation:walking:
 必须在路径规划画线完成后才能调用该方法
 
 @param position 当前定位位置
 @param angle 当前定位角度
 */
- (BOOL)locate:(FMKGeoCoord)position angle:(CGFloat)angle;

/**
 设置定位点距离终点的导航完成距离，因定位存在精度误差，所以定位点可能不会完全与终点重合，因此剩余路长的距离可能不会出现0，因此需要设置导航完成剩余路长阈值

 @param completeDistance 导航完成剩余路长阈值，默认为5，单位为米
 */
- (void)setCompleteDistance:(CGFloat)completeDistance;

@end
