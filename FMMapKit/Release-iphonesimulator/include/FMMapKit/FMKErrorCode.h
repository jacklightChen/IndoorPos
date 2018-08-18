//
//  FMKErrorCode.h
//  FMMapKit2.0
//
//  Created by smallLabel on 2017/7/17.
//  Copyright © 2017年 Fengmap. All rights reserved.
//

#import <Foundation/Foundation.h>


/**
 Fengmap错误码
 */
typedef NS_ENUM(NSInteger, FMKErrorCodeType) {
    ///网络错误
    FMKErrorCodeType_NET_ERROR               = 1,
    ///key错误
    FMKErrorCodeType_KEY_ERROR               = 2,
    ///mapID错误
    FMKErrorCodeType_MAPID_ERROR             = 3,
    /// 没有权限访问数据
    FMKErrorCodeType_NO_PERMISSION           = 4,
    ///key与bundleID不匹配
    FMKErrorCodeType_KEY_NO_MATCH_BUNDLEID   = 5,
    ///地图数据解析失败
    FMKErrorCodeType_MAPDATA_PARSE_ERROR = 6,
    ///地图数据下载失败
    FMKErrorCodeType_DOWNLOAD_ERROR      = 7,
    ///没有版本号错误
    FMKErrorCodeType_NO_VERSION_INFO     = 8,
    ///地图文件路径错误
    FMKErrorCodeType_MAP_DATA_DIRECTORY_ERROR = 9,
    ///版本号解析失败
    FMKErrorCodeType_MAP_VERSION_PARSE_ERROR = 10,
    ///未知错误
    FMKErrorCodeType_UNKNOWN_ERROR       = 11
};

@interface FMKErrorCode : NSObject

@end
