//
//  FMKFacilityLayer.h
//  FMMapKit
//
//  Created by FengMap on 15/6/24.
//  Copyright (c) 2015年 FengMap. All rights reserved.
//

#import "FMKLayer.h"

@class FMKFacility;

/**
 地图公共设施层，该层暂不支持用户创建.

 获取方式 FMKMap  getFacilityLayerByGroupID:
 */
@interface FMKFacilityLayer : FMKLayer

/**
 *  初始化公共设施层 不支持用户创建.
 *
 *  @param groupID 楼层ID.
 *
 *  @return 公共设施层对象.
 */
- (instancetype)initWithGroupID:(NSString *)groupID;

/**
 *  所在的楼层ID
 */
@property (readonly) NSString* groupID;

/**
 *  根据设施类型返回
 *
 *  @param type 公共设置类型 如卫生间type为 @"200002"
 *
 *  @return 查询得到的公共设施结果 数组中为FMKFacility类型对象
 */
- (NSArray *)queryFacilityByType:(NSString *)type;

@end
