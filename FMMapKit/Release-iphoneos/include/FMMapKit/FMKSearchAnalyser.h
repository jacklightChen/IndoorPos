//
//  FMSearchAPI.h
//  FMMapKit
//
//  Created by FengMap on 15/5/15.
//  Copyright (c) 2015年 FengMap. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "FMKGeometry.h"
#import "FMKSearchObj.h"

@protocol FMKSearchAnalyserDelegate;

/**
 * fengmap的查询功能
 * 用于查询fengmap基础数据
 * 基础数据包括model poi等
 */
@interface FMKSearchAnalyser : NSObject

/**
 *  实现了FMKSearchAnalyserDelegate协议的类指针
 */
@property (nonatomic,weak) id<FMKSearchAnalyserDelegate> delegate;

/**
 *  通过mapID初始化查询
 *	通过该接口初始化查询分析对象，地图数据必须通过ID下载保存在默认路径下，否则初始化失败
 *
 *  @param mapID 蜂鸟mapID
 *
 *  @return FMKSearchAnalyser类型对象
 */
- (instancetype)initWithMapID:(NSString *)mapID;

/**
 *  通过地图数据初始化查询
 *
 *  @param dataPath 蜂鸟地图数据路径
 *
 *  @return FMKSearchAnalyser类型对象
 */
- (instancetype)initWithDataPath:(NSString *)dataPath;

/**
 *  获取所有查询结果所在楼层
 */
@property (nonatomic,readonly) NSArray* groupIDs;

/**
 *  获取所有查询结果所在楼层名称
 */
@property (nonatomic,readonly) NSArray* groupNames;

/**
 *  查询所有模型信息
 *
 *  @param groupID 楼层ID
 *
 *  @return 结果返回FMKModelSearchResult对象的数组
 */
- (NSArray *)getAllModelsWithGroupID:(NSString *)groupID;

/**
 *  查询所有公共设施信息
 *
 *  @param groupID 楼层号
 *
 *  @return 结果返回FMKFacilitySearchResult对象的数组
 */
- (NSArray *)getAllFacilityWithGroupID:(NSString *)groupID;

/**
 *  通过FID进行查询
 *	该查询必须设置查询FID
 *  @param searchRequest FMKSearchRequest类型或子类的请求对象
 */
- (void)executeFMKSearchRequestByFID:(FMKSearchRequest *)searchRequest;

/**
 *  通过关键字进行查询
 *	该查询必须设置查询关键字
 *  @param searchRequest FMKSearchRequest类型或子类的请求对象
 *  @param caseSensitive 是否开启大小写敏感
 */
- (void)executeFMKSearchRequestByKeyWords:(FMKSearchRequest *)searchRequest caseSensitive:(BOOL)caseSensitive;
/**
 *  通过关键字进行查询
 *	该查询必须设置查询关键字
 *  @param searchRequest FMKSearchRequest类型或子类的请求对象
 */
- (void)executeFMKSearchRequestByKeyWords:(FMKSearchRequest *)searchRequest;

/**
 *  通过类型进行查询
 *	该查询必须设置查询类型
 *  @param searchRequest FMKSearchRequest类型或子类的请求对象
 */
- (void)executeFMKSearchRequestByType:(FMKSearchRequest *)searchRequest;

/**
 点周边查询
 该查询必须设置查询半径和查询中心点坐标
 @param searchRequest 查询请求
 */
- (void)executeFMKSearchRequestByRadius:(FMKSearchRequest *)searchRequest;

/**
 *  根据范围查询模型
 *
 *  @param request 查询请求
 */
- (void)executeFMKSearchRequestByMapPoints:(FMKExternalModelSearchRequest *)request;


@end

@class FMKModelSearchRequest;
@class FMKFacilitySearchRequest;

/**
 查询回调方法
 */
@protocol FMKSearchAnalyserDelegate <NSObject>

@optional

/**
 *  查询模型结果返回
 *
 *  @param request     模型查询请求
 *  @param resultArray 模型查询结果，数组中为FMKModelSearchResult型对象
 *	@param distances   点周边查询结果与目标点距离
 */
- (void)onModelSearchDone:(FMKModelSearchRequest *)request result:(NSArray *)resultArray distances:(NSArray *)distances;

/**
 *  查询公共设施结果返回
 *
 *  @param request     公共设施查询请求
 *  @param resultArray 公共设施查询结果，数组中为FMKFacilitySearchResult型对象
 *	@param distances   点周边查询结果与目标点距离
 */
- (void)onFacilitySearchDone:(FMKFacilitySearchRequest *)request result:(NSArray *)resultArray distances:(NSArray *)distances;


/**
 查询外部模型返回回调方法

 @param request 外部模型查询请求
 @param resultArray 外部模型查询结果
 @param distances 查询结果距离与查询中心点距离
 */
- (void)onExternalModelSearchDone:(FMKExternalModelSearchRequest *)request result:(NSArray *)resultArray distances:(NSArray *)distances;
@end


