//
//  FMKSegment.h
//  FMMapKit
//
//  Created by FengMap on 15/9/2.
//  Copyright (c) 2015年 FengMap. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "FMKNode.h"

@class FMKNaviResult;
/**
 * 地图线段，用于添加线
 */
@interface FMKSegment : FMKNode
/**
 *  地图线段类，该类现不支持直接画到地图上
 *  可将这些点组装到数组中通过FMKLineMarker画线
 *
 *  @param groupID    楼层组id
 *  @param pointArray 该层上的点
 *
 *  @return 返回的对象用于地图上线的创建
 */
- (instancetype)initWithGroupID:(NSString *)groupID
                     pointArray:(NSArray *)pointArray;

/**
 地图线段数据类

 @param groupID 楼层ID
 @param pointArray 三维点集合
 @return 线段数据对象
 */
- (instancetype)initWithGroupID:(NSString *)groupID
        threeDimensionaPointArr:(NSArray *)pointArray;

/**
 *  楼层id
 */
@property (nonatomic,strong) NSString*  groupID;

/**
 *  长度
 */
@property (nonatomic,assign) double     length;

/**
 *  在该楼层上的点，数组中为FMKMapPoint型的NSValue对象
 */
@property (nonatomic,strong) NSArray*   pointArray;

@end
