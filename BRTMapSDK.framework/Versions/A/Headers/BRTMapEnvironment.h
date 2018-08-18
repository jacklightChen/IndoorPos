//
//  BRTMapEnvironment.h
//  mapbox
//
//  Created by thomasho on 2017/12/20.
//  Copyright © 2017年 thomasho. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface BRTMapEnvironment : NSObject


/**
 地图引擎版本
 
 @return 版本号
 */

+ (NSString *)getSDKVersion;

/**
 * 获取地图路径
 *
 * @return 地图资源目录
 */
+ (NSString *)getRootDirectoryForMapFiles;

/**
 * 设置地图资源
 *
 * @param dir 地图资源总目录
 */
+ (void)setRootDirectoryForMapFiles:(NSString *)dir;

/**
 *  获取目标建筑的目录路径
 *
 *  @param buildingID 目标建筑ID
 *
 *  @return 目标建筑的文件路径
 */
+ (NSString *)getBuildingDirectory:(NSString *)buildingID;

/**
 * 设置自定义地图本地化语言(请使用标准本地化描述zh-hans,zh-hant,en等，依赖MapLocalizable.string文件本地化设置)
 
 @param local 设置本地化语言
 */
+ (void)setMapCustomLanguage:(NSString *)local;

/**
 * 获取地图本地化Bundle，默认[NSBundle mainBundle]
 *
 @return 本地化Bundle
 */
+ (NSBundle *)getCustomLanguageBundle;

/**
 *  设置验证License
 *
 *  license 验证license
 *  buildingId 建筑Id
 *  appkey 用户appkey
 */
+ (void)setLicense:(NSString *)license forBuildingId:(NSString *)buildingId appKey:(NSString *)appkey;

@end
