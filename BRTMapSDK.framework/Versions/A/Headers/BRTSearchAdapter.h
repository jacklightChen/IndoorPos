//
//  BRTSearchAdapter.h
//  MapProject
//
//  Created by thomasho on 18/5/26.
//  Copyright © 2018年 thomasho. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>
#import "BRTPoi.h"

@interface BRTSearchAdapter : NSObject


/**
 初始化建筑搜索类

 @param buildingID 建筑ID
 @return 搜索类
 */
- (id)initWithBuildingID:(NSString *)buildingID;

/**
 初始化<=范围(米)去重名搜索类

 @param buildingID 建筑ID
 @param threshold 去除阀值(米)内重复名称的数据
 @return 搜索类
 */
- (id)initWithBuildingID:(NSString *)buildingID distinct:(double)threshold;


/**
 根据自定sql检索POI名称

 @param sql sql语句
 @return POI数组
 */
- (NSArray<BRTPoi *> *)querySql:(NSString *)sql;

/**
 根据关键字模糊检索所有楼层POI名称

 @param searchText 关键字
 @return POI数组
 */
- (NSArray<BRTPoi *> *)queryPoi:(NSString *)searchText;

/**
 根据关键字模糊和楼层检索POI名称

 @param name 检索关键字
 @param floor 楼层
 @return POI数组
 */
- (NSArray<BRTPoi *> *)queryPoi:(NSString *)name andFloor:(int)floor;


/**
 根据类别ID检索所有楼层POI

 @param cids 类别ID；多个以,隔开
 @return POI数组
 */
- (NSArray<BRTPoi *> *)queryPoiByCategoryID:(NSString *)cids;

/**
 根据类别ID和楼层检索POI

 @param cids 类别ID；多个以,隔开
 @param floor 楼层
 @return POI数组
 */
- (NSArray<BRTPoi *> *)queryPoiByCategoryID:(NSString *)cids andFloor:(int)floor;


/**
 搜索point半径约radius范围内floor楼层的poi

 @param point 中心点
 @param radius 半径
 @param floor 楼层，如：-1，1
 @return POI数组，由近及远排序
 */
- (NSArray<BRTPoi *> *)queryPoiByCenter:(CLLocationCoordinate2D)point Radius:(double) radius Floor:(int) floor;
@end
