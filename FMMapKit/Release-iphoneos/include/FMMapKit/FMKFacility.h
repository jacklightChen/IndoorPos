//
//  FMKPOI.h
//  FMMapKit
//
//  Created by FengMap on 15/6/24.
//  Copyright (c) 2015年 FengMap. All rights reserved.
//

#import "FMKNode.h"

/**
 *  地图公共设施节点，不支持用户自定义创建
 */
@interface FMKFacility : FMKNode

/**
 *  所在楼层ID
 */
@property (readonly)   NSString*   groupID;
/**
 *  公共设施类型
 */
@property (readonly)   NSString*   type;
///公共设施名称 可能为空
@property (nonatomic, readonly) NSString *name;
///公共设施eid  该ID表示该公共设施在楼层上的编码 编码从1开始
@property (nonatomic, readonly) int eid;
///公共设施英文名称 可能为空
@property (nonatomic, readonly) NSString *ename;
/**
 *  透明度
 */
@property (nonatomic, assign)    float   alpha;
/**
 *  选中状态
 */
@property (nonatomic, assign)    BOOL    selected;


@end
