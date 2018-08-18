//
//  FMKImageMarkerNode.h
//  FMMapKit
//
//  Created by FengMap on 15/5/23.
//  Copyright (c) 2015年 FengMap. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "FMKNode.h"

@class FMKImageMarkerStyle;

/**
 *  图片位于地图上的位置
 */
typedef NS_ENUM(NSInteger, FMKImageMarkerOffsetMode){
    /**
     *  位于建筑模型之上
     */
    FMKImageMarker_MODELTOP=0,
    /**
     *  位于地面之上
     */
    FMKImageMarker_OVEREXTENT,
    
    /**
     *  用户自定义
     */
    FMKImageMarker_USERDEFINE
};


/**
 图片绘制模式

 - FMKImageMarker_NORMAL: 默认模式
 - FMKImageMarker_BILLBOARD: 广告版模式
 */
typedef NS_ENUM(NSInteger, FMKImageMarkerRenderMode)
{
    ///默认模式
	FMKImageMarker_NORMAL = 0,
    ///广告版模式
	FMKImageMarker_BILLBOARD
};

/**
 * @brief 用户自定义图片点位置，
 * 可用一张自定义图片进行模型等的描述
 */
@interface FMKImageMarker : FMKNode

/**
 *  使用UIImage初始化
 *
 *  @param image    UIImage对象
 *  @param mapCoord 地图地理坐标
 *
 *  @return 图片标注对象
 */
- (instancetype)initWithImage:(UIImage *)image
                        Coord:(FMKMapPoint)mapCoord;

/**
 *  需要使用png格式的图片；
 *  默认图片路径为nil
 *  若不设置图片路径，则此处可设图片全路径
 *
 *  @param name     图片名
 *  @param mapCoord 地理坐标
 *
 *  @return 图片标注对象
 */
- (instancetype)initWithImageName:(NSString *)name
                            Coord:(FMKMapPoint)mapCoord;

/**
 *  设置图片平铺
 */
- (void)setImageMarkerTile;

/**
 *  添加动画效果 偏移模式必须为FMKImageMarker_USERDEFINE
 *
 *  @param changeValue z值该变量
 *  @param repeatCount 重复次数 -1表示无限循环
 *  @param time        每个周期时间
 */
- (void)addAnimationWithChangeValue:(float)changeValue repeatCount:(int)repeatCount perCycleTime:(double)time;
/**
 * 停止动画
 */
- (void)stopAnimation;
/// 添加的图片
@property (nonatomic, strong) UIImage *image;
/// 图片资源名
@property (nonatomic,readonly) NSString *imageName;
/// 标注物地理坐标中心点
@property (nonatomic,assign) FMKMapPoint mapCoord;
/// 图片大小
@property (nonatomic,assign) CGSize imageSize;
/// 选中状态
@property (nonatomic,assign) BOOL selected;
/// 自定义图片标注所在的位置
@property (nonatomic,assign) FMKImageMarkerOffsetMode offsetMode;
/// 设置图片标注物所在位置的高度偏移量
@property (nonatomic,assign) CGFloat imageOffset;
///图片的旋转角度
@property (nonatomic,assign) CGFloat  angle;
///绘制模式
@property (nonatomic, assign) FMKImageMarkerRenderMode renderMode;

@end






