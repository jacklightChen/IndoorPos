//
//  BRTBeaconDefinitions.h
//  BrightSDK
//
//  Version : 1.0.0
//  Created by Bright Beacon on 19/04/14.
//  Copyright (c) 2014 Bright. All rights reserved.
//

#import <Foundation/Foundation.h>
////////////////////////////////////////////////////////////////////
// Type and class definitions
/**
 * 更新日志
 *
 *  3.4.9 修复brtBeacons
 *  3.4.8 分离蓝牙扫描、iBeacon扫描
 *  3.4.7 优化区域监听(regionHander)
 *
 */
#define SDK_VERSION @"3.4.9"

//////可用的配置参数列表
#define B_NAME @"name"
#define B_UUID @"uuid"
#define B_MAJOR @"major"
#define B_MINOR @"minor"
#define B_MEASURED @"mPower"
#define B_MPOWER @"mPower"
#define B_INTERVAL @"txInterval"
#define B_TX @"txPower"
#define B_MODE @"pMode"
#define B_BATTERY_INTERVAL @"batteryInterval"
#define B_TEMPERATURE_INTERVAL @"temperatureInterval"
#define B_LIGHT_INTERVAL @"lightInterval"
#define B_LIGHT_SLEEP @"lightSleep"
//Anti
#define B_Reserved @"Reserved"
#define B_InRange @"InRange"
#define B_AutoAlarm @"AutoAlarm"
#define B_ActiveFind @"ActiveFind"
#define B_ButtonAlarm @"ButtonAlarm"
#define B_AutoAlarmTimeOut @"autoalarmtimeout"

//阿里轮播模式
#define B_Ali_Switch @"AliSw"
#define B_AliUUID_Switch @"AliUUIDsw"
#define B_AliUUID @"Reserved"

//Eddystone  （0304-9新增）
#define B_BroadcastMode @"BroadcastMode"
#define B_EddystoneURL @"Reserved"

//新增用户自定义4byte广播数据（>030x-10,031x-4,040x）
#define B_UserData @"userData"

//040x版本串口数据
#define B_SerialData @"serialData"

//0313 注：至少保持一个广播频点，如果设置全部关闭，默认2402
#define B_Off2402 @"off2402"
#define B_Off2426 @"off2426"
#define B_Off2480 @"off2480"

//050x版本广播切换间隔
#define B_BROADCAT_INTERVAL @"broadcatInterval"


/////恢复默认参数
#define DEFAULT_KEY @"00000000000000000000000000000000"   //32-0
#define DEFAULT_UUID @"E2C56DB5-DFFB-48D2-B060-D0F5A71096E0"
#define DEFAULT_MAJOR 0
#define DEFAULT_MINOR 0
#define DEFAULT_MEASURED -65
//间隔(ms)
#define DEFAULT_INTERVAL 760
#define DEFAULT_BCHECK_INTERVAL 3600
#define DEFAULT_TCHECK_INTERVAL 0
#define DEFAULT_LCHECK_INTERVAL 0

/*
 * 发送功率(dbm)
 * TI芯片   -23    -6      0       +4
 * Nordic  -40    -30    -20     -16    -12    -8      -4       0     +4
 */

#define DEFAULT_TX  2
#define DEFAULT_TX_PLUS  7
//针对BrtSupportsExtension设备，请直接使用功率数值。
#define DEFAULT_TX_EX  0

#define DEFAULT_NAME  @"BrightBeacon"
#define DEFAULT_MODE 0
#define DEFAULT_LIGHT_SLEEP 0

#define kNotifyConnect @"kNotifyConnect"
#define kNotifyCancelConnect @"kNotifyCancelConnect"
#define kNotifyDisconnect @"kNotifyDisconnect"

#ifndef I2N
#define I2N(x) [NSNumber numberWithInt:x]
#define F2N(x) [NSNumber numberWithFloat:x]
#define L2N(x) [NSNumber numberWithInteger:x]

#define I2S(x) [I2N(x) stringValue]
#define F2S(x) [F2N(x) stringValue]
#define L2S(x) [L2N(x) stringValue]
#endif

typedef NS_OPTIONS(NSUInteger, BrtSupports) {
    BrtSupportsCC254x                   = 1 << 0,//TI系列
    BrtSupportsNordic                   = 1 << 1,//Nordic系列
    BrtSupportsLight                    = 1 << 2,//光感支持
    BrtSupportsCombineCharacteristic    = 1 << 3,//组合特征
    BrtSupportsAntiLose                 = 1 << 4,//已废弃，防丢器
    BrtSupports16Key                    = 1 << 5,//加密模式
    BrtSupportsUpdateName               = 1 << 6,//设备名轮播
    BrtSupportsAli                      = 1 << 7,//已废弃，替换为eddystone
    BrtSupportsEddystone                = BrtSupportsAli,//Google Eddystone协议
    BrtSupportsSerialData               = 1 << 8,//串口数据收发
    BrtSupportsAdvRFOff                 = 1 << 9,//广播频点配置
    BrtSupportsUserData                 = 1 << 10,//广播自定义数据
    BrtSupportsExtension                = 1 << 11,//自定义扩展
    BrtSupportsEncrypt                  = 1 << 12,//广播加密
    BrtSupportsAB                       = 1 << 13//AB芯片
};

typedef NS_ENUM(NSInteger,DevelopPublishMode)
{
    DevelopMode=0,  //开发模式
    PublishMode,    //部署模式
};

typedef NS_ENUM(NSInteger,BroadcastMode)
{
    Broadcast_iBeacon_Only=0,       //只广播iBeacon        0   0   x
    Broadcast_eddystone_Uid_Only=2,   //只广播Uid            0   1   0
    Broadcast_eddystone_Url_Only=3,   //只广播Url            0   1   1
    Broadcast_iBeacon_eddystone_Uid=4,//广播iBeacon 和Uid    1   0   0
    Broadcast_iBeacon_eddystone_Url=5,//广播iBeacon 和Url    1   0   1
    Broadcast_eddystone_Url_Uid=6,    //广播Url 和Uid        1   1   x
};

typedef NS_ENUM(NSInteger,ErrorCode)
{
    ErrorCodeUnKnown = 0,  //未知错误（发起连接失败、蓝牙信道拥塞）
    CBErrorCode1 = 1,     //参数无效
    CBErrorCode2 = 2,     //指定属性无效
    CBErrorCode3 = 3,     //设备未连入
    CBErrorCode4 = 4,     //设备空间资源耗尽
    CBErrorCode5 = 5,     //操作被取消
    CBErrorCode6 = 6,     //连接超时
    CBErrorCode7 = 7,     //设备被断开（连接错误、AppKey不正确）
    CBErrorCode8 = 8,     //指定的UUID不允许
    CBErrorCode9 = 9,     //设备正在广播
    CBErrorCode10 = 10,     //设备连接失败(信号中断等)
    
    ErrorCode100 = 100,     //APP KEY不正确
    ErrorCode101 = 101,     //未识别的设备(未检测到peripheral或非BrightBeacon设备)
    ErrorCode102 = 102,     //网络连接失败
    ErrorCode103 = 103,     //未检测到传感器(读取传感器特征失败)
    ErrorCode104 = 104,     //未检测到传感器、读取数据有误(读取传感器特征失败)
    ErrorCode105 = 105,     //当前版本固件不支持更新
    ErrorCode106 = 106,     //暂无版本更新，或未执行版本检测：checkFirmwareUpdateWithCompletion:
    ErrorCode107 = 107,     //固件下载失败，请重试
    ErrorCode108 = 108,     //固件数据有误
    ErrorCode109 = 109,     //固件更新中断
    ErrorCode110 = 110,     //unuse
} ;

typedef void(^BRTCompletionBlock)(BOOL complete, NSError* error);
typedef void (^BRTDataCompletionBlock)(id data,NSError *error);


////////////////////////////////////////////////////////////////////
// Interface definition

@interface BRTBeaconDefinitions : NSObject

@end
