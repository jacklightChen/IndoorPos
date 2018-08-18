//
//  FMKExternalModelLayer.h
//  FMMapKit
//
//  Created by fengmap on 16/6/1.
//  Copyright © 2016年 Fengmap. All rights reserved.
//

#import "FMKLayer.h"
@class FMKExternalModel;

/**
 该类为3D模型图层管理类
 3D模型时特殊的地图数据模型，需要结合主题内的3D模型文件配套使用
 该图层的获取方法与FMKMadelLayer类似。不可由开发者自主创建
 */
@interface FMKExternalModelLayer : FMKLayer

///所在楼层
@property (nonatomic,copy)NSString * groupID;

/**
 初始化3D模型图层
 该初始化方法不应由开发者自主创建

 @param groupID 楼层id
 @return 3D模型图层
 */
- (instancetype)initWithGroupID:(NSString *)groupID;

/**
 *  通过fid查找外部模型
 *
 *  @param fid 外部模型的fid
 *
 *  @return 获取外部模型
 */
- (FMKExternalModel *)queryExternalModelByFid:(NSString *)fid;

@end
