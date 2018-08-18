//
//  FMKAnimatorEnableController.h
//  FMMapKit
//
//  Created by FengMap on 15/11/13.
//  Copyright © 2015年 Fengmap. All rights reserved.
//
#import <Foundation/Foundation.h>

/**
 地图手势动画控制对象
 */
@interface FMKAnimatorEnableController : NSObject

///控制地图轻扫时的惯性动画 默认为YES
@property (nonatomic, assign) BOOL mapViewEnableMoveAnimation;

///控制地图缩放动画 默认为YES
@property (nonatomic, assign) BOOL mapViewEnableZoomAnimation;

///控制地图的旋转动画 默认为YES
@property (nonatomic, assign) BOOL mapViewEnableRotateAnimation;

/**
 *  动画控制对象创建
 *
 *  @return 动画控制对象
 */
+(FMKAnimatorEnableController *)sharedFMKAnimatorEnableController;

@end
