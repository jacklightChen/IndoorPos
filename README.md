# IndoorPos
### 简介
该项目为本人实习期间的项目 内容为基于ibeacon的AR室内定位导航

### 使用技术
... | ... 
:---:|:---
语言|Objective-C swift
扫描ibeacon | [brightSDK](https://github.com/BrightBeacon/BrightBeacon_iOS_SDK)
定位 | [最小二乘法三点定位](http://www.docin.com/p-813893113.html)
地图 | [蜂鸟云地图sdk](https://www.fengmap.com/develop-ios-guide.html)
AR | ARKit

### 项目结构
```
├──BrightSDK (智石科技扫描蓝牙sdk)
├──FMBundle.bundle (蜂鸟云地图的资源包)
├──FMMapKit (蜂鸟云地图sdk）
├──location.xcodeproj
├──location	
	├── AppDelegate
	│   ├── AppDelegate.h
	│   ├── AppDelegate.m (配置蜂鸟云appkey)
	├── Assets.xcassets
	├── Base.lproj
	├── Controller
	│   ├── ARViewController.h 
	│   ├── ARViewController.m (AR场景)
	│   ├── BRTBeaconScan.h 
	│   ├── BRTBeaconScan.m (扫描ibeacon并设置每个ibeacon放置的位置 在回调中保存全局定位点)
	│   ├── BRTViewController.h (已弃用)
	│   ├── BRTViewController.m (已弃用)
	│   ├── BeaconViewController.h (已弃用)
	│   ├── BeaconViewController.mm (已弃用)
	│   ├── MapViewController.h
	│   ├── MapViewController.m (提供2D地图的操作)
	│   ├── ViewController.h (已弃用)
	│   └── ViewController.m (已弃用)
	├── Info.plist 
	├── MapData
	│   ├── 10347.fmap
	│   ├── cmbintern.fmap (专门绘制的办公室地图)
	│   ├── xierqisubway
	├── Model
	│   ├── Coordination.h 
	│   ├── Coordination.m (坐标包装类)
	│   ├── IbeaconInfo.h (已弃用)
	│   └── IbeaconInfo.m (已弃用)
	├── Swift
	│   └── location-Bridging-Header.h
	├── Util
	│   ├── Location.swift (最小二乘法三边定位算法)
	│   ├── LocationUtil.h (已弃用)
	│   └── LocationUtil.mm (C++矩阵库编写有冲突已弃用)
	├── art.scnassets
	│   ├── arrow.dae (AR需要用到的箭头)
	│   └── arrow.scn
	└── main.m
```

### 使用说明
clone项目
在console中执行pod install
打开xcode用location.xcworkspace打开项目
需要先按步骤接入fengmap(引入几个系统静态库):https://www.fengmap.com/develop-ios-guide-environment.html

### 项目展示
只有三个ibeacon时的定位demo:
![定位](https://github.com/jacklightChen/IndoorPos/blob/master/demopicture/point.png)
办公室地图:
![办公室](https://github.com/jacklightChen/IndoorPos/blob/master/demopicture/office.jpg)
项目2D效果 左图片右gif:
<div align=left><img width="375" height="667" src="https://github.com/jacklightChen/IndoorPos/blob/master/demopicture/show.png"/>
<img width="375" height="667" src="https://github.com/jacklightChen/IndoorPos/blob/master/demopicture/demo.gif"/></div>
