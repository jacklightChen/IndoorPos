//
//  TYLocationError.h
//  TYLocationEngine
//
//  Created by thomasho on 17/5/4.
//  Copyright © 2017年 brightbeacon. All rights reserved.
//

#ifndef TYLocationError_h
#define TYLocationError_h

#define TYLocationErrorDomain @"TYLocationErrorDomain"
/**
 定位数据、定位超时错误对照
 */
typedef NS_ENUM(NSUInteger, TYLocationError) {
    /** 100 权限更新失败*/
    kTYLocationErrorLicenseUpdateFailed = 100,
    /** 101 权限更新接口验证失败*/
    kTYLocationErrorLicenseUpdateDenied,
    /** 102 定位数据版本检查失败*/
    kTYLocationErrorVersionUpdateFailed,
    /** 103 定位数据版本检查接口：验证失败，无定位数据*/
    kTYLocationErrorVersionUpdateDenied,
    /** 104 定位数据更新失败*/
    kTYLocationErrorDataUpdateFailed,
    /** 105 定位数据更新接口验证失败*/
    kTYLocationErrorDataUpdateDenied,
    /** 106 定位数据文件有误*/
    kTYLocationErrorDataZipFailed,
    /** 107 定位数据校验失败*/
    kTYLocationErrorInvalidCode,
    /** 108 定位超时，持续返回*/
    kTYLocationErrorTimeOut
};

#endif /* TYLocationError_h */
