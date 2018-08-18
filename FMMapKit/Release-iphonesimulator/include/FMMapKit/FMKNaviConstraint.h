//
//  FMKNaviConstraint.h
//  FMMapKit
//
//  Created by fengmap on 16/7/13.
//  Copyright © 2016年 Fengmap. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "FMKGeometry.h"


/**
 路径约束计算结果类型

 - FMKCONSTRAINT_SUCCESS: 成功
 - FMKCONSTRAINT_FAILED_NO_NAVIDATAS: 失败 无数据
 - FMKCONSTRAINT_FAILED_NO_CONSTRAINT: 失败 无法约束
 - FMKCONSTRAINT_ERROR: 失败 未知错误
 */
typedef NS_ENUM(NSInteger, FMKConstraintType)
{
    ///成功
	FMKCONSTRAINT_SUCCESS = 1,
    ///失败 无数据
	FMKCONSTRAINT_FAILED_NO_NAVIDATAS,
    ///失败 无法约束
	FMKCONSTRAINT_FAILED_NO_CONSTRAINT,
    ///失败 未知错误
	FMKCONSTRAINT_ERROR
};


/**
 路径约束计算结果
 */
typedef struct FMKNaviConstraintResult
{
	///返回结果类型
	FMKConstraintType type;
	
	/**
	 返回结果下标
	 
	 该下标为路径约束结果点坐标在点集合中所在线段的起点下标
	 */
	int index;
	
	/**
	 定位点与点集合构成路线的偏移量
	 */
	float distance;
	
	/**
	 路径约束计算结果
	 */
	FMKMapPoint mapPoint;
	
}FMKNaviConstraintResult;


@interface FMKNaviConstraint : NSObject
/**
 *  初始化约束
 *
 *  @param mapPath 地图数据路径
 *
 *  @return 约束对象
 */
- (instancetype)initWithMapPath:(NSString *)mapPath;

/**
 *  更新导航约束所需参数
 *
 *	在进行导航约束计算前都需要更新所在楼层的导航约束数据
 *
 *  @param mapPoints 本楼层路径分析结果
 *  @param groupID   所在楼层ID
 */
- (void)updateNaviConstraintDataWithPoints:(NSArray *)mapPoints
						 groupID:(NSString *)groupID;

/**
 *  导航约束点计算
 *	导航约束可将定位漂移点约束到特定路线上，在使用该方法前需更新一次当前定位楼层的导航数据
 *
 *  @param lastMapPoint    上一个定位点坐标
 *  @param currentMapPoint 当前定位坐标
 *
 *  @return 导航约束结果
 */
- (FMKNaviConstraintResult)naviConstraintByLastPoint:(FMKMapPoint)lastMapPoint currentMapPoint:(FMKMapPoint)currentMapPoint;


/**
 路径约束计算
 调用此方法可以计算定位点与地图上自有路径最近的投影坐标点，并计算偏移距离等参数

 @param lastMapPoint 上一次定位坐标点
 @param currentMapPoint 当前定位坐标点
 @param groupID 当前定位所在楼层
 @return 路径约束结果
 */
- (FMKNaviConstraintResult)pathContraintByLastPoint:(FMKMapPoint)lastMapPoint currentMapPoint:(FMKMapPoint)currentMapPoint groupID:(NSString *)groupID;

@end
