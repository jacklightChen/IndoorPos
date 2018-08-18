//
//  TYMapCredential.h
//  MapProject
//
//  Created by thomasho on 18/11/27.
//  Copyright © 2018年 thomasho. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "BRTMapError.h"

#define kDefaultLicense @"00000000000000000000000000000000"

@interface BRTMapCredential : NSObject

+ (BRTMapError)checkAppKey:(NSString *)aKey BuildingID:(NSString *)bid License:(NSString *)license;
+ (void)saveAppKey:(NSString *)aKey BuildingID:(NSString *)bid License:(NSString *)license;
+ (void)resetAppKey:(NSString *)aKey BuildingID:(NSString *)bid;

+ (NSString *)urlEncodeLicense:(NSString *)license;
+ (NSString *)urlDecodeLicense:(NSString *)license;
@end
