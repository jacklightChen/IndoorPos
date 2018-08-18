//
//  Coordination.h
//  location
//
//  Created by 陈之豪 on 2018/7/24.
//  Copyright © 2018年 陈之豪. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface Coordination : NSObject
    @property (nonatomic,assign)   double x;
    @property (nonatomic,assign)   double y;
    @property (nonatomic,assign)   double dis;
    @property (nonatomic,assign)   int identifier;
-(instancetype)initWithX:(double)x andY:(double)y andDis:(double)dis;
-(instancetype)initWithX:(double)x andY:(double)y;
-(instancetype)initWithX:(double)x andY:(double)y andId:(int)identifier;
@end
