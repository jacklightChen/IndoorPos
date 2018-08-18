//
//  FMKNavigation.h
//  FMMapKit
//
//  Created by smallLabel on 2017/10/20.
//  Copyright © 2017年 Fengmap. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "FMKGeometry.h"
#import "FMKNaviAnalyser.h"

@class FMKMapView, FMKNaviPredictionSegment, FMKPointOption, FMKNaviResult, FMKNavigationInfo, FMKLineMarker;

@protocol FMKNavigationDelegate;

/**
 导航路径规划结果
 */
typedef NS_ENUM(NSInteger, FMKAnalyseRouteResult) {

    ///路算成功
    FMKANALYSERESULT_SUCCESS = 1, 
    ///路算失败，原因：没有起点
    FMKANALYSERESULT_NOSTART,           
    ///路算失败，原因：没有终点
    FMKANALYSERESULT_NOEND,
    ///路算失败，原因：计算失败
    FMKANALYSERESULT_CALCULATEFAILURE
};

/**
 导航功能基类
 */
@interface FMKNavigation : NSObject

///实现了 FMKNavigationDelegate 协议的类指针
@property (nonatomic, weak, nullable) id<FMKNavigationDelegate>delegate;
///路算结束后的路段信息
@property (nonatomic, readonly, nullable) NSArray<FMKNaviPredictionSegment *> *segments;
///路算结果
@property (nonatomic, readonly, nullable) NSArray<FMKNaviResult *> *naviResults;
///路算结束后的文本描述
@property (nonatomic, readonly, nullable) NSArray<NSString *> *describes;
///地图视图
@property (nonatomic, readonly, nonnull) FMKMapView *mapView;
///路径规划成功后的路径总长
@property (nonatomic) CGFloat length;

///路径规划完成后画线，每个navigation对象同时只能有一个线标注物
@property (nonatomic, readonly, nullable) FMKLineMarker *lineMarker;
///路径规划起点坐标
@property (nonatomic, readonly) FMKGeoCoord start;
///路径规划终点坐标
@property (nonatomic, readonly) FMKGeoCoord end;

/**
 初始化地图导航对象
 该类为基类，请使用子类初始化

 @param mapView 当前显示的地图视图，地图视图不可为空
 @return 地图导航对象
 */
- (instancetype _Nullable)initWithMapView:(FMKMapView *_Nonnull)mapView;

/**
 设置导航的起点坐标
 设置该属性后会自动在相应位置添加默认的图片标注，该图标标注属性可通过setStartOption:方法修改
 注意该图片标注物的管理与FMKImageLayer密切相关，若要删除imageLayer时注意图层的tag
 该图片标注物所在图层imageLayer的layerTag默认为-1
 
 @param startPoint 起点坐标
 */
- (void)setStartPoint:(FMKGeoCoord)startPoint;
/**
 设置导航的终点坐标
 设置该属性后会自动在相应位置添加默认的图片标注，该图标标注属性可通过setEndOption:方法修改
 注意该图片标注物的管理与FMKImageLayer密切相关，若要删除imageLayer时注意图层的tag
 该图片标注物所在图层imageLayer的layerTag默认为-1
 
 @param endPoint 起点坐标
 */
- (void)setEndPoint:(FMKGeoCoord)endPoint;

/**
 设置起点图片标注属性

 @param startOption 待设置的起点图片标注属性，若为空则采用默认配置
 */
- (void)setStartOption:(FMKPointOption * _Nullable)startOption;
/**
 设置终点图片标注属性
 
 @param endOption 待设置的终点图片标注属性，若为空或不调用则采用默认配置
 */
- (void)setEndOption:(FMKPointOption *_Nullable)endOption;

/**
 在当前显示地图上进行路径规划

 @param routeSetting 路径规划偏好设置
 @return 路径规划结果
 */
- (FMKAnalyseRouteResult)analyseRoute:(FMKRouteSetting)routeSetting;

/**
 根据路径规划结果绘制线标注

 @return 生成的线标注物，此线标注物受全局的FMKLineLayer的管理
 */
- (FMKLineMarker * _Nullable)drawNaviLine;

/**
 清除所有起终点标注、线标注及路径规划结果，所有属性恢复初始化状态
 注意模拟导航在调用此方法之前必须调用一次stop方法
 */
- (void)clear;

@end


/**
 导航过程状态回调
 */
@protocol FMKNavigationDelegate <NSObject>

/**
 导航过程

 @param navigation 导航对象
 @param navigationInfo 导航信息
 */
- (void)navigation:(FMKNavigation *_Nonnull)navigation walking:(FMKNavigationInfo *_Nonnull)navigationInfo;

/**
 导航完成回调

 @param navigation 导航对象
 */
- (void)complete:(FMKNavigation *_Nonnull)navigation;

@end
