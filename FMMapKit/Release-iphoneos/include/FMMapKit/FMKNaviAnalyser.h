//
//  FMNaviAnalyser.h
//  FMMapKit
//
//  Created by FengMap on 15/6/1.
//  Copyright (c) 2015年 FengMap. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "FMKGeometry.h"

@class FMKNaviPredictionSegment;

/**
 *  路径规划类型
 */
typedef NS_ENUM(NSInteger, FMKNaviModule)
{
    /**
     * 最短
     */
    MODULE_SHORTEST = 1,
    
    /**
     * 最优
     */
    MODULE_BEST = 2,
};

/**
  楼层间路径规划方式优先级
 */
typedef NS_ENUM(NSInteger, FMKRouteCrossGroupPriority)
{
    ///默认直梯优先方式
	FMKROUTE_CGP_DEFAULT = 0,//LIFT > ESCALATOR > STAIR
    ///直梯优先
	FMKROUTE_CGP_LIFTFIRST,
    ///扶梯优先
	FMKROUTE_CGP_ESCALATORFIRST,
    ///楼梯优先
	FMKROUTE_CGP_STAIRFIRST,
    ///仅直梯
	FMKROUTE_CGP_LIFTONLY,
    ///仅扶梯
	FMKROUTE_CGP_ESCALATORONLY,
    ///仅楼梯
	FMKROUTE_CGP_STAIRONLY
};

/**
 路径分析类型设置
 */
typedef struct FMKRouteSetting
{
	/*
	 *	路径经过楼梯优先级选择
	 */
	FMKRouteCrossGroupPriority routeCrossGroupPriority;
	/*
	 *	最短最优路径计算方法选择
	 */
	FMKNaviModule naviModule;
	
}FMKRouteSetting;

/**
 * 路径计算的返回值。
 */
typedef NS_ENUM(int, FMKRouteCalculateResultType)
{
    ///地图数据不存在
    IROUTE_DATA_LOST = -3,    
    ///数据库出错
    IROUTE_DATABASE_ERROR = -2,  
    ///数据错误
    IROUTE_PARAM_ERROR = -1,  
    ///成功
    IROUTE_SUCCESS = 1,               
    ///与数据无关的错误
    IROUTE_FAILURE_NO_FMDBKERNEL = 2, 
    ///失败，起点和终点太近
    IROUTE_FAILURE_TOO_CLOSE = 3, 
    ///失败，没有起点所在层的数据
    IROUTE_FAILURE_NO_START = 4, 
    ///失败，没有终点所在层的数据
    IROUTE_FAILURE_NO_END = 5,   
    ///失败，没有电梯（扶梯）进行跨楼路径规划
    IROUTE_FAILURE_NO_STAIR_FLOORS = 6,
    ///失败，不支持跨楼层导航
    IROUTE_FAILURE_NOTSUPPORT_FLOORS = 7,
    ///不能计算
    IROUTE_FAILED_CANNOT_CALCULATE = 8,  
    ///没有结果
    IROUTE_SUCCESS_NO_RESULT = 9         
};

/*
 *  路径规划分析
 */
@class FMKNaviResult;

@protocol FMKNaviAnalyserDelegate;


/**
 路径分析器
 */
@interface FMKNaviAnalyser : NSObject


/**
 文字导航处理结果 路径规划有结果时有效
 */
@property (nonatomic, readonly) NSArray <FMKNaviPredictionSegment *>* naviDescriptionsData;

/**
 文字导航文字描述 路径规划有结果时有效
 */
@property (nonatomic, readonly) NSArray <NSString *>* naviDescriptions;

/**
 *  通过mapID初始化路径分析
 *	通过该方式初始化路径分析对象时，地图数据必须是通过ID下载得到的，否则会初始化失败
 *  地图数据下载有两种方式：一、通过id加载过地图数据会自动下载；二、使用SDK下载器下载地图数据
 *
 *  @param mapID 地图id
 *
 *  @return 路径分析对象
 */
- (instancetype)initWithMapID:(NSString *)mapID;

/**
 *  通过地图数据路径初始化路径分析
 *
 *  @param dataPath 地图数据路径
 *
 *  @return 路径分析对象
 */
- (instancetype)initWithMapPath:(NSString *)dataPath;

/**
 *  路径规划分析代理
 */
@property (nonatomic,weak)  id<FMKNaviAnalyserDelegate> delegate;

/**
 路径规划分析
 该方法仅计算路算长度，不返回路段结果，也不会生成相应文字描述

 @param start 路径规划起点
 @param end 路径规划终点
 @param routeSetting 路算策略
 @return 路径规划计算结果
 */
- (FMKRouteCalculateResultType)analyseRouteWithStartCoord:(FMKGeoCoord)start
                                                 endCoord:(FMKGeoCoord)end
                                                     type:(FMKRouteSetting)routeSetting;

/**
 路径规划分析
 该方法会生成相应路段文字描述
 @param start 路径规划起点
 @param end 路径规划终点
 @param routeSetting 路算策略
 @param naviResults 路径规划结果，对象为FMKNaviResult型对象
 @return 路径规划计算结果
 */
- (FMKRouteCalculateResultType)analyseRouteWithStartCoord:(FMKGeoCoord)start
                                                      end:(FMKGeoCoord)end
                                                     type:(FMKRouteSetting)routeSetting
                                              routeResult:(NSMutableArray **)naviResults;

@end


/**
 路径规划回调方法
 */
@protocol FMKNaviAnalyserDelegate <NSObject>

@optional

/**
 路径规划成功后相应楼层的点集合，若路径规划有多个楼层，该回调会触发多次

 @param analyser 路径分析器
 @param coords 对应楼层路径规划结果点集合
 @param groupID 楼层id
 */
- (void)analyser:(FMKNaviAnalyser *)analyser naviGeoCoords:(NSArray *)coords inGroup:(NSString *)groupID;

/**
 路径规划成功后对应楼层的路径长度，若路径规划有多个楼层，该回调会触发多次

 @param analyser 路径分析器
 @param length 对应楼层上的路径长度
 @param groupID 楼层id
 */
- (void)analyser:(FMKNaviAnalyser *)analyser groupLength:(double)length inGroup:(NSString *)groupID;

/**
 路径规划结果包含的所有楼层id

 @param analyser 路径分析器
 @param groupIDs 路径规划结果包含的所有楼层id，若为跨层路径规划，该集合可能包含重复楼层id，且 仅包含起点和终点所在楼层id
 */
- (void)analyser:(FMKNaviAnalyser *)analyser groupIDs:(NSArray *)groupIDs;

/**
 路径规划总长度

 @param analyser 路径分析器
 @param totalLength 路径总长度
 */
- (void)analyser:(FMKNaviAnalyser *)analyser totalLength:(double)totalLength;

@end





