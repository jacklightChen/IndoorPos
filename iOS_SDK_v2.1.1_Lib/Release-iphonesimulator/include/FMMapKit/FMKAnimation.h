//
//  FMKAnimation.h
//  FMMapKit
//
//  Created by fengmap on 16/7/22.
//  Copyright © 2016年 Fengmap. All rights reserved.
//

#import <Foundation/Foundation.h>


/**
 动画插值基类
 */
@interface FMKAnimation : NSObject


/**
 动画初始化方法

 @param duration 动画持续时间
 @param key 动画唯一标识
 @return 动画对象
 */
- (instancetype)initWithDuration:(NSTimeInterval)duration key:(NSString *)key;

/**
 动画持续时间
 */
@property (nonatomic, assign) NSTimeInterval duration;

/**
 自定义动画编号
 */
@property (nonatomic, readonly) NSString * key;

/**
 *  开始动画
 */
- (void)start;

/**
 *  暂停动画
 */
- (void)pause;

/**
 *  恢复动画
 */
- (void)resume;

/**
 *  停止动画
 */
- (void)stop;

@end
