//
//  FMKNode.h
//  FMMapKit
//
//  Created by FengMap on 15/5/25.
//  Copyright (c) 2015年 FengMap. All rights reserved.
//
#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "FMKGeometry.h"
/**
 * 地图节点基类，
 * 节点用于显示在地图上的额外添加物
 */
@interface FMKNode : NSObject

///内部关联指针 不可修改
@property (nonatomic,assign) long pointer;

///内部关联指针集合 不可修改
@property (nonatomic, strong) NSArray * pointers;

/**
 *  元素的唯一标识
 *
 *	在创建自定义标注物时赋值
 */
@property (nonatomic,assign)  NSInteger nodeTag;

/**
 *  用户自定义标注物附加属性
 *
 *	附件属性由用户自定义
 */
@property (nonatomic,strong) NSDictionary *  attributes;

///元素隐藏属性
@property (nonatomic, assign) BOOL hidden;

@end
