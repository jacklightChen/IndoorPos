//
//  MapViewController.h
//  location
//
//  Created by 陈之豪 on 2018/8/8.
//  Copyright © 2018年 陈之豪. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "NaviResult.h"


@interface MapViewController : UIViewController
-(void)showPointWithX:(double)x andY:(double)y;
-(NaviResult *)getNavi;
@end
