//
//  FMKScene.h
//  FMMapKit
//
//  Created by FengMap on 15/8/20.
//  Copyright (c) 2015年 FengMap. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "FMKGeometry.h"

@class FMKMapInfo;

@class FMKGroup;

@class FMKLayer;
@class FMKLineLayer,FMKLocationLayer; //只读层，单个
@class FMKFacilityLayer,FMKModelLayer,FMKTextLayer,FMKExtentLayer,FMKLabelLayer,FMKGroundLayer,FMKExternalModelLayer;     //只读层，多个
@class FMKImageLayer,FMKTextLayer,FMKPolygonLayer;

@class FMKMapStatus;


/**
 地图管理根节点对象 
 不可由用户创建
 */
@interface FMKMap : NSObject

/**
 不支持自己创建
 初始化地图数据
 @param dataPath 地图路径
 @return 地图管理对象
 */
- (instancetype)initWithPath:(NSString *)dataPath;

///该地图数据路径
@property (nonatomic, readonly) NSString* dataPath;

///内部关联指针 不可修改
@property (nonatomic, assign)  long pointer;


/**
 地图显示状态
 
 设置地图显示状态，如旋转角度等
 */
@property (nonatomic, strong) FMKMapStatus * mapStatus;

///地图ID
@property (nonatomic, readonly) NSString* ID;

/**
 楼层名数组
 
 该地图所有楼层的名称
 */
@property (nonatomic, readonly) NSArray * groupNames;

/**
 地图的所有楼层ID
 */
@property (nonatomic, readonly) NSArray * groupIDs;
/**
 地图信息
 
 该地图的所有信息
 */
@property (nonatomic, readonly) FMKMapInfo* info;


/**
 地图线标注物管理层
 
 不支持用户创建，直接与地图根节点关联，不与楼层关联
 */
@property (nonatomic, readonly) FMKLineLayer*  lineLayer;

/**
 地图定位管理层
 
 不支持用户创建，直接与地图根节点关联，不与楼层关联
 */
@property (nonatomic, readonly) FMKLocationLayer*  locationLayer;

/**
 控制缩放级别范围
 */
@property (nonatomic, assign) FMKMapZoomLevelRange zoomLevelRange;

/**
 设置比例尺
 */
@property (nonatomic, assign) CGFloat rulerRatio;

/**
 设置缩放级别

 @param zoomLevel 缩放级别
 @param animated  动效开关
 */
- (void)setZoomLevel:(CGFloat)zoomLevel animated:(BOOL)animated;

/**
 获取当前地图的显示级别

 @return 当前地图显示级别
 */
- (CGFloat)getCurrentZoomLevel;

/**
 *  获取楼层管理对象
 *
 *  @param groupID 楼层ID
 *
 *  @return 楼层管理对象
 */
- (FMKGroup*)getGroupByGroupID:(NSString *)groupID;

/**
 *  获取地图的ground层管理对象
 *
 *  @param groupID ground层所在的Group层
 *
 *  @return FMKGroundLayer
 */
- (FMKGroundLayer *)getGroundLayerWithGroupID:(NSString *)groupID;

/**
 *  获取地图公共设施管理层
 *
 *  @param groupID 公共设施层所在的group层
 *
 *  @return 公共设施层管理对象
 */
- (FMKFacilityLayer *)getFacilityLayerByGroupID:(NSString *)groupID;

/**
 *  获取地图Model管理层对象
 *
 *  @param groupID model层所在的group层
 *
 *  @return model层管理对象
 */
- (FMKModelLayer *)getModelLayerByGroupID:(NSString *)groupID;

/**
 获取地图外部模型图层
 
 该图层为真实模型管理图层

 @param groupID 楼层id
 @return 外部模型管理图层
 */
- (FMKExternalModelLayer *)getExternalModelLayerByGroupID:(NSString *)groupID;

/**
 *  获取地图text层管理对象
 *
 *  @param groupID text层所在group层
 *
 *  @return text层管理对象
 */
- (FMKLabelLayer *)getLabelLayerByGroupID:(NSString *)groupID;

/**
 *  获取对应group层下的已添加image层对象
 *
 *  @param groupID image层所在的group层
 *
 *  @return image层管理对象
 */
- (NSArray *)getImageLayerByGroupID:(NSString *)groupID;

/**
 *  获取对应楼层下的已添加的文本图层
 *
 *  @param groupID 楼层ID
 *
 *  @return 对应楼层下的文本图层
 */
- (NSArray *)getTextLayerByGroupID:(NSString *)groupID;

/**
 *  获取对应楼层下的覆盖面图层
 *
 *  @param groupID 楼层编号
 *
 *  @return 该楼层下所有的覆盖面图层
 */
- (NSArray *)getPolygonLayerByGroupID:(NSString *)groupID;
/**
 *  获取对应楼层下的底图图层
 *
 *  @param groupID 底图所在的楼层ID
 *
 *  @return 底图图层对象
 */
- (FMKExtentLayer *)getExtentLayerByGroupID:(NSString *)groupID;

/**
 *  添加自定义图层 包括图片 文本 面标注物图层
 *
 *  @param layer 地图可添加层对象
 */
- (void)addLayer:(FMKLayer *)layer;

/**
 *  删除图层
 *
 *  @param layer 地图可删除层对象
 */
- (void)removeLayer:(FMKLayer *)layer;

/**
 *  通过层标识获取层管理对象
 *
 *  @param tag 图层的唯一标识，由用户创建自定义图层时自定义tag，也可不设置
 *
 *  @return 返回层对象
 */
- (FMKLayer *)layerByTag:(NSInteger)tag;

/**
 *  删除所有图片标注层
 */
- (void)removeAllImageLayer;

/**
 删除所有的自定义文本标注物图层
 */
- (void)removeAllTextLayer;

/**
 删除所有的自定义面标注物图层
 */
- (void)removeAllPolygonLayer;

@end
