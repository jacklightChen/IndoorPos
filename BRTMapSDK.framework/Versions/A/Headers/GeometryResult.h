//
//  GeometryResult.h
//  BRTMapProject
//
//  Created by thomasho on 2018/5/11.
//  Copyright © 2018年 thomasho. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>

@interface GeometryResult : NSObject

@property (nonatomic,assign) CLLocationCoordinate2D preCoordinate;
@property (nonatomic,assign) CLLocationCoordinate2D nextCoordinate;
@property (nonatomic,assign) CLLocationCoordinate2D crossCoordinate;
@property (nonatomic,assign) NSUInteger pointIndex;

+ (instancetype)resultWithCoordinate:(CLLocationCoordinate2D)coord;
+ (instancetype)resultWithCoordinate:(CLLocationCoordinate2D)coord pre:(CLLocationCoordinate2D)pre next:(CLLocationCoordinate2D)next index:(NSUInteger)index;

@end
