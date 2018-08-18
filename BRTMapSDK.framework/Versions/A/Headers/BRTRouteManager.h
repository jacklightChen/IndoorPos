//
//  BRTRouteManager.h
//  BRTMapProject
//
//  Created by thomasho on 2018/4/18.
//  Copyright © 2018年 thomasho. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "BRTRouteResult.h"
#import <Mapbox/Mapbox.h>

#import <BRTMapData/BRTBuilding.h>
#import <BRTMapData/BRTLocalPoint.h>

@class BRTRouteManager;
@protocol BRTRouteManagerDelegate
/**
 *  解决路径规划返回方法
 *
 *  @param routeManager 离线路径管理实例
 *  @param rs           路径规划结果
 */
- (void)routeManager:(BRTRouteManager *)routeManager didSolveRouteWithResult:(BRTRouteResult *)rs;

/**
 *  路径规划失败回调方法
 *
 *  @param routeManager 离线路径管理实例
 *  @param error        错误信息
 */
- (void)routeManager:(BRTRouteManager *)routeManager didFailSolveRouteWithError:(NSError *)error;

@end

@interface BRTRouteManager : NSObject

/**
 *  路径规划起点
 */
@property (nonatomic, strong) BRTLocalPoint *startPoint;

/**
 *  路径规划终点
 */
@property (nonatomic, strong) BRTLocalPoint *endPoint;


/**
 *  离线路径管理代理
 */
@property (nonatomic, weak) id<BRTRouteManagerDelegate> delegate;

/**
 *  离线路径管理类的静态实例化方法
 *
 *  @param building     目标建筑
 *  @param token        目标建筑token
 *
 *  @return 离线路径管理类实例
 */
+ (BRTRouteManager *)routeManagerWithBuilding:(BRTBuilding *)building token:(NSString *)token;

/**
 *  离线路径管理类的静态实例化方法
 *
 *  @param building     目标建筑
 *  @param appkey        目标建筑token
 *
 *  @return 离线路径管理类实例
 */
+ (BRTRouteManager *)routeManagerWithBuilding:(BRTBuilding *)building appkey:(NSString *)appkey;


/**
 *  请求路径规划，在代理方法获取规划结果
 *
 *  @param start 路径规划起点
 *  @param end   路径规划终点
 */
- (void)requestRouteWithStart:(BRTLocalPoint *)start end:(BRTLocalPoint *)end;


/**
 请求路径规划，在代理方法获取规划结果

 @param start 起点
 @param end 终点
 @param stops 途径点
 @param sort 是否途径点重排序
 @param vehicle 是否车行规划
 @param cids 禁行设施分类
 */
- (void)requestRouteWithStart:(BRTLocalPoint *)start end:(BRTLocalPoint *)end stops:(NSArray<BRTLocalPoint *> *)stops sortStop:(BOOL)sort vehicle:(BOOL)vehicle ignore:(NSArray<NSString *> *)cids;

@end
