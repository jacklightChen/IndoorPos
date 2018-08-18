//
//  MercatorConvert.h
//  BRTMapProject
//
//  Created by thomasho on 2018/4/18.
//  Copyright © 2018年 thomasho. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <CoreLocation/CoreLocation.h>
#import "IPVector.h"

@interface MercatorConvert : NSObject

+ (IPVector *)toMercator:(CLLocationCoordinate2D)coordinate;
+ (CLLocationCoordinate2D)toCoordX:(double)x Y:(double)y;

@end
