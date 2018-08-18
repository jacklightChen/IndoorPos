//
//  BRTTools.h
//  BrightSDK
//
//  Created by thomasho on 16/9/18.
//  Copyright © 2016年 thomasho. All rights reserved.
//

#import <Foundation/Foundation.h>

#define subString(str,loc,len) [str substringWithRange:NSMakeRange(loc, len)]

@interface BRTTools : NSObject

+ (NSData *)hex2data:(NSString *)hex;
+ (NSString *)data2hex:(NSData *)data;
+ (NSString *)data2UTF8:(NSData *)data;

//小端模式(little-endian)
+ (int32_t)data2Integer:(NSData *)data;
+ (NSData *)integer2data:(int32_t )value;
+ (NSData *)uinteger2data:(uint32_t )value;

@end
