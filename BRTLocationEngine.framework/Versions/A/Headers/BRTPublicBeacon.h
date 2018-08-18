#import "BRTMapBeacon.h"
#import <BRTMapData/BRTMapData.h>

/**
 *  公共Beacon类，当前用于表示固定部署用于定位的beacon
 */
@interface BRTPublicBeacon : BRTMapBeacon

/**
 *  Beacon所部署的位置
 */
@property (nonatomic, strong) BRTLocalPoint *location;

/**
 *  Beacon部署位置所属的商铺，可以为空
 */
@property (nonatomic, strong) NSString *shopGid;


@property (nonatomic, strong) NSString *mapID;
@property (nonatomic, strong) NSString *buildingID;
@property (nonatomic, strong) NSString *cityID;

/**
 *  初始化定位Beacon的类方法
 *
 *  @param uuid     UUID
 *  @param major    Major
 *  @param minor    Minor
 *  @param tag      Beacon的Tag，用于标识Beacon，如Mac地址，序列号等
 *  @param location Beacon所部署的位置
 *
 *  @return 定位Beacon实例
 */
+ (BRTPublicBeacon *)beaconWithUUID:(NSString *)uuid Major:(NSNumber *)major Minor:(NSNumber *)minor Tag:(NSString *)tag Location:(BRTLocalPoint *)location;

/**
 *  初始化定位Beacon的类方法
 *
 *  @param uuid     UUID
 *  @param major    Major
 *  @param minor    Minor
 *  @param tag      Beacon的Tag，用于标识Beacon，如Mac地址，序列号等
 *  @param location Beacon所部署的位置
 *  @param shopID   Beacon部署位置所属的商铺，可以为空
 *
 *  @return 定位Beacon实例
 */
+ (BRTPublicBeacon *)beaconWithUUID:(NSString *)uuid Major:(NSNumber *)major Minor:(NSNumber *)minor Tag:(NSString *)tag Location:(BRTLocalPoint *)location ShopGid:(NSString *)shopID;

+ (NSDictionary *)buildBeaconObject:(BRTPublicBeacon *)pb;
+ (BRTPublicBeacon *)parseBeaconObject:(NSDictionary *)beaconObject;

@end
