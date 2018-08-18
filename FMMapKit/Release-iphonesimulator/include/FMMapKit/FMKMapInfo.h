//
//  FMKSceneInfo.h
//  FMMapKit
//
//  Created by FengMap on 15/7/8.
//  Copyright (c) 2015年 FengMap. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "FMKGeometry.h"

/**
 *  地图信息
 */
@interface FMKMapInfo : NSObject
/**
 *  地图ID
 */
@property (nonatomic, copy)      NSString*       ID;
/**
 地图数据版本号
 */
@property (nonatomic, copy)		 NSString *		 fmapVersion;
/**
 *  所有楼层id
 */
@property (nonatomic, strong)    NSArray*        groupIDs;
/**
 * 所有楼层信息
 */
@property (nonatomic, strong)    NSArray*        groupInfos;

/**
 * 当前地图名
 */
@property (nonatomic, copy)      NSString*       name;

/**
 *  地图最小x坐标，地理坐标
 */
@property (nonatomic, assign)    FMKDegrees      minX;
/**
 *  地图最小y坐标，地理坐标
 */
@property (nonatomic, assign)    FMKDegrees      minY;
/**
 *  地图最大x坐标，地理坐标
 */
@property (nonatomic, assign)    FMKDegrees      maxX;
/**
 *  地图最大y坐标，地理坐标
 */
@property (nonatomic, assign)    FMKDegrees      maxY;
/**
 *  楼层高度
 */
@property (nonatomic, assign)    FMKDegrees      height;
/**
 *  地图中心坐标
 */
@property (nonatomic, assign)    FMKMapPoint     center;

@end
