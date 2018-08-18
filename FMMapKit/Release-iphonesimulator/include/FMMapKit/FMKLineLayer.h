//
//  FMKLineLayer.h
//  FMMapKit
//
//  Created by FengMap on 15/8/24.
//  Copyright (c) 2015年 FengMap. All rights reserved.
//

#import "FMKLayer.h"

@class FMKLineMarker;

/**
 *  地图线层标注层，地图自有图层，不可创建
 *	线标注物图层直接与地图根节点关联，不与楼层关联
 *  可通过地图map节点获取 FMKMap lineLayer
 */
@interface FMKLineLayer : FMKLayer

/**
 *  添加线标注物
 *
 *  @param lineMarker 地图线对象
 */
- (void)addMarker:(FMKLineMarker *)lineMarker;

/**
 添加三维线段标注物

 @param lineMarker 线标注物
 */
- (void)addThreeDimensionalLineMarker:(FMKLineMarker *)lineMarker;

/**
 *  删除线标注物
 *
 *  @param lineMarker 地图线对象
 */
- (void)removeMarker:(FMKLineMarker *)lineMarker;

/**
 *  删除所有线标注物
 */
- (void)removeAll;


@end
