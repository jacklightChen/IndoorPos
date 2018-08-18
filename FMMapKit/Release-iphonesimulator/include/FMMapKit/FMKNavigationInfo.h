//
//  FMKNavigationInfo.h
//  FMMapKit
//
//  Created by smallLabel on 2017/10/24.
//  Copyright © 2017年 Fengmap. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "FMKGeometry.h"

@class FMKNaviPredictionSegment;

/**
 导航结果信息
 */
@interface FMKNavigationInfo : NSObject

///当前导航位置，若当前导航是真实导航，则此位置为经过纠偏到路线上的位置点
@property (nonatomic) FMKGeoCoord position;
///当前导航朝向，若当前为模拟导航，则此角度为当前点位于路线上的角度，若为真实导航则此角度为传入的角度
@property (nonatomic) CGFloat angle;
///当前导航点与终点剩余距离
@property (nonatomic) CGFloat surplusDistance;
///当前导航点与路线的偏移距离，该参数仅在真实导航状态下有效
@property (nonatomic) CGFloat offsetDistance;
///当前导航点所在路段文本描述
@property (nonatomic, copy) NSString *naviText;
///当前导航点所在路段,该路段对象不是路径规划结果的点集合的两两构造路段
@property (nonatomic, strong) FMKNaviPredictionSegment *segment;

@end
