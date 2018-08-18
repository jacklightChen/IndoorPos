//
//  FMKLocationMarker.h
//  FMMapKit
//
//  Created by FengMap on 15/7/20.
//  Copyright (c) 2015年 FengMap. All rights reserved.
//

#import "FMKNode.h"

/**
 * 定位标注，可移动图片点
 * 功能单一，非移动图片标注
 */
@interface FMKLocationMarker : FMKNode

/**
 * 定位点资源图片需要放在FMBundle里
 * 也可以替换掉上述的两个图片文件
 *
 *  @param pName "pointer.png"
 *  @param dName "dome.png"
 *
 *  @return 定位功能标注
 */
- (instancetype)initWithPointerImageName:(NSString *)pName
                           DomeImageName:(NSString *)dName;
@property (readonly) NSString* pImageName;
@property (readonly) NSString* dImageName;


/**
 当前定位点位置
 */
@property (nonatomic, readonly) FMKGeoCoord currentCoord;

/**
 旋转角度改变量
 */
@property (nonatomic, readonly) float angle;

///定位标注物的大小
@property (nonatomic,assign) CGSize size;


/**
 定位标注物位置更新

 @param geoCoord fengmap地图坐标
 */
- (void)locateWithGeoCoord:(FMKGeoCoord)geoCoord;

/**
 定位标注物旋转角度更新

 @param rotate 旋转角度
 */
- (void)updateRotate:(CGFloat)rotate;

@end
