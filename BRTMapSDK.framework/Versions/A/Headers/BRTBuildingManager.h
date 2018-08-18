//
//  TYBuildingManager.h
//  MapProject
//
//  Created by thomasho on 18/9/8.
//  Copyright (c) 2018年 thomasho. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <BRTMapData/BRTMapData.h>

/**
 *  建筑管理类，用于管理建筑数据
 */
@interface BRTBuildingManager : NSObject

/**
 *  解析目标城市特定ID的建筑信息
 *
 *  @param buildingID 目标建筑ID
 *
 *  @return 目标建筑信息
 */
+ (BRTBuilding *)parseBuilding:(NSString *)buildingID;

@end
