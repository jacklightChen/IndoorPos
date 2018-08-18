//
//  FMKLocationLayer.h
//  FMMapKit
//
//  Created by FengMap on 15/6/8.
//  Copyright (c) 2015年 FengMap. All rights reserved.
//

#import "FMKLayer.h"

@class FMKLocationMarker;

/**
 *  地图定位标注层，地图自有图层.
 *
 *  定位层暂不支持创建，可通过地图map节点获取.
 *
 *  定位标注可添加多个.
 *	获取方式 FMKMap locationLayer
 *
 */
@interface FMKLocationLayer : FMKLayer

/**
 *  添加定位标注
 *
 *  @param locationMarker 定位标注点
 */
- (void)addMarker:(FMKLocationMarker *)locationMarker;

/**
 *  删除指定定位标注
 *
 *  @param locationMarker 定位标注点
 */
- (void)removeMarker:(FMKLocationMarker *)locationMarker;

/**
 *  删除所有定位标注
 */
- (void)removeAll;

@end
