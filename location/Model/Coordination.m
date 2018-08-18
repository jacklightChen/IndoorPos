//
//  Coordination.m
//  location
//
//  Created by 陈之豪 on 2018/7/24.
//  Copyright © 2018年 陈之豪. All rights reserved.
//

#import "Coordination.h"

@implementation Coordination
-(instancetype)initWithX:(double)x andY:(double)y andDis:(double)dis{
    self = [super init];
    if (self) {
        self.x=x;
        self.y=y;
        self.dis=dis;
    }
    return self;
}
-(instancetype)initWithX:(double)x andY:(double)y{
    self = [super init];
    if (self) {
        self.x=x;
        self.y=y;
    }
    return self;
}

-(instancetype)initWithX:(double)x andY:(double)y andId:(int)identifier{
    self = [super init];
    if (self) {
        self.x=x;
        self.y=y;
        self.identifier=identifier;
    }
    return self;
}
@end
