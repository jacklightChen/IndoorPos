//
//  AppDelegate.m
//  location
//
//  Created by 陈之豪 on 2018/7/24.
//  Copyright © 2018年 陈之豪. All rights reserved.
//

#import "AppDelegate.h"
#import "BRTBeaconSDK.h"
#import "FMMapKit.h"

@interface AppDelegate ()

@end

@implementation AppDelegate
- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    //brightbeacon appkey
    [BRTBeaconSDK registerApp:DEFAULT_KEY onCompletion:^(BOOL complete, NSError *error) {
        NSLog(@"注册appKey：%@",error);
    }];
    //fengmap appkey
    [[FMKMapSDK shareSDK] setKey:@"1a3591234f52bb1aadf8150665f33581"];
    return YES;
}

@end
