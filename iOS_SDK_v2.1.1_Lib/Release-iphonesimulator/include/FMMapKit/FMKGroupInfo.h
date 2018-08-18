//
//  FMKLayerGroup.h
//  FMMapKit
//
//  Created by FengMap on 15/7/20.
//  Copyright (c) 2015年 FengMap. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 *  地图的楼层信息
 */
@interface FMKGroupInfo : NSObject

///楼层ID
@property (nonatomic,copy) NSString* groupID;

///楼层名称
@property (nonatomic,copy) NSString* name;

///楼层别名
@property (nonatomic,copy) NSString* alias;

///楼层高度
@property (nonatomic,assign) float   height;

///楼层描述
@property (nonatomic,copy) NSString* desc;


@end
