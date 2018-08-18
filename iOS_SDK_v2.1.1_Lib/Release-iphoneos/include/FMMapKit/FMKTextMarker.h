//
//  FMKTexter.h
//  FMMapKit
//
//  Created by FengMap on 15/6/23.
//  Copyright (c) 2015年 FengMap. All rights reserved.
//

#import "FMKNode.h"

/**
 *  文本位于地图上的位置
 */
typedef NS_ENUM(NSInteger, FMKTextOffsetMode){
    /**
     *  位于模型之上
     */
    FMKTextMarker_MODELTOP=0,
    /**
     *  位于地面之上
     */
    FMKTextMarker_OVEREXTENT,
    
    /**
     *  用户自定义
     */
    FMKTextMarker_USERDEFINE
};


/**
 自定义文本标注物
 */
@interface FMKTextMarker : FMKNode

/**
 *  初始化文本标注物
 *
 *  @param content 文本内容
 *  @param coord   文本所在地图位置
 *
 *  @return 文本标注物对象
 */
- (instancetype)initWithTextContent:(NSString *)content coord:(FMKMapPoint)coord;

///文本标注物地图位置
@property (nonatomic,assign) FMKMapPoint mapPoint;

///文字大小
@property (nonatomic,assign) CGFloat     fontSize;

///文本内容
@property (nonatomic,copy)   NSString*  content;

///文本标注物的偏移模式
@property (nonatomic,assign) FMKTextOffsetMode offsetMode;

///设置文本的偏移量（只在偏移模式为用户自定义时有效）
@property (nonatomic,assign) CGFloat offset;

///选中属性
@property (nonatomic,assign) BOOL selected;

///文本标注物的颜色
@property (nonatomic,strong) UIColor* textColor;

@end
