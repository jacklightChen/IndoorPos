//
//  FMKPolygonMarker.h
//  FMMapKit
//
//  Created by fengmap on 16/4/15.
//  Copyright © 2016年 Fengmap. All rights reserved.
//

#import "FMKNode.h"

/**
 *  覆盖面标注物偏移模式
 */
typedef NS_ENUM(NSInteger,FMKPolygonMarkerOffsetMode) {
    /**
     *  位于模型之上
     */
    FMKPolygonMarker_MODELTOP = 0,
    /**
     *  位于底面之上
     */
    FMKPolygonMarker_OVEREXTENT,
    /**
     *  用户自定义 当选择这个模式时，需要设置标注物的偏移量
     */
    FMKPolygonMarker_USERDEFINE
};
/**
 *  多边形形状
 */
typedef NS_ENUM(NSInteger, FMKPolygonMarkerType) {
	/**
	 *  普通形状
	 */
	FMKPolygonMarker_NORMAL = 0,
	/**
	 *  矩形
	 */
	FMKPolygonMarker_RECTANGLE,
	/**
	 *  圆
	 */
	FMKPolygonMarker_CIRCLE
};


/**
 自定义面标注物
 */
@interface FMKPolygonMarker : FMKNode

/**
 *  标注物偏移模式
 */
@property (nonatomic, assign) FMKPolygonMarkerOffsetMode offsetMode;
/**
 *  标注物type
 */
@property (nonatomic, readonly) FMKPolygonMarkerType type;
/**
 *  偏移量  只有在FMKPolygonMarker_USERDEFINE模式时有效
 */
@property (nonatomic, assign) CGFloat offset;

/**
 *  边框线宽 负值为内边框
 */
@property (nonatomic, assign) CGFloat lineWidth;
/**
 *  覆盖面标注物颜色
 */
@property (nonatomic, strong) UIColor * color;
/**
 *  边框颜色
 */
@property (nonatomic, strong) UIColor * lineColor;

/**
 *  覆盖面标注物的顶点地图坐标集合
 */
@property (nonatomic, strong) NSArray * mapPoints;

/**
 *  覆盖面标注物的透明度
 */
@property (nonatomic, assign) CGFloat alpha;
/**
 *  中心位置  矩形和圆形有效
 */
@property (nonatomic, readonly) FMKMapPoint centerPosition;

/**
 *  FID 元素唯一标识
 */
@property (nonatomic, readonly) NSString * FID;

/**
 *  name
 */
@property (nonatomic, readonly) NSString * name;

/**
 *  ename
 */
@property (nonatomic, readonly) NSString * ename;

/**
 *  height
 */
@property (nonatomic, readonly) CGFloat height;
/**
 *  矩形宽
 */
@property (nonatomic, readonly) CGFloat width;
/**
 *  圆半径
 */
@property (nonatomic, readonly) CGFloat radius;
/**
 *  圆分割数
 */
@property (nonatomic, readonly) NSInteger segments;

/**
 *  初始化覆盖面标注物
 *
 *  @param color     覆盖面标注物的颜色
 *  @param mapPoints 覆盖面标注物的顶点地图坐标集合 至少需要三个地图顶点坐标FMKMapPoint
 *
 *  @return 覆盖面标注物
 */
- (instancetype)initWithColor:(UIColor *)color
					withCoord:(NSArray *)mapPoints;

/**
 *  初始化矩形覆盖物
 *
 *  @param color    矩形填充色
 *  @param width    矩形宽
 *  @param height     矩形高
 *  @param position 中心位置
 *
 *  @return 矩形标注物
 */
- (instancetype)initWithColor:(UIColor *)color
						width:(CGFloat)width
					   height:(CGFloat)height
			   centerPosition:(FMKMapPoint)position;

/**
 *  初始化圆形
 *
 *  @param color    填充颜色
 *  @param radius   半径
 *  @param position 圆心坐标
 *  @param segments 分段数 该参数影响逼近圆的线段边数
 *
 *  @return 圆标注物
 */
- (instancetype)initWithColor:(UIColor *)color
					   radius:(CGFloat)radius
			   centerPosition:(FMKMapPoint)position
					 segments:(NSInteger)segments;


/**
 *  判断一个地图坐标是否在覆盖面内
 *
 *  @param mapPoint 地图坐标
 *
 *  @return 判断结果
 */
- (BOOL)mapPointIsContained:(FMKMapPoint)mapPoint;

@end
