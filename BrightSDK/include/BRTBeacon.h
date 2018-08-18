//
//  BRTBeacon.h
//  BrightSDK
//
//  Version : 1.0.0
//  Created by Bright Beacon on 21/04/14.
//  Copyright (c) 2014 Bright. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>
#import <CoreBluetooth/CoreBluetooth.h>
#import "BRTBeaconDefinitions.h"

@class BRTBeacon;

////////////////////////////////////////////////////////////////////
// Bright Beacon delegate protocol


/**
 
 BRTBeaconDelegate 定义了 beacon 连接相关的委托方法，beacon 的连接是一个异步操作，因此你只需要实现例如beaconDidDisconnect:相关方法，它们会被自动回调.
 
 */

@protocol BRTBeaconDelegate <NSObject>

@optional

/**
 * beacon连接产生错误回调该方法.
 *
 * @param beacon 关联的beacon实体
 * @param error 错误的描述信息
 *
 */
- (void)beaconConnection:(BRTBeacon*)beacon withError:(NSError*)error;

/**
 * beacon与设备已经断开连接回调该方法
 *
 * @param beacon 关联的beacon实体
 * @param error 错误的描述信息
 *
 */
- (void)beaconDidDisconnect:(BRTBeacon*)beacon withError:(NSError*)error;

/**
 * beacon 050x读写参数回调
 *
 * @param beacon 关联的beacon实体
 * @param data 返回数据信息
 * @param error 返回错误信息
 *
 */
- (void)beacon:(BRTBeacon *)beacon didUpdateValue:(NSData *)value error:(NSError *)error;

@end


////////////////////////////////////////////////////////////////////
// Interface definition

/**
 
 BRTBeacon类代表了一个在该区域监听中遇到的beacon设备. 你不需要直接实例化这个类. BRTBeaconManager在扫描到beacon设备时会回调相应delegate的方法传人BRTBeacon.你可以通过BRTBeacon里的信息来识别不同的设备.
 
 
 BRTBeacon类既包含了苹果CLBeacon类的基本方法，同时也新增了一些扩展方法，它能连接到beacon设备读取和写人一些特征（characteristics）.
 
 */

@interface BRTBeacon : NSObject <CBPeripheralDelegate>

@property (nonatomic, weak)     id <BRTBeaconDelegate>  delegate;

/////////////////////////////////////////////////////
//
//

/**
 *  invalidTime
 *
 *  Discussion:
 *    beacon设备上一次出现的时间戳，一般用于维护是设备生存周期，例如5s内未再次收到该设备信号，就移除该beacon设备.
 */
@property (nonatomic, assign) NSTimeInterval invalidTime;

/**
 *  macAddress
 *
 *  Discussion:
 *    beacon设备的物理地址.可以唯一标识Bright Beacon设备，非BrightBeacon设备该值可能为空
 */
@property (nonatomic, strong)   NSString*               macAddress;

/**
 *  name
 *
 *    beacon设备名.
 *
 */
@property (nonatomic, strong)   NSString*               name;

/**
 *  proximityUUID
 *
 *    beacon设备的UUID，可以用作区域标识
 *
 */
@property (nonatomic, strong)   NSUUID*                 proximityUUID;

/**
 *  major
 *
 *    设备的主要属性值，默认值是0。可以用作区域标识
 *
 * Discussion:
 * 注意该值在用于区域标识，0和nil不等价：0是监测区域中对应UUID的设备下Major为0的设备，nil则表示不使用该值
 */
@property (nonatomic, strong)   NSNumber*               major;

/**
 *  minor
 *
 *    设备的次要属性值，默认值是0。可以用作区域标识，类同Major
 *
 * Discussion:
 * 注意该值在用于区域标识，0和nil不等价：0是监测区域中对应UUID的设备下Minor为0的设备，nil则表示不使用该值
 */
@property (nonatomic, strong)   NSNumber*               minor;



/**
 *  rssi
 *
 *    beacon的接收信号强度指示（Received Signal Strength Indicator）以分贝为单位.
 *    该值是根据本次beacon发射的信号所收集到样本的平均值.
 *
 */
@property (nonatomic)           NSInteger               rssi;

/*
 *  accuracy
 *
 *   该值单位‘米’，值越小表明位置越近，负值无效，仅作参考距离
 *
 */
@property (nonatomic) CLLocationAccuracy accuracy;

/**
 *  distance
 *
 *    根据接收信号强度指示（rssi）和测量功率（measured power：距离一米的rssi值）估算出的beacon设备到手机的距离.
 *
 */
@property (nonatomic, strong)   NSNumber*               distance;

/**
 *  proximity
 *
 *    该值代表相对距离远近，可以通过它快速确定beacon设备距离用户是在附近或是很远.
 */
@property (nonatomic)           CLProximity             proximity;

/**
 *  measuredPower
 *
 *    该值是1米处的rssi值，用于设备距离估算.
 */
@property (nonatomic, strong)   NSNumber*               measuredPower;

/**
 *  region
 *
 *    该值是设备所在区域region，仅IOS7+支持
 */
@property (nonatomic, strong)   CLBeaconRegion*               region;

/**
 *  peripheral
 *
 *    代表一个周边设备，用于蓝牙连接.
 */
@property (nonatomic, strong)   CBPeripheral*           peripheral;

/**
 *  isBrightBeacon
 *
 *    是否是BrightBeacon
 */
@property (nonatomic, assign)    BOOL    isBrightBeacon;

/**
 *  isConnected
 *
 *    标示连接状态.
 */
@property (nonatomic, readonly)   BOOL                  isConnected;
/**
 *  battery
 *
 *    battery电量，范围 0~100，通过实时工作电压估算值；连接时功耗变化，较广播时略偏低
 */
@property (nonatomic, strong)    NSNumber*    battery;

/**
 *  temperature
 *
 *    温度，范围 -40~100℃ ，127为无效值
 */
@property (nonatomic, strong)    NSNumber*    temperature;

/**
 *  light
 *
 *    光感强度
 */
@property (nonatomic, assign)   NSInteger          light;

/**
 *  mode
 *
 *    Beacon模式，开发模式，部署模式
 */
@property (nonatomic, assign)    DevelopPublishMode    mode;

/**
 *  硬件版本
 *
 *    设备硬件版本
 */
@property (strong, nonatomic)   NSString*               hardwareVersion;

/**
 *  固件版本
 *
 *    设备固件版本
 */
@property (strong, nonatomic)   NSString*               firmwareVersion;

/**
 * 当前版本支持状态（位标示,参见BrtSupports）
 *
 */
@property (nonatomic,assign) NSInteger supportOption;

/**
 *  广播模式选择（1、iBeacon 2、eddystone-Uid 3、eddystone-Url）
 *
 * 轮播Beacon专用
 * <br/>0.只广播iBeacon,               bit[2]=0,bit[3]=0,
 * <br/>1.仅广播Eddystone(UID),        bit[2]=0,bit[3]=1,bit[4]=0
 * <br/>2.仅广播Eddystone(URL),        bit[2]=0,bit[3]=1,bit[4]=1
 * <br/>3.轮播iBeacon和Eddystone(UID), bit[2]=1,bit[3]=0,bit[4]=0
 * <br/>4.轮播iBeacon和Eddystone(URL), bit[2]=1,bit[3]=0,bit[4]=1
 * <br/>5,轮播Eddystone(UID/URL),      bit[2]=1,bit[3]=1
 */
@property (nonatomic,assign) BroadcastMode broadcastMode;

/**
 * 050x广播标识位数据 2byte（16bit）
 *
 * 标志位  
 *  15  14  13  广播频点(同isOff2480、isOff2426、isOff2402)
 *  12 ~ 4      未使用
 *  3  2  1     广播模式 (同broadcastMode)
 *  0           部署模式/开发模式（同mode）
 *
 *  V0501锁7~4位:激活,反锁,把手,开关
 */
@property (nonatomic,assign) uint16_t flag;

/**
 * 用户自定义广播数据 4byte范围（0x00000000~0xFFFFFFFF）
 */
@property (nonatomic,strong) NSString *userData;

/////////////////////////////////////////////////////
// 通过蓝牙连接，读取的属性

/// @name 连接之后属性可用


/**
 *  power
 *
 *  以分贝计的发射功率，连接后可用
 *  TI芯片：0：-23dBm 1：-6dBm 2：0dBm 3：+4dBm
 *  Nordic芯片：0：-40dBm 1：-30dBm 2：-20dBm 3：-16dBm 4：-12dBm 5：-8dBm 6：-4dBm 7：0dBm 8：+4dBm
 */
@property (nonatomic, assign)   NSInteger           power;

/**
 *  advInterval
 *
 *    广播发射间隔，值范围100ms~10000ms,连接后可用
 */
@property (nonatomic, strong)   NSNumber*               advInterval;

/**
 *  broadcastInterval
 *
 *    广播切换间隔，用于iBeacon、eddystone等广播切换间隔，值范围100ms~1200ms,连接后可用
 */
@property (nonatomic, strong)   NSNumber*    broadcastInterval;

/**
 *  batteryCheckInteval
 *
 *    广播状态下Beacon的电量检测间隔，单位为：秒；范围：1800秒~43200秒（12小时），即每隔指定秒自动检测电量并更新广播的数据
 */
@property (nonatomic, assign)    NSInteger    batteryCheckInteval;

/**
 *  temperatureCheckInteval
 *
 *    广播状态下Beacon周边温度检测间隔，单位为：秒；范围：10秒~43200秒（12小时），即每隔指定秒自动检测电量并更新广播的数据
 */
@property (nonatomic, assign)    NSInteger    temperatureCheckInteval;

/**
 *  lightCheckInteval
 *
 *    广播状态下Beacon周边光强检测间隔（已弃用）
 */
@property (nonatomic, assign)    NSInteger    lightCheckInteval;

/**
 * lightSleep
 *
 *  开启光感休眠（已弃用）
 */
@property (nonatomic, assign)    BOOL    lightSleep;

/**
 *  固件最新版本信息，
 *
 *    固件最新版本信息，{@link checkFirmwareUpdateWithCompletion:}后可用
 */
@property (readonly, nonatomic)   NSString* firmwareVersionInfo;

/**
 *  Eddystone的Uid
 */
@property (nonatomic,strong)  NSString *eddystone_Uid;

/**
 *  Eddystone的实物网链接Url，IOS10以后，必须https才能发现。
 */
@property (nonatomic,strong)  NSString *eddystone_Url;


/**
 *  040x串口数据收发
 *
 *  该值会在串口数据变化时，自动更新。
 */
@property (nonatomic,copy) NSString *serialData;
/**
 * 广播跳频模式，默认3种切换：2402、2426、2480MHz
 */
@property (nonatomic,assign) BOOL isOff2402;
@property (nonatomic,assign) BOOL isOff2426;
@property (nonatomic,assign) BOOL isOff2480;


/**
 *  支持eddystone模式的设备，该属性等同eddystone_url
 */
@property (strong, nonatomic)   NSString*   reserved;



/**
 * rssi 转换成 距离（米）
 *
 * @param beacon beacon设备，需要使用measured power值
 *
 * @return float 距离（米）
 */
+ (float)rssiToDistance:(BRTBeacon*)beacon;

/**
 *  转换Url为eddystone模式NSData
 *  参考：https://github.com/google/eddystone/tree/master/eddystone-url
 *
 *  @param url 例(https://www.brtbeacon.com)->()
 *
 *  @return NSData
 */
- (NSData*)eddystone_Url_From:(NSString*)url;

/**
 *  将eddystone模式下的Url字符串转换为普通url
 *
 *  @param eddystoneUrl eddystone-URL字符串
 *
 *  @return NSString
 */
- (NSString*)eddystone_Url_To:(NSString*)eddystoneUrl;

/// @name 连接beacon相关的方法


/**
 * 检测beacon设备是否支持某些属性
 */
- (BOOL)isSupport:(BrtSupports)option;

/**
 * 蓝牙连接到beacon设备
 * 只能连接之后才可以修改
 * Major, Minor, Power and Advertising interval.
 *
 */
-(void)connectToBeacon;
-(void)connectToBeaconWithCompletion:(BRTCompletionBlock)completion;

/**
 * 断开蓝牙连接
 *
 */
-(void)disconnectBeacon;

/// @name 写人beacon配置信息相关的方法

/**
 *  可扩展Beacon数据传输（仅支持050x版本设备）
 *  适用单消息发送，发送完毕completion立即清空
 *
 *  发送消息ID:
 *  0x00~0x3F：Beacon配置保留如下：
 *      00重启 01版本 02温度电量 03写key 04读UUID 05写UUID 06读MM 07写MM 08读MPower 09写MPower
 *      0A读功率 0B写功率 0C读模式 0D写模式 0E读名称 0F写名称 10读频率 11写频率 12读温度电量间隔 13写温电间隔 14读自定义广播
 *      15写自定义广播 16读eddystoneUrl 17写eddystoneUrl 18开始/停止固件升级数据 19写入固件升级数据 20~3F保留
 *
 *  0x40~0xFF：配合硬件SDK自定义传输使用
 *
 *  @param value     消息ID(1字节)+有效数据长度(1字节)+数据(0~18字节)
 *  示例：
 *  读取UUID：0x0402
 *  写入UUID：0x0512E2C56DB5DFFB48D2B060D0F5A71096E0
 *  @param completion 硬件返回数据：data 消息ID(1字节)+数据长度(1字节)+返回消息数据(0~18字节)
 */
- (void)sendBeaconValue:(NSData *)value withCompletion:(BRTDataCompletionBlock)completion;

/**
 *  可扩展Beacon数据传输（仅支持050x版本设备）
 *  适用批量发送,delegate依次返回所有消息回复
 *
 *  @param values 消息ID(1字节)+数据长度(1字节)+消息数据(0~18字节)
 *  @param delegate 同self.delegate
 */
- (void)sendBeaconValue:(NSArray *)values withDelegate:(id<BRTBeaconDelegate>)delegate;

/**
 * 写入设备信息
 *
 * @param values 设备信息(参见:可用的配置参数列表)
 * @param completion 写入完成回调
 *
 */
- (void)writeBeaconValues:(NSDictionary*)values withCompletion:(BRTCompletionBlock)completion;

/**
 *  检查固件更新
 *
 *  @param completion 写入完成回调
 */
-(void)checkFirmwareUpdateWithCompletion:(BRTDataCompletionBlock)completion;

/**
 *  云端更新固件
 *
 *  @param progress 更新进度0~100
 *  @param completion 写入完成回调
 */
-(void)updateBeaconFirmwareWithProgress:(BRTDataCompletionBlock)progress andCompletion:(BRTCompletionBlock)completion;

/**
 *  读取设备所有信息（为了加快连入速率，连接不在默认执行该操作，请连接成功后自行调用获取参数）
 *
 *  @param completion 返回当前beacon对象和错误信息。
 */
- (void)readBeaconValuesCompletion:(BRTDataCompletionBlock)completion;
/**
 *  读取设备版本信息
 *
 *  @param completion 读取完成回调
 */
- (void)readBeaconFirmwareVersionWithCompletion:(BRTDataCompletionBlock)completion;

/**
 *  读取设备变动信息：温度、电量、光感(若有)
 *
 *  @param completion 读取完成回调
 */
- (void)readBeaconChangesWithCompletion:(BRTDataCompletionBlock)completion;

/**
 * 重置beacon设备默认值，该操作要求已经成功执行 {@link registerApp:};
 *
 */
-(void)resetBeaconToDefault;

/**
 * 重置beacon设备默认KEY，该操作可以解除设备开发者绑定，让beacon设备可以重新被连接设定新的APP_KEY，该操作要求已经成功执行[BRTBeaconManager registerApp:APP_KEY];
 *
 */
- (void)resetSDKKEY;

/**
 * 设置此Beacon处于开发者模式（DevelopMode）还是部署模式（PublishMode）
 *
 * 如果Beacon处于开发者模式，则可以用任意的APP KEY进行连接， 如果Beacon处于部署模式，则需要对应配置过Beacon的APP KEY 才能再一次进行连接，确保Beacon部署安全
 * @param mode 0、开发模式 1、部署模式
 * @param completion 写入完成回调
 */
- (void)writeBeaconMode:(DevelopPublishMode)mode withCompletion:(BRTCompletionBlock)completion;


/**
 距离估算方法，用于衡量不同设备距离差值，相对实际距离可能有误差

 @param rssi 接收信号强度
 @param mpower 1米处信号强度
 @return 估算距离值
 */
+ (float)distanceByRssi:(NSInteger)rssi oneMeterRssi:(NSInteger)mpower;

@end
