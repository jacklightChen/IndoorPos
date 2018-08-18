//
//  BRTRouteResult.h
//  BRTMapProject
//
//  Created by thomasho on 2018/4/18.
//  Copyright © 2018年 thomasho. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "BRTRoutePart.h"
#import <BRTMapData/BRTLocalPoint.h>

/**
 *  路径规划结果
 */
@interface BRTRouteResult : NSObject


/**
 * 本路径总长度
 */
@property (nonatomic,readonly) double length;

/**
 *  路径结果的所有路径段
 */
@property (nonatomic, readonly) NSArray<BRTRoutePart *> *allRoutePartArray;

/**
 *  路径结果按楼层分类的映射关系
 */
@property (nonatomic, readonly) NSDictionary<NSNumber *,BRTRoutePart *> *allFloorRoutePartDict;

/**
 *  下一路段
 */
@property (nonatomic, strong) BRTRouteResult *nextResult;

/**
 *  当前段的前一段
 */
@property (nonatomic, strong) BRTRouteResult *previousResult;

/**
 *  判断当前段是否为跨层导航的第一段
 *
 *  @return 是否为第一段
 */
- (BOOL)isFirstRoute;

/**
 *  判断当前段是否为跨层导航的最后一段
 *
 *  @return 是否为最后一段
 */
- (BOOL)isLastRoute;

/**
 *  判断当前段是否为中间段
 *
 *  @return 是否为中间段
 */
- (BOOL)isMiddleRoute;

/**
 *  路径结果的类实例化方法，一般不需要直接调用，由导航管理类调用生成
 *
 *  @param routePartArray 路径段数组
 *
 *  @return 路径结果实例
 */
+ (BRTRouteResult *)routeResultWithRouteParts:(NSArray *)routePartArray;

/**
 *  判断位置位置点是否偏离导航线
 *
 *  @param point    目标位置点
 *  @param distance 判断是否偏离的阈值
 *
 *  @return 是否偏离导航线
 */
- (BOOL)isDeviatingFromRoute:(BRTLocalPoint *)point WithThrehold:(double)distance;

/**
 * 获取路径上最近的点
 *
 * 如果本层无路径数据，仅返回传入点
 *
 * @param lp 传入点
 * @return 路径上最近的点
 */
- (BRTLocalPoint *)getNearPointOnRoute:(BRTLocalPoint *)lp;

/**
 * 获取距终点长度
 *
 * 如果lp不在路径上，会额外增加距离路径的长度；
 * 如果lp非路径楼层数据，返回路径全长；
 *
 * @param lp 传入点
 * @return 距终点全长
 */
- (double)distanceToRouteEnd:(BRTLocalPoint *)lp;

/**
 *  获取距离目标位置点最近的路径段
 *
 *  @param location 目标位置点
 *
 *  @return 最近的路径段
 */
- (BRTRoutePart *)getNearestRoutePart:(BRTLocalPoint *)location;

/**
 *  获取目标楼层的所有路径段
 *
 *  @param floor 目标楼层
 *
 *  @return 路径段数组
 */
- (NSArray *)getRoutePartsOnFloor:(int)floor;

/**
 *  从路径段数组中获取特定索引的路径段
 *
 *  @param index 目标段索引
 *
 *  @return 目标段
 */
- (BRTRoutePart *)getRoutePart:(int)index;

/**
 *  获取一组折线的子折线
 *
 *  @param originalLine 原折线
 *  @param start        子折线起点
 *  @param end          子折线终点
 *
 *  @return 目标子折线
 */
+ (MGLPolyline *)getSubPolyline:(MGLPolyline *)originalLine WithStart:(CLLocationCoordinate2D)start End:(CLLocationCoordinate2D)end;
@end
