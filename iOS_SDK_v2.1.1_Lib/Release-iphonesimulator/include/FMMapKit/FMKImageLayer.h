//
//  FMKImageMarkerLayer.h
//  FMMapKit
//
//  Created by FengMap on 15/6/2.
//  Copyright (c) 2015年 FengMap. All rights reserved.
//

#import "FMKLayer.h"

@class FMKImageMarker;

/**
 自定义图层
 地图图片标注层节点，用于添加地图的图片标注
 同一楼层可添加多个图片层 使用"addLayer:"
 获取方式 FMKMap getImageLayerByGroupID:
 */
@interface FMKImageLayer : FMKLayer

/**
 *  初始化图片标注物图层，由用户创建
 *
 *  @param groupID 楼层ID
 *
 *  @return 图片层对象
 */
- (instancetype)initWithGroupID:(NSString *)groupID;

///图层所在楼层的ID
@property (nonatomic,readonly) NSString* groupID;

/**
 *  添加图片标注物
 *
 *  @param imageMarker 图片标注对象
 */
- (void)addMarker:(FMKImageMarker *)imageMarker;

/**
 *  根据tag获取图片标注物
 *
 *  @param tag 图片唯一标识，该标识由用户自定义
 *
 *  @return 图片标注对象
 */
- (FMKImageMarker *)imageMarkerWithTag:(NSInteger)tag;

/**
 *  删除指定tag的标注物
 *
 *  @param imageMarker 图片标注对象
 */
- (void)removeMarker:(FMKImageMarker *)imageMarker;

/**
 * 移除所有标注物
 */
- (void)removeAll;

@end

