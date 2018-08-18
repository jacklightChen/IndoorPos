//
//  FMKAnimationDelegate.h
//  FMMapKit
//
//  Created by fengmap on 16/7/22.
//  Copyright © 2016年 Fengmap. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 插值回调方法
 */
@protocol FMKAnimationDelegate <NSObject>

/**
 *  动画插值回调
 *
 *  @param value 插值结果
 *  @param key   key
 */
- (void)updateInterpolationValue:(id)value key:(NSString *)key;

@optional

/**
 *  动画将要开始
 *
 *  @param animation 动画
 *  @param key       KEY
 */
- (void)animationWillStart:(FMKAnimation * )animation key:(NSString *)key;
/**
 *  动画正在执行
 *
 *  @param animation 动画对象
 *  @param key       KEY
 */
- (void)animationIsExecuting:(FMKAnimation *)animation key:(NSString *)key;
/**
 *  动画完成
 *
 *  @param animation 动画对象
 *  @param key       KEY
 */
- (void)animationDidFinish:(FMKAnimation *)animation key:(NSString *)key;

/**
 *  动画暂停
 *
 *  @param animation 动画对象
 *  @param key       KEY
 */
- (void)animationPause:(FMKAnimation *)animation key:(NSString *)key;
/**
 *  动画暂停恢复
 *
 *  @param animation 动画对象
 *  @param key       KEY
 */
- (void)animationResume:(FMKAnimation *)animation key:(NSString *)key;

@end
