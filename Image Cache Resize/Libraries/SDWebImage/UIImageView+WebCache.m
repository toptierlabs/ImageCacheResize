/*
 * This file is part of the SDWebImage package.
 * (c) Olivier Poitrey <rs@dailymotion.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

#import "UIImageView+WebCache.h"

@implementation UIImageView (WebCache)


- (void)setImageWithURL:(NSURL *)url andCropToBounds:(CGRect)bounds
{
    [self setImageWithURL:url placeholderImage:nil options:0 andCropToBounds: bounds];
}

- (void)setImageWithURL:(NSURL *)url andResize:(CGSize)size
{
    [self setImageWithURL:url placeholderImage:nil options:0 andResize:size];
}

- (void)setImageWithURL:(NSURL *)url andResize:(CGSize)size withContentMode:(UIViewContentMode)mode
{
    [self setImageWithURL:url placeholderImage:nil options:0 andResize:size withContentMode:mode];
}

- (void)setImageWithURL:(NSURL *)url
{
    [self setImageWithURL:url placeholderImage:nil];
}

- (void)setImageWithURL:(NSURL *)url placeholderImage:(UIImage *)placeholder
{
    [self setImageWithURL:url placeholderImage:placeholder options:0];
}


- (void)setImageWithURL:(NSURL *)url placeholderImage:(UIImage *)placeholder options:(SDWebImageOptions)options  andCropToBounds:(CGRect)bounds;
{
    SDWebImageManager *manager = [SDWebImageManager sharedManager];
    
    // Remove in progress downloader from queue
    [manager cancelForDelegate:self];
    
    self.image = placeholder;
    
    NSDictionary *userInfo = [NSDictionary dictionaryWithObjectsAndKeys:@"crop", @"transformation",
                              NSStringFromCGRect(bounds), @"bounds", nil];
    
    if (url)
    {
        [manager downloadWithURL:url delegate:self options:options userInfo:userInfo];
    }
}

- (void)setImageWithURL:(NSURL *)url placeholderImage:(UIImage *)placeholder options:(SDWebImageOptions)options  andResize:(CGSize)size
{
    SDWebImageManager *manager = [SDWebImageManager sharedManager];
    
    // Remove in progress downloader from queue
    [manager cancelForDelegate:self];
    
    self.image = placeholder;
    
    NSDictionary *userInfo = [NSDictionary dictionaryWithObjectsAndKeys:@"resize", @"transformation",
                              NSStringFromCGSize(size), @"size", nil];
    
    if (url)
    {
        [manager downloadWithURL:url delegate:self options:options userInfo:userInfo];
    }
}

- (void)setImageWithURL:(NSURL *)url placeholderImage:(UIImage *)placeholder options:(SDWebImageOptions)options  andResize:(CGSize)size withContentMode:(UIViewContentMode)mode
{
    SDWebImageManager *manager = [SDWebImageManager sharedManager];
    
    // Remove in progress downloader from queue
    [manager cancelForDelegate:self];
    
    self.image = placeholder;
    
    
    NSString *mode_str = nil;
    
    if (mode == UIViewContentModeScaleAspectFit)
    {
        mode_str = @"UIViewContentModeScaleAspectFit";
    }
    else
    {
        if (mode == UIViewContentModeScaleAspectFill)
        {
            mode_str = @"UIViewContentModeScaleAspectFill";
        }
    }

    NSDictionary *userInfo = [NSDictionary dictionaryWithObjectsAndKeys:@"resize", @"transformation",
                              NSStringFromCGSize(size), @"size",
                              mode_str, @"content_mode", nil];
    
    if (url)
    {
        [manager downloadWithURL:url delegate:self options:options userInfo:userInfo];
    }
}


- (void)setImageWithURL:(NSURL *)url placeholderImage:(UIImage *)placeholder options:(SDWebImageOptions)options
{
    SDWebImageManager *manager = [SDWebImageManager sharedManager];

    // Remove in progress downloader from queue
    [manager cancelForDelegate:self];

    self.image = placeholder;

    if (url)
    {
        [manager downloadWithURL:url delegate:self options:options];
    }
}

#if NS_BLOCKS_AVAILABLE
- (void)setImageWithURL:(NSURL *)url success:(SDWebImageSuccessBlock)success failure:(SDWebImageFailureBlock)failure;
{
    [self setImageWithURL:url placeholderImage:nil success:success failure:failure];
}

- (void)setImageWithURL:(NSURL *)url placeholderImage:(UIImage *)placeholder success:(SDWebImageSuccessBlock)success failure:(SDWebImageFailureBlock)failure;
{
    [self setImageWithURL:url placeholderImage:placeholder options:0 success:success failure:failure];
}

- (void)setImageWithURL:(NSURL *)url placeholderImage:(UIImage *)placeholder options:(SDWebImageOptions)options success:(SDWebImageSuccessBlock)success failure:(SDWebImageFailureBlock)failure;
{
    SDWebImageManager *manager = [SDWebImageManager sharedManager];

    // Remove in progress downloader from queue
    [manager cancelForDelegate:self];

    self.image = placeholder;

    if (url)
    {
        [manager downloadWithURL:url delegate:self options:options success:success failure:failure];
    }
}
#endif

- (void)cancelCurrentImageLoad
{
    [[SDWebImageManager sharedManager] cancelForDelegate:self];
}

- (void)webImageManager:(SDWebImageManager *)imageManager didProgressWithPartialImage:(UIImage *)image forURL:(NSURL *)url
{
    self.image = image;
    [self setNeedsLayout];
}

- (void)webImageManager:(SDWebImageManager *)imageManager didFinishWithImage:(UIImage *)image
{
    self.image = image;
    [self setNeedsLayout];
}

@end
