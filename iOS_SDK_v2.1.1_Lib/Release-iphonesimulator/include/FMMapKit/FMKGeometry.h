//
//  FMGeometry.h
//  FMMapKit
//
//  Created by FengMap on 15/4/28.
//  Copyright (c) 2015年 FengMap. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreGraphics/CGGeometry.h>

static const double kFMKCoordCompareLimitValue = 1e-3;

/**
 *	蜂鸟视图点,
 *	该点为地图数据点，
 *	通过地图数据取得
 */
typedef double  FMKDegrees;
typedef int     FMKMapGroupID;

///蜂鸟投影坐标点
typedef struct FMKMapPoint
{
    FMKDegrees x;
    FMKDegrees y;
}FMKMapPoint;

inline static FMKMapPoint FMKMapPointMake(FMKDegrees x,FMKDegrees y)
{
    FMKMapPoint coord;
    coord.x = x;
    coord.y = y;
    return coord;
}

inline static const FMKMapPoint FMKMapPointZero(void)
{
    return FMKMapPointMake(0, 0);
}

inline static NSString* NSStringFromFMKMapPoint(FMKMapPoint mapPoint)
{
    return [NSString stringWithFormat:@"%lf %lf",mapPoint.x,mapPoint.y];
}

/**
 *	fengmap SDK三维数据结构
 */
typedef struct FMKMap3DPoint
{
	FMKDegrees x;
	FMKDegrees y;
	FMKDegrees z;
}FMKMap3DPoint;

inline static FMKMap3DPoint FMKMap3DPointMake(FMKDegrees x, FMKDegrees y, FMKDegrees z)
{
	FMKMap3DPoint point;
	point.x = x;
	point.y = y;
	point.z = z;
	return point;
}

inline static FMKMap3DPoint FMKMap3DPointZero()
{
	return FMKMap3DPointMake(0, 0, 0);
}

inline static NSString *NSStringFromFMKMap3DPoint(FMKMap3DPoint point)
{
	return [NSString stringWithFormat:@"%lf %lf %lf",point.x, point.y, point.z];
}

/**
 蜂鸟地理楼层坐标
 */
typedef struct FMKGeoCoord
{    
    FMKMapGroupID  groupID;        //楼层
    FMKMapPoint    mapPoint;   //投影坐标
}FMKGeoCoord;


/**
 地图坐标构建函数

 @param groupID 楼层id
 @param mapPoint 地图坐标
 @return 地图坐标
 */
inline static FMKGeoCoord FMKGeoCoordMake(FMKMapGroupID groupID,FMKMapPoint mapPoint)
{
    FMKGeoCoord geoCoord;
    geoCoord.mapPoint  = mapPoint;
    geoCoord.groupID   = groupID;
    return geoCoord;
}

/**
 地图坐标归零

 @return 归零结果
 */
inline static const FMKGeoCoord FMKGeoCoordZero(void)
{
    return FMKGeoCoordMake(0, FMKMapPointZero());
}


/**
 地图坐标字符串构建函数

 @param geoCoord 地图坐标
 @return 字符串
 */
inline static NSString* NSStringFromFMKGeoCoord(FMKGeoCoord geoCoord)
{
    return [NSString stringWithFormat:@"%d %lf %lf",geoCoord.groupID,geoCoord.mapPoint.x,geoCoord.mapPoint.y];
}

/**
 地图缩放范围定义 注意与地图缩放级别范围区别
 */
typedef struct FMKMapScaleRange
{
	float min;
	float max;
	
}FMKMapScaleRange;

inline static FMKMapScaleRange FMKMapScaleRangeMake(float min, float max)
{
	FMKMapScaleRange range;
	range.max = max;
	range.min = min;
	return range;
}

inline static NSString* NSStringFromFMKMapScaleRange(FMKMapScaleRange range)
{
	return [NSString stringWithFormat:@"%lf  %lf",range.min, range.max];
}

/**
 地图缩放级别范围定义 注意与地图缩放范围区别
 */
typedef struct FMKMapZoomLevelRange
{
	int min;
	int max;
}FMKMapZoomLevelRange;

/**
 地图缩放级别范围构建函数

 @param min 最小值
 @param max 最大值
 @return 范围
 */
inline static FMKMapZoomLevelRange FMKMapZoomLevelRangeMake(int min, int max)
{
	FMKMapZoomLevelRange range;
	range.max = max;
	range.min = min;
	return range;
}

/**
 地图缩放级别范围字符串构建

 @param range 缩放范围
 @return 字符串
 */
inline static NSString* NSStringFromFMKMapZoomLevelRange(FMKMapZoomLevelRange range)
{
	return [NSString stringWithFormat:@"min:%d  max:%d",range.min, range.max];
}

/**
 FMKMapPoint比较函数

 @param mapPoint1 FMKMapPoint1
 @param mapPoint2 FMKMapPoint2
 @return 比较结果，若相同则返回true
 */
FOUNDATION_STATIC_INLINE bool FMKMapPointEqualToMapPoint(FMKMapPoint mapPoint1, FMKMapPoint mapPoint2) {
    return  (fabs(mapPoint1.x - mapPoint2.x) < kFMKCoordCompareLimitValue) &&
            ((fabs(mapPoint1.y - mapPoint2.y) < kFMKCoordCompareLimitValue));
}

/**
 FMKGeoCoord比较函数

 @param coord1 FMKGeoCoord1
 @param coord2 FMKGeoCoord2
 @return 比较结果，若两者相同则返true
 */
FOUNDATION_STATIC_INLINE bool FMKGeoCoordEqualToCoord(FMKGeoCoord coord1, FMKGeoCoord coord2) {
    return  (coord1.groupID == coord2.groupID) &&
            FMKMapPointEqualToMapPoint(coord1.mapPoint, coord2.mapPoint);
}


/**
 地图坐标格式化
 */
@interface NSValue (FMKValue)

/**
 地图坐标对象化

 @param mapPoint 地图坐标点
 @return 对象化
 */
+ (NSValue *)valueWithFMKMapPoint:(FMKMapPoint)mapPoint;

/**
 地图坐标对象化

 @param geoCoord 地图坐标
 @return 对象化
 */
+ (NSValue *)valueWithFMKGeoCoord:(FMKGeoCoord)geoCoord;

/**
 地图坐标对象化

 @param map3Dpoint 地图坐标
 @return 对象化
 */
+ (NSValue *)valueWithFMKMap3DPoint:(FMKMap3DPoint)map3Dpoint;

/**
 对象转为地图坐标结构

 @return 地图坐标
 */
- (FMKMapPoint)FMKMapPointValue;
/**
 对象转为地图坐标结构
 
 @return 地图坐标
 */
- (FMKGeoCoord)FMKGeoCoordValue;
/**
 对象转为地图坐标结构
 
 @return 地图坐标
 */
- (FMKMap3DPoint)FMKMap3Dpoint;
@end








