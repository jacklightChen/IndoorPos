//
//  FMKLocateCoordTransformer.h
//  FMMapKit
//
//  Created by smallLabel on 2018/3/27.
//  Copyright © 2018年 Fengmap. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "FMKGeometry.h"

/**
 坐标转化工具类
 */
@interface FMKLocateCoordTransformer : NSObject

/**
 经纬度转墨卡托坐标
 
 @param coordinate 经纬度坐标
 @return 转化后的墨卡托坐标
 */
+ (FMKMapPoint)geographicCoordinate2MercatorWithCoordinate:(FMKMapPoint)coordinate;

/**
 设置定位系统参数

 @param origin 定位系统原点坐标
 @param range 定位系统范围，如图片像素宽高
 */
- (void)setLocateOrigin:(CGPoint)origin locateRange:(CGPoint)range;

/**
 设置对应fengmap参数

 @param origin 定位系统原点坐标对应到fengmap的坐标点
 @param xLimitPoint 沿X轴增大的fengmap边界点坐标
 @param yLimitPoint 沿Y轴增大的fengmap边界点坐标
 */
- (void)setFengmapOrigin:(FMKMapPoint)origin 
           fmXLimitPoint:(FMKMapPoint)xLimitPoint
           fmYLimitPoint:(FMKMapPoint)yLimitPoint;

/**
 定位坐标转化到fengmap坐标
 在转化之前必须设置好定位系统和fengmap相关参数，否则返回{0, 0}

 @param locatePoint 定位坐标点
 @return 转化完成的fengmap坐标
 */
- (FMKMapPoint)transformWithLocatePoint:(CGPoint)locatePoint;

@end
