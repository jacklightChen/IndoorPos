//
//  FMKNaviResult.h
//  FMMapKit
//
//  Created by FengMap on 15/9/2.
//  Copyright (c) 2015年 FengMap. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 *  路径分析结果数据，该结果以楼层为单位
 */
@interface FMKNaviResult : NSObject

/**
 * 路径分析结果所在楼层ID
 */
@property (nonatomic,copy)      NSString* groupID;
/**
 *  该路径规划结果路径长度
 */
@property (nonatomic,assign)    double    length;

/**
 *  该楼层上路径分析的结果点,数组中为FMKMapPoint型的NSValue数据
 */
@property (nonatomic,strong)    NSArray*  pointArray;

@end

