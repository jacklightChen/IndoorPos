//
//  BRTBLEEnvironment.h
//  BLEProject
//
//  Created by thomasho on 16/6/17.
//  Copyright © 2016年 thomasho. All rights reserved.
//

#import <Foundation/Foundation.h>


/**
    定位环境设置类
 */
@interface BRTBLEEnvironment : NSObject


/**
 设置定位数据自定义目录，需目录可写入。(有默认值)

 @param dir 自定义目录
 */
+ (void)setRootDirectoryForFiles:(NSString *)dir;


/**
 获取定位目录

 @return 目录路径
 */
+ (NSString *)getRootDirectoryForFiles;


/**
 定位SDK版本

 @return 版本号
 */
+ (NSString *)getSDKVersion;


/**
 * 修改默认请求定位权限，默认请求always定位权限
 *
 * 请在Info.plist添加always定位描述说明：NSLocationAlwaysAndWhenInUsageDescription、NSLocationAlwaysUsageDescription和NSLocationWhenInUseUsageDescription，（填写描述如：用于室内地图导航）
 *
 * @param whenInUse 是否仅使用时期间定位权限
 */
+ (void)setRequestWhenInUseAuthorization:(BOOL)whenInUse;


/**
 * 获取当前定位权限请求模式
 *
 * @return @YES 仅在使用期间 @NO 一直需要
 */
+ (BOOL)isWhenInUseAuthorization;
@end
