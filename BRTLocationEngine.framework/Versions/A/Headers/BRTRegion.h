//
//  BRTRegion.h
//  BRTMapLocationDemo
//
//  Created by thomasho on 18/4/14.
//  Copyright (c) 2018年 thomasho. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>

@interface BRTRegion : NSObject

@property (nonatomic, strong) NSString *cityID;
@property (nonatomic, strong) NSString *buildingID;
@property (nonatomic, strong) NSString *name;
@property (nonatomic, strong) CLBeaconRegion *region;

+ (BRTRegion *)beaconRegionWithCityID:(NSString *)cid BuildingID:(NSString *)bid Name:(NSString *)name UUID:(NSString *)uuidString Major:(NSNumber *)m;

+ (NSDictionary *)buildRegionObject:(BRTRegion *)region;
+ (BRTRegion *)parseBeaconRegionObject:(NSDictionary *)regionObject;

@end
