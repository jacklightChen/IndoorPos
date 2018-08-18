//
//  ViewController.m
//  location
//
//  Created by 陈之豪 on 2018/7/24.
//  Copyright © 2018年 陈之豪. All rights reserved.
//

#import "ViewController.h"
#import "BeaconViewController.h"
#import "BRTViewController.h"
#import "BRTBeaconScan.h"
#import "MapViewController.h"
#import "ARViewController.h"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.

    ARViewController *ar=[ARViewController new];
    [self addChildViewController:ar];
    [self.view addSubview:ar.view];

}


- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}


@end
