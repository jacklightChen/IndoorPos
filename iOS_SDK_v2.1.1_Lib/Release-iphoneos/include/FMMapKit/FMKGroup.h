//
//  FMKGroup.h
//  FMMapKit
//
//  Created by fengmap on 16/1/12.
//  Copyright © 2016年 Fengmap. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>

@class FMKGroupInfo;
/**
 *	楼层  楼层的初始化不支持用户自定义创建
 *	可通过map获取
 *	楼层信息在地图创建完成后绑定地图 用户不能自定义楼层信息
 *	获取到楼层可设置楼层的显隐和透明度 其他属性无法通过该对象设置
 */
@interface FMKGroup : NSObject

/**
 内部关联指针
 */
@property (nonatomic, assign) long pointer;

/**
 楼层ID(不可设置)
 */
@property (nonatomic, copy) NSString * groupID;

/**
 楼层高度
 */
@property (nonatomic, readonly) CGFloat height;

/**
 楼层信息（不可设置）
 */
@property (nonatomic, strong) FMKGroupInfo * groupInfo;

/**
 楼层隐藏属性（可设置）
 */
@property (nonatomic, assign) BOOL hidden;

/**
 楼层透明度（可设置）
 */
@property (nonatomic, assign) CGFloat alpha;

/**
 *  初始化楼层 不支持用户创建楼层 只能通过map获取楼层
 *
 *  @param groupID 楼层ID
 *
 *  @return FMKGroup对象
 */
- (instancetype)initWithGroupID:(NSString *)groupID;

@end
