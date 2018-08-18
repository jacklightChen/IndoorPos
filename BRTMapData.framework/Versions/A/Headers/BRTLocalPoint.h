//
//  BRTLocalPoint.h
//  BRTMapProject
//
//  Created by thomasho on 2018/4/18.
//  Copyright © 2018年 o2o. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>

@interface BRTLocalPoint : NSObject

/**
 * 经纬度坐标
 */
@property (nonatomic, assign, readonly) CLLocationCoordinate2D coordinate;

/**
 *  米坐标X
 */
@property (nonatomic, assign) double x;

/**
 *  米坐标Y
 */
@property (nonatomic, assign) double y;

/**
 *  楼层号
 */
@property (nonatomic, assign) int floor;

/**
 *  位置点的经纬度实例化方法
 *
 *  @param coordinate 经纬度坐标
 *  @param f 位置点所在楼层
 *
 *  @return 位置点实例
 */
+ (BRTLocalPoint *)pointWithCoor:(CLLocationCoordinate2D)coordinate Floor:(int)f;

/**
 *  位置点的米坐标实例化方法
 *
 *  @param x 米坐标x
 *  @param y 米坐标y
 *  @param f 位置点所在楼层
 *
 *  @return 位置点实例
 */
+ (BRTLocalPoint *)pointWithX:(double)x Y:(double)y Floor:(int)f;

/**
 两点直线距离
 
 @param p 另一点
 @return 直线距离
 */
- (double)distanceWith:(BRTLocalPoint *)p;

@end

