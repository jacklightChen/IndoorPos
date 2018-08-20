//
//  PositionUtil.swift
//  location
//
//  Created by 陈之豪 on 2018/8/20.
//  Copyright © 2018年 陈之豪. All rights reserved.
//

import Foundation
import Accelerate

class PositionUtilSwift:NSObject{
    func calPosition (infos:NSMutableArray) -> Coordination {
        let result=Coordination();
        if infos.count<=2 {
            return result
        }
        var left = [Double]()
        var right = [Double]()
        let n = infos.count
        let last = infos.object(at: n-1) as! Coordination
        
        /*build matrix a n行2列*/
        for i in 0...n-2 {
            let cur=infos.object(at: i) as! Coordination
            let value1 = 2 * (cur.x - last.x)
            left.append(value1)
            let value2 = 2 * (cur.y - last.y)
            left.append(value2)
        }
        
        /*build matrix b n行1列*/
        for i in 0...n-2{
            let cur=infos.object(at: i) as! Coordination
            let value=pow2(value: cur.x) - pow2(value: last.x) + pow2(value: cur.y) - pow2(value: last.y) + pow2(value: last.dis) -  pow2(value: cur.dis);
            right.append(value)
        }
        
        
        /*a的转置 2行n列*/
        var leftT = [Double](repeating : 0.0, count : 2*n)
        vDSP_mtransD(left, 1, &leftT, 1, 2, vDSP_Length(n))
        
        /*temp 2行2列*/
        var temp = [Double](repeating : 0.0, count : 4)
        vDSP_mmulD(leftT, 1, left, 1, &temp, 1, 2, 2, vDSP_Length(n))
        
        /*按公式计算
         * (A^T*A)^(-1)*A^T*B=X
         * temp2 2行n列
         */
        let tempInv=invert(matrix: temp)
        var temp2 = [Double](repeating : 0.0, count : 2*n)
        vDSP_mmulD(tempInv, 1, leftT, 1, &temp2, 1, 2, vDSP_Length(n), 2);
        
        
        /*中间结果乘以最后的right矩阵*/
        var resultMatrix=[Double](repeating : 0.0, count : 2)
        vDSP_mmulD(temp2, 1, right, 1, &resultMatrix, 1, 2,  1, vDSP_Length(n))
        result.x=resultMatrix[0];
        result.y=resultMatrix[1];
        return result
    }
    func pow2(value:Double) -> Double {
        return value*value;
    }
    func invert(matrix : [Double]) -> [Double] {
        
        var inMatrix = matrix
        
        var pivot : __CLPK_integer = 0
        var workspace = 0.0
        var error : __CLPK_integer = 0
        
        var N = __CLPK_integer(sqrt(Double(matrix.count)))
        dgetrf_(&N, &N, &inMatrix, &N, &pivot, &error)
        
        if error != 0 {
            return inMatrix
        }
        
        dgetri_(&N, &inMatrix, &N, &pivot, &workspace, &N, &error)
        return inMatrix
    }
}
