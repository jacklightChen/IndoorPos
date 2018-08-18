//
//  BRTFloorInfo.h
//  BRTMapProject
//
//  Created by thomasho on 2018/4/13.
//  Copyright © 2018年 o2o. All rights reserved.
//

#import <Foundation/Foundation.h>
@class BRTBuilding;

/**
 *  地图尺寸,对应地图所示区域实际大小
 */
typedef struct mapsize {
    double x;
    double y;
} MapSize;

/**
 *  地图坐标范围:{xmin, ymin, xmax, ymax}
 */
typedef struct mapextent {
    double xmin;
    double ymin;
    double xmax;
    double ymax;
} MapExtent;

MapExtent BRTMapExtentMake(double xmin, double ymin, double xmax, double ymax);
MapSize BRTMapSizeMake(double x, double y);

/**
 *  地图信息类：用于表示某一层地图的配置信息，包含地图ID、地图尺寸、地图范围、地图偏转角等
 */
@interface BRTFloorInfo : NSObject

/**
 *  所在城市的ID
 */
@property (nonatomic, readonly) NSString *cityID;


/**
 *  所在建筑的ID
 */
@property (nonatomic, readonly) NSString *buildingID;

/**
 *  当前地图的唯一ID，当前与楼层的FloorID一致
 */
@property (nonatomic, readonly) NSString *mapID;

/**
 *  地图尺寸
 */
@property (readonly) MapSize mapSize;

/**
 *  地图范围
 */
@property (readonly) MapExtent mapExtent;

/**
 *  当前楼层名称，如F1、B1
 */
@property (readonly, nonatomic) NSString *floorName;

/**
 *  当前楼层序号,如-1、1
 */
@property (readonly) int floorNumber;

/**
 *  地图X方向放缩比例，当前比例为1
 */
@property (readonly) double scalex;

/**
 *  地图Y方向放缩比例，当前比例为1
 */
@property (readonly) double scaley;

/**
 *  地图信息的实例化方法
 *
 *  @param cityID     城市ID
 *  @param buidlingID 建筑ID
 *  @param mapID      地图ID，与楼层ID相同
 *  @param e          地图范围
 *  @param s          地图尺寸
 *  @param fs         楼层名称
 *  @param fi         楼层序号
 *
 *  @return 地图信息实例
 */
- (id)initWithCityID:(NSString *)cityID BuildingID:(NSString *)buidlingID MapID:(NSString *)mapID Extent:(MapExtent)e Size:(MapSize)s Floor:(NSString *)fs FloorNumber:(int)fi;

/**
 *  解析目标建筑的特定名称的地图信息
 *
 *  @param floor    目标楼层名称
 *  @param building 目标建筑信息
 *
 *  @return 目标楼层地图信息
 */
+ (BRTFloorInfo *)parseMapInfo:(NSString *)floor ForBuilding:(BRTBuilding *)building;

/**
 *  解析目标建筑的所有楼层地图信息
 *
 *  @param infos 建筑楼层信息
 *
 *  @return 目标楼层所有地图信息
 */
+ (NSArray *)parseAllMapInfoObject:(NSArray *)infos;

/**
 *  从一组地图信息中搜索特定楼层的地图信息
 *
 *  @param array 目标地图信息数组
 *  @param floor 目标楼层
 *
 *  @return 目标楼层信息
 */
+ (BRTFloorInfo *)searchMapInfoFromArray:(NSArray *)array Floor:(int)floor;

/**
 *  从一组地图信息中搜索特定楼层的地图信息
 *
 *  @param array 目标地图信息数组
 *  @param floorName 目标楼层名
 *
 *  @return 目标楼层信息
 */
+ (BRTFloorInfo *)searchMapInfoFromArray:(NSArray *)array FloorName:(NSString *)floorName;

/**
 *  解析目标建筑的所有楼层地图信息
 *
 *  @param buildingId 建筑信息
 *
 *  @return 目标楼层所有地图信息
 */
+ (NSArray *)parseAllMapInfo:(NSString *)buildingId;
/**
 *  从目标路径的地图信息文件中解析所有地图信息
 *
 *  @param path 目标地图信息文件
 *
 *  @return 所有地图信息
 */
+ (NSArray *)parseAllMapInfoFromFile:(NSString *)path;

/**
 *  从Json数据中解析MapInfo信息
 *
 *  @param mapInfoObject 地图信息的JSON表示
 *
 *  @return 地图信息实例
 */
+ (BRTFloorInfo *)parseMapInfoObject:(NSDictionary *)mapInfoObject;

/**
 *  构建地图信息的JSON表示
 *
 *  @param mapInfo 地图信息实例
 *
 *  @return 地图信息的JSON表示
 */
+ (NSDictionary *)buildingMapInfoObject:(BRTFloorInfo *)mapInfo;

@end
