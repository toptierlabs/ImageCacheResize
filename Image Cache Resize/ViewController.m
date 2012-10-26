//
//  ViewController.m
//  Image Cache Resize
//
//  Created by TopTier on 10/26/12.
//  Copyright (c) 2012 TopTier. All rights reserved.
//

#import "ViewController.h"

@interface ViewController ()

@end

@implementation ViewController
@synthesize scroller;

- (void)viewDidLoad
{
    [super viewDidLoad];
	// Do any additional setup after loading the view, typically from a nib.
    
    
    [scroller setContentSize:CGSizeMake(320, 2000)];
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
