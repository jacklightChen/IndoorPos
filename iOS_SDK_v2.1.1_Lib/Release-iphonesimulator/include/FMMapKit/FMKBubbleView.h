//
//  FMKBubbleView.h
//  FMMapKit
//
//  Created by fengmap on 16/7/25.
//  Copyright © 2016年 Fengmap. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "FMKGeometry.h"
#import "FMKMapView.h"

/**
 自定义气泡
 */
@interface FMKBubbleView : UIView

/**
 气泡所在的地图位置
 
 重设该参数可更新气泡位置
 */
@property (nonatomic, assign) FMKGeoCoord coord;
/**
 初始化气泡视图

 @param customView 自定义控件
 @param coord 气泡添加到地图上的地图坐标
 @return 气泡对象
 */
- (instancetype)initWithCustomView:(UIView *)customView atPoint:(FMKGeoCoord)coord;

/**
 *  添加气泡
 *
 *  @param mapView 气泡所在的地图
 *  @param zType   气泡所在坐标的Z值  表示气泡在地面、模型、标注物等之上
 *	@param height  自定义高度偏移量（屏幕像素高度）负值为屏幕上方移动
 */
- (void)addBubbleViewOnMapView:(FMKMapView *)mapView mapCoordZType:(FMKMapCoordZType)zType height:(CGFloat)height;
/**
 *  删除气泡
 */
- (void)removeFromMap;
@end
