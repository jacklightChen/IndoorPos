/*
 *  因C++库冲突 废弃的基于Eigen库的代码
 *
 */

////  LocationUtil.m
////  location
////
////  Created by 陈之豪 on 2018/8/2.
////  Copyright © 2018年 陈之豪. All rights reserved.
////
//
//#import "LocationUtil.h"
//#import <iostream>
//#import <Eigen/Core>
//#import <Accelerate/Accelerate.h>
//
//using namespace std;
//using namespace Ei`   `       ``  `                   `                                                                   ````                ``````````                                                      gen;
//
//@implementation LocationUtil
//
//+(Coordination *)getRealCoordination:(NSMutableArray *)infos{
//    if(infos.count<=2)return nil;
//    NSUInteger n=infos.count;
//    MatrixXd left(n,2);
//    MatrixXd right(n,1);
//    Coordination *last=[infos objectAtIndex:n-1];
//    /*build matrix a*/
//    for(int i=0;i<n-1;i++){
//        Coordination *cur=[infos objectAtIndex:i];
//        double value1=2*(cur.x - last.x);
//        left(i,0)=value1;
//        double value2=2*(cur.y - last.y);
//        left(i,1)=value2;
//    }
//    /*build matrix b*/
//    for(int i=0;i<n-1;i++){
//        Coordination *cur=[infos objectAtIndex: i];
//        double value=[self pow2:cur.x]-[self pow2:last.x]
//        +[self pow2:cur.y]-[self pow2:last.y]
//        +[self pow2:last.dis]-[self pow2:cur.dis];
//        right(i,0)=value;
//    }
//    
//    /*a的转置*/
//    MatrixXd leftT=left.transpose();
//    MatrixXd temp=leftT*left;
//    /*按公式计算
//     * (A^T*A)^(-1)*A^T*B=X*/
//    MatrixXd tempInv=temp.inverse();
//    MatrixXd temp2=tempInv*leftT;
//    
//    /*中间结果乘以最后的right矩阵*/
//    MatrixXd resultMatrix=temp2*right;
//    Coordination * target =[[Coordination alloc]initWithX:resultMatrix(0,0) andY:resultMatrix(1,0) andDis:0];
//    return target;
//}
//+(double)pow2:(double) target
//{
//    return target*target;
//}
//@end
