#import <Foundation/Foundation.h>

typedef enum type {
   UNKNOWN, PUBLIC, TRIGGER, ACTIVITY
} BRTPE;

typedef enum proximity {
    BRTProximityUnknown,
    BRTProximityImmediate,
    BRTProximityNear,
    BRTProximityFar
} BRTProximity;

/**
 *  智石Beacon类
 */
@interface BRTMapBeacon : NSObject

/**
 *  UUID 设备通用标识，可用于表示建筑、大区域范围
 */
@property (readonly, strong) NSString *UUID;

/**
 *  Major 主标识，可用于表示楼层、小区域范围等
 */
@property (readonly, strong) NSNumber *major;

/**
 *  Minor 次标识，可用于表示具体位置、物品等
 */
@property (readonly, strong) NSNumber *minor;

/**
 *  Beacon的Tag，用于标识Beacon，如Mac地址，序列号等
 */
@property (readonly, strong) NSString *tag;

/**
 *  扫描到Beacon的信号强度
 */
@property (nonatomic, assign) int rssi;

/**
 *  距离Beacon相对距离的准确性，单位为米，常用于相对远近比较
 */
@property (nonatomic, assign) double accuracy;

/**
 *  距离Beacon的相对距离，远/中/近
 */
@property (nonatomic, assign) BRTProximity proximity;

/**
 *  Beacon用途类型，如用于定位、营销等
 */
@property (assign) BRTPE type;


/**
 *  初始化Beacon的类方法
 *
 *  @param uuid  UUID
 *  @param major Major
 *  @param minor Minor
 *  @param tag   标识
 *
 *  @return Beacon实例
 */
+ (BRTMapBeacon *)beaconWithUUID:(NSString *)uuid Major:(NSNumber *)major Minor:(NSNumber *)minor Tag:(NSString *)tag;

/**
 *  初始化Beacon的类方法
 *
 *  @param uuid  UUID
 *  @param major Major
 *  @param minor Minor
 *  @param tag   标识
 *  @param type  类型
 *
 *  @return Beacon实例
 */
+ (BRTMapBeacon *)beaconWithUUID:(NSString *)uuid Major:(NSNumber *)major Minor:(NSNumber *)minor Tag:(NSString *)tag Type:(BRTPE) type;

/**
 *  初始化Beacon的方法
 *
 *  @param uuid  UUID
 *  @param major Major
 *  @param minor Minor
 *  @param tag   标识
 *  @param type  类型
 *
 *  @return Beacon实例
 */
- (id)initWithUUID:(NSString *)uuid Major:(NSNumber *)major Minor:(NSNumber *)minor Tag:(NSString *)tag Type:(BRTPE)type;

@end
