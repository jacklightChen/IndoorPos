//
//  BRTPoi.h
//  BRTMapProject
//
//  Created by BrightBeacon on 18/5/2.
//  Copyright (c) 2018年 BrightBeacon. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <Mapbox/Mapbox.h>
#import <BRTMapData/BRTLocalPoint.h>

/**
 *  POI所在层，当前按层来分类：房间层（ROOM）、资产层（ASSET）、公共设施层（FACILITY）
 */
typedef NS_ENUM(NSUInteger, POI_LAYER) {
    POI_FLOOR = 1,
    POI_ROOM = 2,
    POI_ASSET = 3,
    POI_FACILITY = 4,
    POI_LABEL = 5,
};

/**
 *  POI类：用于表示POI相关数据，主要包含POI地理信息，及相应POI ID
 */
@interface BRTPoi : NSObject

/**
 *  POI地理ID
 */
@property (nonatomic, readonly) NSString *geoID;

/**
 *  POI ID
 */
@property (nonatomic, readonly) NSString *poiID;

/**
 *  POI所在建筑ID
 */
@property (nonatomic, readonly) NSString *buildingID;

/**
 *  POI所在楼层ID
 */
@property (nonatomic, readonly) NSString *floorID;

/**
 *  POI所在楼层号
 */
@property (nonatomic, readonly) int floorNumber;

/**
 *  POI名称
 */
@property (nonatomic, readonly) NSString *name;

/**
 *  通过MapView获取的POI区域几何数据：MGLPolygon/MGLMultiPolygon
 */
@property (nonatomic, readwrite) MGLShape* geometry;

/**
 *  POI锚点
 */
@property (nonatomic, readonly) BRTLocalPoint *labelPoint;

/**
 *  POI分类类型ID
 */
@property (nonatomic, readonly) NSInteger categoryID;

/**
 *  POI所在层
 */
@property (nonatomic, readonly) POI_LAYER layer;

/**
 *  POI是否拉伸
 */
@property (nonatomic, readonly) BOOL extrusion;

/**
 *  创建POI实例的静态方法
 *
 *  @param attr 属性键值对
 *
 *  @return POI实例
 */
+ (BRTPoi *)poiWithAttributes:(NSDictionary *)attr;

@end
