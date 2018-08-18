//
//  FMKModelLayer.h
//  FMMapKit
//
//  Created by FengMap on 15/8/18.
//  Copyright (c) 2015年 FengMap. All rights reserved.
//

#import "FMKLayer.h"

@class FMKModel;

/**
 地图模型层，用于标注地图楼层上的模型层，地图自有图层
 
 每个楼层只有一个模型层
 
 获取该图层参见 FMKMap

 可通过地图map节点获取
 */
@interface FMKModelLayer : FMKLayer

/**
 模型层透明度
 
 设置模型透明度会将该图层下所有模型的透明度设置为该数值
 */
@property (nonatomic, assign) CGFloat alpha;

/**
 *  初始化模型层，暂不支持用户创建模型层
 *
 *  @param groupID 楼层ID
 *
 *  @return 地图模型层对象
 */
- (instancetype)initWithGroupID:(NSString *)groupID;

///模型层所在的groupID
@property (readonly) NSString* groupID;


/**
 *  根据FID查找model，注意与FMKSearchAnalyser搜索得到的结果区分
 *
 *  @param FID 模型的唯一标识码
 *
 *  @return FMKModel
 */
- (FMKModel *)queryModelByFID:(NSString *)FID;

/**
 *  根据模型类型查找model
 *
 *  @param type 模型类型，参见FMKModel type
 *
 *  @return 查询结果数组 FMKModel
 */
- (NSArray *)queryModelByType:(NSString *)type;

@end
