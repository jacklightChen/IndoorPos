//
//  BRTNetEncryption.h
//  MapProject
//
//  Created by thomasho on 17/5/25.
//  Copyright © 2017年 BrightBeacon. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface BRTNetEncryption : NSObject

+ (NSString *) encode:(NSString *)str;
+ (NSString *) decode:(NSString *)str;

@end
