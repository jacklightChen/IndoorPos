//
//  FMKPolygonLayer.h
//  FMMapKit
//
//  Created by fengmap on 16/4/15.
//  Copyright © 2016年 Fengmap. All rights reserved.
//

#import "FMKLayer.h"

@class FMKPolygonMarker;

/**
 自定义面标注物图层
 由用户自定义创建
 创建成功使用FMKMap addLayer:添加到地图
 获取方式 FMKMap getPolygonLayerByGroupID:
 */
@interface FMKPolygonLayer : FMKLayer

/**
 *  面标注物图层
 *
 *  @param groupID 楼层ID
 *
 *  @return 标注面图层对象
 */
- (instancetype)initWithGroupID:(NSString *)groupID;

/**
 *  面标注物图层所在楼层ID
 */
@property (nonatomic, readonly)NSString * groupID;

/**
 图层透明度
 该参数会改变添加到该图层上的所有的面标注物透明度
 */
@property (nonatomic, assign) CGFloat alpha;

/**
 *  添加面标注物
 *
 *  @param polygonMarker 面标注物
 *
 *  @return 所添加标注物下标 返回值为-1表示添加失败
 */
- (int)addMarker:(FMKPolygonMarker *)polygonMarker;

/**
 *  删除面标注物
 *
 *  @param polygonMarker 面标注物
 */
- (void)removeMarker:(FMKPolygonMarker *)polygonMarker;

/**
 *  删除所有的覆盖面标注物
 */
- (void)removeAll;

@end
