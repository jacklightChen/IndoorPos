//
//  BRTOfflineRouteManager.h
//  MapProject
//
//  Created by thomasho on 18/5/11.
//  Copyright © 2018年 thomasho. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "BRTRouteResult.h"
#import <BRTMapData/BRTMapData.h>

@class BRTOfflineRouteManager;

/**
 *  离线路径管理代理协议
 */
@protocol BRTOfflineRouteManagerDelegate <NSObject>

@optional
/**
 *  解决路径规划返回方法
 *
 *  @param routeManager 离线路径管理实例
 *  @param rs           路径规划结果
 */
- (void)offlineRouteManager:(BRTOfflineRouteManager *)routeManager didSolveRouteWithResult:(BRTRouteResult *)rs;

/**
 *  路径规划失败回调方法
 *
 *  @param routeManager 离线路径管理实例
 *  @param error        错误信息
 */
- (void)offlineRouteManager:(BRTOfflineRouteManager *)routeManager didFailSolveRouteWithError:(NSError *)error;

@end


/**
 *  离线路径管理类
 */
@interface BRTOfflineRouteManager : NSObject

/**
 *  路径规划起点
 */
@property (nonatomic, strong, readonly) BRTLocalPoint *startPoint;

/**
 *  路径规划终点
 */
@property (nonatomic, strong, readonly) BRTLocalPoint *endPoint;


/**
 *  离线路径管理代理
 */
@property (nonatomic, weak) id<BRTOfflineRouteManagerDelegate> delegate;

/**
 *  离线路径管理类的静态实例化方法
 *
 *  @param building     目标建筑
 *  @param mapInfoArray 目标建筑的所有楼层信息
 *
 *  @return 离线路径管理类实例
 */
+ (BRTOfflineRouteManager *)routeManagerWithBuilding:(BRTBuilding *)building MapInfos:(NSArray *)mapInfoArray;


/**
 *  请求路径规划，在代理方法获取规划结果
 *
 *  @param start 路径规划起点
 *  @param end   路径规划终点
 */
- (void)requestRouteWithStart:(BRTLocalPoint *)start End:(BRTLocalPoint *)end;


/**
 计算距离路网最近的点

 @param point 目标点
 @return 路网上的点,未成功直接返回原点
 */
- (BRTLocalPoint *)nearestPointOnRoute:(BRTLocalPoint *)point;

/**
 路网

 @return 整条路线
 */
- (MGLMultiPolyline *)route;


/**
 设置禁止通行点

 @param point 路径禁行拐点
 */
- (BOOL)addForbiddenPoint:(BRTLocalPoint *)point;


/**
 移除所有禁止通行点
 */
- (void)removeForbiddenPoints;

@end
