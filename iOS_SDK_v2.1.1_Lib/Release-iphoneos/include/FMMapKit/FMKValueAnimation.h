//
//  FMKValueAnimation.h
//  FMMapKit
//
//  Created by fengmap on 16/7/22.
//  Copyright © 2016年 Fengmap. All rights reserved.
//

#import "FMKAnimation.h"
#import "FMKAnimationDelegate.h"

@class FMKInterpolator;

/**
 自定义动画
 */
@interface FMKValueAnimation : FMKAnimation

/**
 *  起始值
 */
@property (nonatomic, retain) id fromValue;
/**
 *  终点值
 */
@property (nonatomic, retain) id toValue;
/**
 *  动画回调代理
 */
@property (nonatomic, weak) id<FMKAnimationDelegate>delegate;

/**
 设置动画插值器对象
 */
@property (nonatomic, strong) FMKInterpolator * interpolator;

@end
