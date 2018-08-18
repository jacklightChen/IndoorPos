//
//  FMKPointOption.h
//  FMMapKit
//
//  Created by smallLabel on 2017/10/23.
//  Copyright © 2017年 Fengmap. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "FMKImageMarker.h"

/**
 导航图片点标注属性
 */
@interface FMKPointOption : NSObject
///点标注图片
@property (nonatomic, strong, nullable) UIImage *image;
///图片高度偏移量,偏移量设置只有在offsetMode属性为FMKImageMarker_USERDEFINE时有效
@property (nonatomic) CGFloat imageOffset;
///图片大小
@property (nonatomic) CGSize imageSize;
///图片高度偏移模式
@property (nonatomic) FMKImageMarkerOffsetMode offsetMode;
///图片绘制模式  直立或者平铺
@property (nonatomic) FMKImageMarkerRenderMode renderMode;
///图片旋转角度
@property (nonatomic) CGFloat angle;
///图片显隐控制
@property (nonatomic) BOOL hidden;

@end
