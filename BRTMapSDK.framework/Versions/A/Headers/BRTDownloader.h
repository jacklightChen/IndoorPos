//
//  BRTDownloader.h
//  TYMapSDK
//
//  Created by thomasho on 2017/9/13.
//  Copyright © 2017年 thomasho. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface BRTDownloader : NSObject

typedef void(^OnMapDataCompletion)(NSString *locVersion,NSString *newVersion, NSError* error);
+ (void)loadMap:(NSString *)buidingId AppKey:(NSString *)aKey OnCompletion:(OnMapDataCompletion)completion;

@end
