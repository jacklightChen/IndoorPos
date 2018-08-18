//
//  FMKMapStatus.h
//  FMMapKit
//
//  Created by fengmap on 16/8/2.
//  Copyright © 2016年 Fengmap. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "FMKGeometry.h"

/**
 *	本部分为地图状态管理对象，不支持用户自定义
 *	可通过FMKMap获取
 */
@interface FMKMapStatus : NSObject

///内部关联对象，不可修改
@property (nonatomic, assign) long pointer;

/**
 *	地图缩放比例
 *
 *	在当前基础上累乘 当前比例永远为1.0
 */
@property (nonatomic, assign) float zoomScale;

/**
 *	设置地图倾斜角度
 *
 *	参数单位为度，90°为俯视倾角
 *	范围30~90
 */
@property (nonatomic, assign) float inclineAngle;

/**
 *	设置地图旋转角度
 *
 *	逆时针为正
 */
@property (nonatomic, assign) float rotateAngle;

/**
 *  设置地图的缩放范围
 *
 *	范围为0.0~1.0
 */
@property (nonatomic, assign) FMKMapScaleRange zoomRange;

@end
