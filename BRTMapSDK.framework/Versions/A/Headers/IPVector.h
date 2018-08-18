//
//  Vector2.h
//  MapProject
//
//  Created by thomasho on 18/4/17.
//  Copyright (c) 2018年 thomasho. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface IPVector : NSObject

@property (nonatomic, assign) double x;
@property (nonatomic, assign) double y;
@property (nonatomic, strong) id obj;

+ (instancetype)fromX:(double)x Y:(double)y;
+ (instancetype)fromPoint:(NSArray *)point;

-(double)getAngle;
-(double)getlength;
-(double)getSqlength;
-(IPVector *)getScaleVector:(double)scale;

@end
