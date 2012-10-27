//
//  ViewController.m
//  Image Cache Resize
//
//  Created by TopTier on 10/26/12.
//  Copyright (c) 2012 TopTier. All rights reserved.
//

#import "ViewController.h"
#import "UIImageView+WebCache.h"

@interface ViewController ()
-(CGSize) SizeForCrop: (float) image_width
          imageHeight:(float) image_height
          containerWidth: (float)container_width
          containerHeight: (float) container_width;
@end

@implementation ViewController
@synthesize scroller, image1, image2, image3;

-(CGSize) SizeForCrop: (float) image_width
          imageHeight:(float) image_height
       containerWidth: (float)container_width
      containerHeight: (float) container_height{
    
    float image_ratio = container_height/ container_width;
    float crop_width, crop_height;
    if (image_width / image_ratio > image_height)
    {
        // crop width
        crop_height = image_height;
        crop_width = image_height / image_ratio;
    }
    else
    {
        // crop height
        crop_width = image_width;;
        crop_height = image_width / image_ratio;
        
    }
    
    return CGSizeMake(crop_width, crop_height);
}

- (void)viewDidLoad
{
    [super viewDidLoad];
	// Do any additional setup after loading the view, typically from a nib.
    
    
    [scroller setContentSize:CGSizeMake(320, 2000)];

    [image2 setImageWithURL:[NSURL URLWithString:@"http://t0.gstatic.com/images?q=tbn:ANd9GcQfraHpiabjEY8iDdBe9OUQYHMtwfuAv9ZRR0RYKuoVF_EpE8Fp5A"] andResize:CGSizeMake(30, 30) withContentMode:UIViewContentModeScaleAspectFit];
    [image3 setImageWithURL:[NSURL URLWithString:@"http://t0.gstatic.com/images?q=tbn:ANd9GcQfraHpiabjEY8iDdBe9OUQYHMtwfuAv9ZRR0RYKuoVF_EpE8Fp5A"]];
  
    
    
    float image_width = 300;
    float image_height = 168;
    
    float container_width = 119;
    float container_height = 112;
    
    CGSize cropsize = [self SizeForCrop:image_width imageHeight:image_height containerWidth:container_width containerHeight:container_height];
    
    [image1 setImageWithURL:[NSURL URLWithString:@"http://t0.gstatic.com/images?q=tbn:ANd9GcQfraHpiabjEY8iDdBe9OUQYHMtwfuAv9ZRR0RYKuoVF_EpE8Fp5A"] andCropToBounds:CGRectMake(0, 0, cropsize.width, cropsize.height)];
    
    
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
