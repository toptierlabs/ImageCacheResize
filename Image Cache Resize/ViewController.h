//
//  ViewController.h
//  Image Cache Resize
//
//  Created by TopTier on 10/26/12.
//  Copyright (c) 2012 TopTier. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface ViewController : UIViewController{

    IBOutlet UIScrollView *scroller;
    
    IBOutlet UIImageView *image1;
    IBOutlet UIImageView *image2;
    IBOutlet UIImageView *image3;

}

@property(nonatomic, retain) UIScrollView *scroller;

@property(nonatomic, retain) UIImageView *image1;
@property(nonatomic, retain) UIImageView *image2;
@property(nonatomic, retain) UIImageView *image3;


@end
