//
//  FMKGraphicsMath.h
//  FMMapKit
//
//  Created by fengmap on 16/12/28.
//  Copyright © 2016年 Fengmap. All rights reserved.
//

#import <Foundation/Foundation.h>


/**
 fengmap数学计算类
 */
@interface FMKGraphicsMath : NSObject

/**
 计算平滑点插值

 @param points 原始点集合
 @param width 影响范围
 @return 计算结果
 */
+ (NSArray *)calcBezierByPoints:(NSArray *)points withWidth:(double)width;

@end
