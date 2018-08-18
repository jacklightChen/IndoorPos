//
//  BRTBuilding.h
//  BRTMapProject
//
//  Created by thomasho on 2018/4/13.
//  Copyright © 2018年 o2o. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef struct offsetSize {
    double x;
    double y;
} OffsetSize;

/**
 * 建筑类，表示整栋建筑的信息
 */
@interface BRTBuilding : NSObject

/**
 *  建筑所在城市ID
 */
@property (nonatomic, strong) NSString *cityID;

/**
 * 建筑ID
 */
@property (nonatomic, strong) NSString *buildingID;

/**
 * 建筑名称
 */
@property (nonatomic, strong) NSString *name;

/**
 * 建筑地址
 */
@property (nonatomic, strong) NSString *address;

/**
 * 建筑经度
 */
@property (readonly) double longitude;

/**
 * 建筑纬度
 */
@property (readonly) double latitude;

/**
 *  地图初始偏转角度
 */
@property (readonly) double initAngle;

/**
 *  导航服务地址
 */
@property (nonatomic, strong) NSString *routeURL;

/**
 *  路径版本
 */
@property (nonatomic, strong) NSString *routeVersion;

/**
 *  导航偏移量
 */
@property (readonly) OffsetSize offset;

/**
 * 建筑状态
 */
@property (assign) int status;

/**
 * 建筑类型
 */
@property (assign) int type;

/**
 * 是否支持瓦片
 */
@property (assign) BOOL supportURL;

/**
 * 建筑瓦片地址
 */
@property (nonatomic, strong) NSString *mapURL;

/**
 * 建筑区域数据
 */
@property (nonatomic, strong) NSString *uuid;


/**
 *  建筑类的实例化方法
 *
 *  @param cityID     建筑所在城市ID
 *  @param buildingID 建筑ID
 *  @param name       建筑名称
 *  @param lon        建筑经度
 *  @param lat        建筑纬度
 *  @param address    建筑地址
 *  @param initAngle  地图初始偏转角度
 *  @param url        导航服务地址
 *  @param offset     导航偏移量
 *
 *  @return 建筑类实例
 */
- (id)initWithCityID:(NSString *)cityID BuildingID:(NSString *)buildingID Name:(NSString *)name Lon:(double)lon Lat:(double)lat Address:(NSString *)address InitAngle:(double)initAngle RouteURL:(NSString *)url Offset:(OffsetSize)offset;

/**
 *  从Json数据中解析Building信息
 *
 *  @param buildingObject 建筑信息的JSON表示
 *
 *  @return 建筑类实例
 */
+ (BRTBuilding *)parseBuildingObject:(NSDictionary *)buildingObject;

/**
 *   构建建筑信息的JSON表示
 *
 *  @param building 建筑类实例
 *
 *  @return 建筑信息的JSON表示
 */
+ (NSDictionary *)buildBuildingObject:(BRTBuilding *)building;

@end

