//
//  FMKSearchObj.h
//  FMMapKit
//
//  Created by FengMap on 15/8/20.
//  Copyright (c) 2015年 FengMap. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "FMKGeometry.h"

@interface FMKSearchRequest : NSObject
@end

@interface FMKSearchResult : NSObject
@end

#pragma model
/**
 *  模型查询请求体
 */
@interface FMKModelSearchRequest : FMKSearchRequest

///所有查询分析都需设置分析楼层，否则默认全部楼层查询
@property (nonatomic,strong) NSArray*  groupIDs;

///查询关键字，多个关键字用“|”分割，类型查询必须设置该参数
@property (nonatomic,copy)   NSString* keywords;

///查询的模型FID，FID查询必须设置该参数
@property (nonatomic,copy)   NSString* FID;

///查询模型类型，类型查询必须设置该参数
@property (nonatomic,copy)   NSString* type;

///点周边查询半径，点周边查询必须设置该参数
@property (nonatomic, assign) CGFloat radius;

///点周边查询中心点，点周边查询必须设置该参数
@property (nonatomic, assign) FMKGeoCoord coord;

@end

/**
 *  模型查询结果
 */
@interface FMKModelSearchResult : FMKSearchResult

///查询结果所在楼层ID
@property (nonatomic,copy)      NSString*   groupID;

///查询结果所在楼层名称
@property (nonatomic,copy)      NSString*   groupName;

///查询结果模型FID FID为全地图唯一编码
@property (nonatomic,copy)      NSString*   FID;

///查询结果名称
@property (nonatomic,copy)      NSString*   name;

///查询结果英文名称
@property (nonatomic,copy)      NSString*   ename;

///查询结果类型
@property (nonatomic,copy)      NSString*   type;

///查询结果中心点地理坐标，该坐标为FengMap地图坐标
@property (nonatomic,assign)    FMKMapPoint centerCoord;

///模型高度
@property (nonatomic,assign)	float       height;

///模型eid  该ID为模型在当前层的编号 从1开始
@property (nonatomic) int eid;

@end

#pragma facility

/**
 *  公共设施查询请求体
 */
@interface FMKFacilitySearchRequest : FMKSearchRequest

///所有查询分析都需设置分析楼层，否则默认全部楼层查询
@property (nonatomic, strong) NSArray*  groupIDs;

///公共设施类型，多个关键字用“|”分割 执行类型查询时必须设置该参数
@property (nonatomic, copy)   NSString* type;

///点周边查询半径 执行点周边查询时必须设置该参数
@property (nonatomic, assign) CGFloat radius;

///点周边查询中心点 执行点周边查询时必须设置该参数
@property (nonatomic, assign) FMKGeoCoord coord;

@end

/**
 *  公共设施查询结果
 */
@interface FMKFacilitySearchResult : FMKSearchResult

///查询结果所在楼层ID
@property (nonatomic, copy)      NSString*   groupID;      

///查询结果所在楼层名称
@property (nonatomic, copy)      NSString*   groupName;

///查询结果名称
@property (nonatomic, copy)      NSString*   name;

///查询结果英文名称
@property (nonatomic, copy)      NSString*   ename;

///查询结果设施类型
@property (nonatomic, copy)      NSString*   type;

///查询结果设施描述
@property (nonatomic, copy)      NSString*   desc;

///查询结果标识码 该标识码为层唯一 从1开始
@property (nonatomic) int eid;

///查询结果中心点地理坐标，FengMap地图坐标
@property (nonatomic, assign)    FMKMapPoint centerCoord;

@end


/**
 3D模型信息查询请求体
 */
@interface FMKExternalModelSearchRequest : FMKSearchRequest
///要查询的楼层id集合，若不设置该参数则默认为全楼层查询
@property (nonatomic, strong)NSArray * groupIDs;
///fid查询必要参数
@property (nonatomic, copy)NSString * fid;
///关键字查询必要参数
@property (nonatomic, copy)NSString * keywords;
///类型查询必要参数
@property (nonatomic, copy)NSString * type;
///通过范围查询模型的必要参数
@property (nonatomic, strong) NSArray <NSValue *>* mapPoints;

@end

/**
 3D模型信息查询结果
 */
@interface FMKExternalModelSearchResult : FMKSearchResult
///模型所在楼层id
@property (nonatomic, copy)      NSString*   groupID;      
///模型所在楼层名称
@property (nonatomic, copy)      NSString*   groupName;
///模型在当前楼层的eid,每个楼层都从1开始编码
@property (nonatomic, copy)      NSString*   eid;          
///模型名称
@property (nonatomic, copy)      NSString*   name;         
///模型英文名称
@property (nonatomic, copy)      NSString*   ename;        
///模型类型
@property (nonatomic, copy)      NSString*   type;         
///模型描述
@property (nonatomic, copy)      NSString*   desc;         
///模型的唯一编码
@property (nonatomic, copy)      NSString*   fid;
///模型中心点地理坐标
@property (nonatomic, assign)    FMKMapPoint centerCoord;  

@end
