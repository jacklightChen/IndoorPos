//
//  FMKMapSDK.h
//  FMMapKit
//
//  Created by FengMap on 15/4/29.
//  Copyright (c) 2015年 FengMap. All rights reserved.
//
#import <Foundation/Foundation.h>

/**
 *	获取当前地图SDK的版本号
 *	return  返回当前SDK的版本号
 */

FOUNDATION_STATIC_INLINE NSString * FMKGetMapSDKVersion()
{
	return @"2.1.1";
}

@interface FMKMapSDK : NSObject

//启用SDK,配置本地文件
+ (instancetype)shareSDK;

/**
 使用SDK前需要验证key

 @param key key
 */
- (void)setKey:(NSString *)key;

@end
