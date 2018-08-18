//
//  FMKThemeDataManager.h
//  FMMapKit
//
//  Created by FengMap on 15/4/30.
//  Copyright (c) 2015年 FengMap. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
    蜂鸟地图的主题管理，
    注，如果用户需要自己管理主题文件，需要注意以下几点：
    1.下载的资源数据是zip格式的压缩包，需要自己去解压；
    2.解压后的数据中有主题资源以及配套的图片资源，若要正常显示主题，图片文件需要与主题文件在相同的目录下；
 */
@interface FMKThemeDataManager : NSObject

+ (instancetype)shareInstance;

/*!
 @brief 主题存储根目录
 */
@property (nonatomic,readonly) NSString* themePath;

/**
 * 保存主题数据
 * 保存的过程将会进行解压
 * 解压后的文件需要放在同一目录下
 *
 *  @param themeData 图片数据
 *  @param themeID   主题ID
 */
- (void)saveThemeData:(NSData*)themeData ID:(NSString *)themeID;

/**
 *  获取主题数据路径
 *
 *  @param themeID 主题ID
 *
 *  @return 该主题ID所在的文件路径
 */
- (NSString *)getThemeDataPathWithID:(NSString *)themeID;

/**
 *  判断是否已存在主题
 *
 *  @param themeID 主题ID
 *
 *  @return YES/NO
 */
- (BOOL)themeExistWithID:(NSString *)themeID;

/**
 *  删除themeID的数据
 *  删除时会将主题包携带的图片一同删除
 *
 *  @param themeID 主题ID
 */
- (BOOL)deleteLocalDataWithID:(NSString *)themeID;

/*
 * 删除所有地图主题数据
 */
- (BOOL)deleteAllThemeData;

@end






