//
//  FMKLayer.h
//  FMMapKit
//
//  Created by FengMap on 15/6/2.
//  Copyright (c) 2015年 FengMap. All rights reserved.
//


#import <Foundation/Foundation.h>
#import "FMKGeometry.h"
#import "FMKLayerDelegate.h"

/**
 *  地图图层节点基类
 */
@interface FMKLayer : NSObject 

///内部关联指针 不可修改
@property (nonatomic, assign)  long pointer;

/**
 自定义图层唯一标识
 
 用户创建自定义图层时设置，可选
 */
@property (nonatomic, assign) NSInteger layerTag;

/**
 图层代理
 
 用于触发图层元素拾取事件
 */
@property (nonatomic, weak) id<FMKLayerDelegate> delegate;

///图层的隐藏属性
@property (nonatomic, assign) BOOL hidden;

/**
 图层下的所有子节点
 
 如模型层下的所有模型
 */
@property (nonatomic, readonly) NSArray*  subNodes;

@end

