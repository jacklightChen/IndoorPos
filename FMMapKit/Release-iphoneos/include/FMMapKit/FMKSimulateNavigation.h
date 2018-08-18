//
//  FMKSimulateNavigation.h
//  FMMapKit
//
//  Created by smallLabel on 2017/10/23.
//  Copyright © 2017年 Fengmap. All rights reserved.
//

#import "FMKNavigation.h"

/**
 模拟导航类
 该类可以演示路径规划后的模拟导航效果，导航过程中实时计算剩余路长、路线角度、实时坐标、路段信息等信息
 */
@interface FMKSimulateNavigation : FMKNavigation

/**
 模拟导航方法
 必须在路径规划及画线后才能调用该方法

 @param speed 模拟导航的速度值，速度范围 0.4~5.0 m/s
 */
- (void)simulateWithSpeed:(float)speed;

/**
 停止模拟导航
 该方法会清空所有导航过程中产生的中间值
 */
- (void)stop;

/**
 暂停模拟导航过程
 调用该方法后若要继续开始导航必须调用恢复方法
 */
- (void)pause;

/**
 从暂停状态到恢复模拟导航过程
 */
- (void)resume;

@end
