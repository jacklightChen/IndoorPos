//
//  FMKMathTool.h
//  FMMapKit
//
//  Created by smallLabel on 2018/3/14.
//  Copyright © 2018年 Fengmap. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "FMKGeometry.h"

/**
 fengmap 数学工具类
 */
@interface FMKMathTool : NSObject

/**
 计算两个地图坐标点的直线距离

 @param mapPoint1 地图坐标点1
 @param mapPoint2 地图坐标点2
 @return 两点直线距离
 */
+ (double)calculateTwoMapPointsDistanceWithPoint1:(FMKMapPoint)mapPoint1 point2:(FMKMapPoint)mapPoint2;

@end
