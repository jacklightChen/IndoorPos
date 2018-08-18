//
//  FMKMapGestureEnableController.h
//  FMMapKit
//
//  Created by fengmap on 16/3/28.
//  Copyright © 2016年 Fengmap. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 地图手势控制对象
 通过FMKMapView获取
 */
@interface FMKMapGestureEnableController : NSObject

///旋转手势控制 默认为YES
@property (nonatomic,assign) BOOL enableMapRotate;
///拖拽手势控制 默认为YES
@property (nonatomic,assign) BOOL enableMapPan;
///倾斜手势控制 默认为YES
@property (nonatomic,assign) BOOL enableMapIncline;
///捏合手势控制 默认为YES
@property (nonatomic,assign) BOOL enableMapPinch;
///单击手势控制 默认为YES
@property (nonatomic,assign) BOOL enableMapSingalTap;
///双击手势控制 默认为YES
@property (nonatomic,assign) BOOL enableMapDoubleTap;
///长按手势控制 默认为YES
@property (nonatomic,assign) BOOL enableMapLongPress;
///轻扫手势控制 默认为YES
@property (nonatomic,assign) BOOL enableMapSwipe;

@end
