//
//  FMKModelNode.h
//  FMMapKit
//
//  Created by FengMap on 15/5/22.
//  Copyright (c) 2015年 FengMap. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "FMKNode.h"

/**
 * 地图模型节点，不支持创建
 */
@interface FMKModel : FMKNode

///模型所在的楼层ID
@property (nonatomic, readonly)     NSString*   groupID;

///中文名
@property (nonatomic, readonly)     NSString*   title;

///英文名
@property (nonatomic, readonly)     NSString*   englishTitle;

///FID 模型的唯一标识
@property (nonatomic, readonly)     NSString*   FID;

///type 模型type
@property (nonatomic, readonly)     NSString*   type;

///模型屏幕坐标中心点
@property (nonatomic, readonly)     CGPoint     centerPoint;

///模型高度
@property (nonatomic, readonly)		CGFloat		 height;

/**
 *  颜色设置 模型的显示颜色
 */
@property (nonatomic, copy)      UIColor*    color;
/**
 *  边线颜色
 */
@property (nonatomic, copy)      UIColor*    lineColor;
/**
 *  选中状态
 *
 *	选中状态下模型颜色可通过修改主题设置
 */
@property (nonatomic, assign)    BOOL        selected;
/**
 *  边线宽度
 */
@property (nonatomic, assign)    CGFloat     lineWidth;

/**
 模型透明度
 */
@property (nonatomic, assign)    CGFloat	 alpha;


/**
 *  通过地图数据获取模型的地图中心点
 *
 *  @param mapPath 地图路径
 *
 *  @return 模型中心点
 */
- (FMKGeoCoord)getModelCenterByMapPath:(NSString *)mapPath;

@end
