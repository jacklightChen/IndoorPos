//
//  FMKCameraInfo.h
//  FMMapKit
//
//  Created by smallLabel on 2017/7/21.
//  Copyright © 2017年 Fengmap. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "FMKGeometry.h"


/**
 相机状态信息
 */
@interface FMKCameraInfo : NSObject
///相机位置
@property (nonatomic) FMKMap3DPoint cameraPostion;
///x:偏航  y:俯仰角  z:翻滚
@property (nonatomic) FMKMap3DPoint cameraEulerAngle;
///视窗纵横比
@property (nonatomic) CGFloat aspectRatio;

@end

/**
 3D相机信息
 */
@interface FMKPerspectiveCameraInfo : FMKCameraInfo
///相机可视角度
@property (nonatomic) CGFloat cameraFov;
///近裁剪面zNear
@property (nonatomic) CGFloat zNear;
///远裁剪面zFar
@property (nonatomic) CGFloat zFar;

@end


/**
 2D相机信息
 */
@interface FMKOrthoCameraInfo : FMKCameraInfo

///left
@property (nonatomic) CGFloat left;
///right
@property (nonatomic) CGFloat right;
///bottom
@property (nonatomic) CGFloat bottom;
///top
@property (nonatomic) CGFloat top;
///近裁剪面
@property (nonatomic) CGFloat zNear;
///远裁剪面
@property (nonatomic) CGFloat zFar;

@end
