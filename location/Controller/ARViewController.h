//
//  ARViewController.h
//  location
//
//  Created by 陈之豪 on 2018/8/9.
//  Copyright © 2018年 陈之豪. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <ARKit/ARKit.h>
#import <SceneKit/SceneKit.h>
#import "MapViewController.h"
#import "SVProgressHUD.h"
#import "NaviResult.h"

@interface ARViewController : UIViewController

@property (nonatomic,strong) MapViewController *map;
@property (nonatomic,assign) BOOL flag;
@end
