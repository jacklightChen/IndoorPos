//
//  NaviResult.h
//  location
//
//  Created by 陈之豪 on 2018/8/24.
//  Copyright © 2018年 陈之豪. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NaviResult : NSObject
/*导航的总距离*/
@property (nonatomic,assign) double sumDis;
/*导航路线的点集*/
@property (nonatomic,strong) NSMutableArray *array;
@end
