//
//  FMKLayerDelegate.h
//  FMMapKit
//
//  Created by FengMap on 15/8/22.
//  Copyright (c) 2015年 FengMap. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIGestureRecognizer.h>

@class FMKLayer,FMKNode;
/**
 *  层节点协议
 */
@protocol FMKLayerDelegate <NSObject>

/**
 *  当地图上的节点元素被拾取到时，遵循该协议的层将会调用该方法
 *  拾取事件要先于地图单击事件，若拾取不成功则会响应地图事件
 *
 *  @param node              被拾取到的节点元素
 *  @param layer             被拾取到的节点所在的层
 *  @param gestureRecognizer 触发的手势
 */
- (void)onMapClickNode:(FMKNode *)node inLayer:(FMKLayer *)layer gestureRecognizer:(UIGestureRecognizer *)gestureRecognizer;

@end
