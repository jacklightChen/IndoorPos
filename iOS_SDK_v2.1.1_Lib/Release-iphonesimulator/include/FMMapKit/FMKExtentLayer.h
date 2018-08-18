//
//  FMKExtentLayer.h
//  FMMapKit
//
//  Created by fengmap on 15/12/24.
//  Copyright © 2015年 Fengmap. All rights reserved.
//

#import "FMKLayer.h"

/**
 底面图层 位于模型层之下 自有图层，不可创建
 获取方式 FMKMap   - getExtentLayerByGroupID:
 */
@interface FMKExtentLayer : FMKLayer
/**
 *  初始化底面图层
 *	地图自有图层，不可创建
 *
 *  @param groupID 所在楼层ID
 *
 *  @return 底图层对象
 */
- (instancetype)initWithGroupID:(NSString *)groupID;

/**
 *  所在楼层ID
 */
@property(readonly) NSString * groupID;

@end
