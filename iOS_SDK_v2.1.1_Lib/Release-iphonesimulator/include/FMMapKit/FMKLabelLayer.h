//
//  FMKLabelLayer.h
//  FMMapKit
//
//  Created by fengmap on 16/3/7.
//  Copyright © 2016年 Fengmap. All rights reserved.
//

#import "FMKLayer.h"
@class FMKLabel;

/**
 地图文本标签图层
 地图自有图层，不支持用户创建
 获取方式 FMKMap getLabelLayerByGroupID:
 */
@interface FMKLabelLayer : FMKLayer
/**
 *  初始化label层
 *
 *  @param groupID label所在楼层
 *
 *  @return label管理层对象
 */
- (instancetype)initWithGroupID:(NSString *)groupID;

///文本标签图层所在楼层ID
@property(readonly)NSString * groupID;

/**
 *  根据文本内容获取文本对象
 *
 *  @param text 文本内容
 *
 *  @return 文本对象
 */
- (FMKLabel *)queryLabelByText:(NSString *)text;

@end
