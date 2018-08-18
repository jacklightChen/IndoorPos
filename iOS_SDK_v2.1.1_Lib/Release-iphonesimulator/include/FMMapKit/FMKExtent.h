//
//  FMKExtent.h
//  FMMapKit
//
//  Created by fengmap on 15/12/24.
//  Copyright © 2015年 Fengmap. All rights reserved.
//

#import "FMKNode.h"

/**
 楼层底面节点
 地图自有节点，不可自定义创建
 */
@interface FMKExtent : FMKNode

///楼层地面所在楼层ID
@property(nonatomic,readonly)NSString * groupID;

@end
