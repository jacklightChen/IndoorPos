//
//  BRTRoutPart.h
//  BRTMapProject
//
//  Created by thomasho on 2018/4/18.
//  Copyright © 2018年 thomasho. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <BRTMapData/BRTLocalPoint.h>
#import <Mapbox/Mapbox.h>
#import "BRTDirectionalHint.h"

@interface BRTRoutePart : NSObject

/**
 *  路径导航段的初始化方法，一般不需要直接调用，由导航管理类调用生成
 *
 *  @param route   导航线
 *  @param floor 导航线所在楼层
 *
 *  @return 路径导航类实例
 */
- (id)initWithRouteLine:(MGLPolyline *)route Floor:(int)floor;

/**
 路段索引
 */
@property (nonatomic, assign) int partIndex;

/**
 *  当前段的几何数据
 */
@property (nonatomic, strong, readonly) MGLPolyline *route;

/**
 *  当前段的米坐标数据
 */
@property (nonatomic, strong) NSArray<BRTLocalPoint *> *points;

/**
 *  当前段的地图信息
 */
@property (nonatomic, assign, readonly) int floor;

/**
 *  当前段的前一段
 */
@property (nonatomic, weak) BRTRoutePart *previousPart;

/**
 *  当前段的下一段
 */
@property (nonatomic, weak) BRTRoutePart *nextPart;

/**
 *  判断当前段是否为跨层导航的第一段
 *
 *  @return 是否为第一段
 */
- (BOOL)isFirstPart;

/**
 *  判断当前段是否为跨层导航的最后一段
 *
 *  @return 是否为最后一段
 */
- (BOOL)isLastPart;

/**
 *  判断当前段是否为中间段
 *
 *  @return 是否为中间段
 */
- (BOOL)isMiddlePart;

/**
 *  返回当前段的第一个点
 *
 *  @return 第一个点
 */
- (BRTLocalPoint *)getFirstPoint;

/**
 *  返回当前段的最后一个点
 *
 *  @return 最后一个点
 */
- (BRTLocalPoint *)getLastPoint;



/**
 *  获取目标路径段的导航提示(默认忽略距离<6米，转角<15度的线段)
 *
 *  @return 目标路径段的导航提示
 */
- (NSArray *)getRouteDirectionalHints;


/**
 获取目标路径段按自定义距离、角度忽略的导航提示
 
 @param distanceThrehold 忽略距离
 @param angleThrehold 忽略角度
 @return 目标路径段的导航提示
 */
- (NSArray *)getRouteDirectionalHintsIgnoreDistance:(double)distanceThrehold angle:(double)angleThrehold;

/**
 *  从一组导航提示中获取与目标位置点对应的导航提示
 *
 *  @param location   目标位置点
 *  @param directions 目标导航提示数组
 *
 *  @return 与目标位置点对应的导航提示
 */
- (BRTDirectionalHint *)getDirectionHintForLocation:(BRTLocalPoint *)location FromHints:(NSArray *)directions;

@end
