//
//  FMKInterpolator.h
//  FMMapKit
//
//  Created by FengMap on 15/11/4.
//  Copyright © 2015年 FengMap. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef double GoingTime;
typedef double OriginalValue;
typedef double ChangedValue;



/**
 插值函数类型

 - FMKSTAGE_IN: 渐入
 - FMKSTAGE_OUT: 渐出
 - FMKSTAGE_INOUT: 先渐入后渐出
 */
typedef NS_ENUM(NSInteger, FMKStageType)
{
    ///渐入
    FMKSTAGE_IN = 0,
    ///渐出
    FMKSTAGE_OUT,
    ///先渐入后渐出
    FMKSTAGE_INOUT
    
};

/**
 动画插值器函数对象
 */
@interface FMKInterpolator : NSObject

/**
 *  缓动函数插值类型
 */
@property(nonatomic,assign) FMKStageType type;

/**
 *  插值器初始化
 *
 *  @param stageType 插值类型 默认使用USE_INOUT
 *
 *  @return 插值器对象
 */
- (instancetype)initWithStageType:(FMKStageType)stageType;


/**
 *  插值器类型函数 FMKSTAGE_IN
 *
 *  @param goingTime    已运行时间
 *  @param start        起始值
 *  @param changed      改变量
 *  @param duration 持续时间
 *
 *  @return 计算插值
 */
- (double)inWithGoingTime:(GoingTime)goingTime
                 withStart:(OriginalValue )start
                  withEnd:(ChangedValue )changed
         withDuration:(NSTimeInterval)duration;
/**
 *  插值器类型函数 FMKSTAGE_OUT
 *
 *  @param goingTime    已运行时间
 *  @param start        起始值
 *  @param changed      改变量
 *  @param duration 持续时间
 *
 *  @return 计算插值
 */
- (double)outWithGoingTime:(GoingTime)goingTime
                 withStart:(OriginalValue )start
                   withEnd:(ChangedValue )changed
          withDuration:(NSTimeInterval)duration;

/**
 *  插值器类型函数 FMKSTAGE_INOUT
 *
 *  @param goingTime    已运行时间
 *  @param start        起始值
 *  @param changed      改变量
 *  @param duration 持续时间
 *
 *  @return 计算插值
 */
- (double)inOutWithGoingTime:(GoingTime)goingTime
                   withStart:(OriginalValue)start
                     withEnd:(ChangedValue )changed
            withDuration:(NSTimeInterval)duration;


@end
