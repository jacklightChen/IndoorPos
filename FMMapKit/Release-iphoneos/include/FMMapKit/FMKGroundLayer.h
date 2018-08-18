//
//  FMKGroundLayer.h
//  FMMapKit
//
//  Created by fengmap on 16/4/9.
//  Copyright © 2016年 Fengmap. All rights reserved.
//

#import "FMKLayer.h"

/**
 地面图层
 地图自有图层，不支持用户创建
 */
@interface FMKGroundLayer : FMKLayer

/**
 *  内部初始化方法  不支持外部创建
 *
 *  @param groupID  楼层ID
 *
 *  @return FMKGroundLayer层管理对象
 */
- (instancetype)initWithGroupID:(NSString *)groupID;

/**
 *  groundLayer所在的楼层ID
 */
@property (nonatomic,readonly)NSString * groupID;

@end
