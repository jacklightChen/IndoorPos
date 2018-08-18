//
//  FMKTextLayer.h
//  FMMapKit
//
//  Created by fengmap on 15/12/29.
//  Copyright © 2015年 FengMap. All rights reserved.
//

#import "FMKLayer.h"

@class FMKTextMarker;

/**
 自定义文本图层
 创建成功使用FMKMap addLayer方法添加自定义文本标注物图层
 获取方式 FMKMap getTextLayerByGroupID:
 */
@interface FMKTextLayer : FMKLayer

///文本图层所在楼层ID
@property (nonatomic,readonly) NSString * groupID;

/**
 *  初始化文本图层(在同一楼层下可创建多个文本图层)
 *
 *  @param groupID 文本图层所在楼层
 *
 *  @return 文本图层
 */
- (instancetype)initWithGroupID:(NSString *)groupID;

/**
 *  添加文本标注物
 *
 *  @param textMarker 文本标注物
 */
- (void)addMarker:(FMKTextMarker *)textMarker;

/**
 *  通过tag获取文本标注物
 *
 *  @param tag 文本标注物的tag，文本标注物的唯一标识
 *
 *  @return 对应tag的文本标注物
 */
- (FMKTextMarker *)textMarkerWithTag:(NSInteger)tag;

/**
 *  删除文本标注物
 *
 *  @param textMarker 文本标注物
 */
- (void)removeMarker:(FMKTextMarker *)textMarker;

/**
 *  删除该图层下的所有文本标注物
 */
- (void)removeAll;

@end
