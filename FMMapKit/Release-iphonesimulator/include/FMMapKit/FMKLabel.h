//
//  FMKLabel.h
//  FMMapKit
//
//  Created by fengmap on 16/3/7.
//  Copyright © 2016年 Fengmap. All rights reserved.
//

#import "FMKNode.h"

/**
 文本标签，地图自有节点 不支持用户自定义创建
 */
@interface FMKLabel : FMKNode
///文本内容
@property (nonatomic, readonly) NSString * text;
///元素eid
@property (nonatomic, readonly) NSInteger eid;
///元素类型
@property (nonatomic, readonly) long type;
///元素高度
@property (nonatomic, readonly) CGFloat height;

@end
