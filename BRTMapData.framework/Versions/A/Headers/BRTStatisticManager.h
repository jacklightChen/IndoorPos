//
//  BRTStatisticManager.h
//  TYData
//
//  Created by thomasho on 17/5/25.
//  Copyright © 2017年 BrightBeacon. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface BRTStatisticManager : NSObject

+ (BOOL)getStatisticEnable;
+ (void)statisticEnable:(BOOL)enable;
+ (NSString *)getPersonID;
+ (void)statisticMapVerion:(NSString *)mapVersion;
+ (void)statisticLocVersion:(NSString *)locVersion;
+ (void)statisticLoadBuilding:(NSString *)buildingID;
+ (void)statisticUnloadBuilding:(NSString *)buildingID;
+ (void)statisticBuilding:(NSString *)buildingID searchKey:(NSString *)key;
+ (void)statisticBuilding:(NSString *)buildingID selectedPOI:(NSString *)poiID;

@end
