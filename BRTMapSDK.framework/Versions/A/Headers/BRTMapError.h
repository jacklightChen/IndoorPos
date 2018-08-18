

#ifndef kBRTMapError_h
#define kBRTMapError_h

#define kBRTMapErrorDomain @"BRTMapErrorDomain"

/**
 *  地图错误码对照
 */
typedef NS_ENUM(NSInteger,BRTMapError) {
    kBRTMapErrorNone = 0,
    /** 本地权限验证失败 code = 100*/
    kBRTMapErrorLicenseInvalid = 100,
    /** 本地权限过期*/
    kBRTMapErrorLicenseExpired,
    /** 权限更新失败*/
    kBRTMapErrorLicenseUpdateFailed,
    /** 权限更新验证失败*/
    kBRTMapErrorLicenseUpdateDenied,
    /** 地图版本检查失败*/
    kBRTMapErrorVersionUpdateFailed,
    /** 地图版本权限接口验证失败*/
    kBRTMapErrorVersionUpdateDenied,
    /** 地图数据更新失败*/
    kBRTMapErrorDataUpdateFailed,
    /** 地图数据更新接口验证失败*/
    kBRTMapErrorDataUpdateDenied,
    /** 地图数据目录写入失败*/
    kBRTMapErrorDataWriteFailed,
    /** 地图数据解压失败*/
    kBRTMapErrorZipFailed,
    /** 地图数据读取失败*/
    kBRTMapErrorDataReadingFailed
};

#endif /* kBRTMapError_h */
