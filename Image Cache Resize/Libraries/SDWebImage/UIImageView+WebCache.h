/*
 * This file is part of the SDWebImage package.
 * (c) Olivier Poitrey <rs@dailymotion.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

#import "SDWebImageCompat.h"
#import "SDWebImageManagerDelegate.h"
#import "SDWebImageManager.h"

/**
 * Integrates SDWebImage async downloading and caching of remote images with UIImageView.
 *
 * Usage with a UITableViewCell sub-class:
 *
 * 	#import <SDWebImage/UIImageView+WebCache.h>
 * 	
 * 	...
 * 	
 * 	- (UITableViewCell *)tableView:(UITableView *)tableView
 * 	         cellForRowAtIndexPath:(NSIndexPath *)indexPath
 * 	{
 * 	    static NSString *MyIdentifier = @"MyIdentifier";
 * 	
 * 	    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:MyIdentifier];
 * 	
 * 	    if (cell == nil)
 * 	    {
 * 	        cell = [[[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault
 * 	                                       reuseIdentifier:MyIdentifier] autorelease];
 * 	    }
 * 	
 * 	    // Here we use the provided setImageWithURL: method to load the web image
 * 	    // Ensure you use a placeholder image otherwise cells will be initialized with no image
 * 	    [cell.imageView setImageWithURL:[NSURL URLWithString:@"http://example.com/image.jpg"]
 * 	                   placeholderImage:[UIImage imageNamed:@"placeholder"]];
 * 	
 * 	    cell.textLabel.text = @"My Text";
 * 	    return cell;
 * 	}
 * 	
 */
@interface UIImageView (WebCache) <SDWebImageManagerDelegate>


/**
 * Set the imageView `image` with an `url`.
 *
 * The downloand is asynchronous and cached. After the image is downloaded the result image is cropped.
 *
 * @param url The url for the image.
 * @param bounds Bounds of the cropped image.
 */
- (void)setImageWithURL:(NSURL *)url andCropToBounds:(CGRect)bounds;


/**
 * Set the imageView `image` with an `url`.
 *
 * The downloand is asynchronous and cached. After the image is downloaded the result image is cropped.
 *
 * @param url The url for the image.
 * @param size Resize the downloaded image to the specified size
 */
- (void)setImageWithURL:(NSURL *)url andResize:(CGSize)size;

/**
 * Set the imageView `image` with an `url`.
 *
 * The downloand is asynchronous and cached. After the image is downloaded the result image is cropped.
 *
 * @param url The url for the image.
 * @param bounds Bounds of the cropped image.
 * @param size Resize the downloaded image to the specified size
 * @param mode Content mode of the resize strategy. Can be UIViewContentModeScaleAspectFill or UIViewContentModeScaleAspectFit
 */
- (void)setImageWithURL:(NSURL *)url andResize:(CGSize)size withContentMode:(UIViewContentMode)mode;


/**
 * Set the imageView `image` with an `url`.
 *
 * The downloand is asynchronous and cached.
 *
 * @param url The url for the image.
 */
- (void)setImageWithURL:(NSURL *)url;



/**
 * Set the imageView `image` with an `url` and a placeholder.
 *
 * The downloand is asynchronous and cached. After the image is downloaded the result image is cropped.
 *
 * @param url The url for the image.
 * @param placeholder The image to be set initially, until the image request finishes.
 * @param bounds Bounds of the cropped image.
 * @see setImageWithURL:placeholderImage:options:andCropToBounds:
 */
- (void)setImageWithURL:(NSURL *)url placeholderImage:(UIImage *)placeholder andCropToBounds:(CGRect)bounds;



/**
 * Set the imageView `image` with an `url` and a placeholder.
 *
 * The downloand is asynchronous and cached. After the image is downloaded the result image is cropped.
 *
 * @param url The url for the image.
 * @param placeholder The image to be set initially, until the image request finishes.
 * @param size Resize the downloaded image to the specified size
 * @see setImageWithURL:placeholderImage:options:andResize:
 */
- (void)setImageWithURL:(NSURL *)url placeholderImage:(UIImage *)placeholder options:(SDWebImageOptions)options  andResize:(CGSize)size;

/**
 * Set the imageView `image` with an `url` and a placeholder.
 *
 * The downloand is asynchronous and cached. After the image is downloaded the result image is cropped.
 *
 * @param url The url for the image.
 * @param placeholder The image to be set initially, until the image request finishes.
 * @param size Resize the downloaded image to the specified size
 * @param mode Content mode of the resize strategy. Can be UIViewContentModeScaleAspectFill or UIViewContentModeScaleAspectFit
 * @see setImageWithURL:placeholderImage:options:andResize:withContentMode:
 */
- (void)setImageWithURL:(NSURL *)url placeholderImage:(UIImage *)placeholder options:(SDWebImageOptions)options  andResize:(CGSize)size withContentMode:(UIViewContentMode)mode;



/**
 * Set the imageView `image` with an `url` and a placeholder.
 *
 * The downloand is asynchronous and cached.
 *
 * @param url The url for the image.
 * @param placeholder The image to be set initially, until the image request finishes.
 * @see setImageWithURL:placeholderImage:options:
 */
- (void)setImageWithURL:(NSURL *)url placeholderImage:(UIImage *)placeholder;


/**
 * Set the imageView `image` with an `url`, placeholder and custom options.
 *
 * The downloand is asynchronous and cached. After the image is downloaded the result image is cropped.
 *
 * @param url The url for the image.
 * @param placeholder The image to be set initially, until the image request finishes.
 * @param options The options to use when downloading the image. @see SDWebImageOptions for the possible values.
 * @param bounds Bounds of the cropped image.
 */
- (void)setImageWithURL:(NSURL *)url placeholderImage:(UIImage *)placeholder options:(SDWebImageOptions)options  andCropToBounds:(CGRect)bounds;


/**
 * Set the imageView `image` with an `url`, placeholder and custom options.
 *
 * The downloand is asynchronous and cached.
 *
 * @param url The url for the image.
 * @param placeholder The image to be set initially, until the image request finishes.
 * @param options The options to use when downloading the image. @see SDWebImageOptions for the possible values.
 */
- (void)setImageWithURL:(NSURL *)url placeholderImage:(UIImage *)placeholder options:(SDWebImageOptions)options;

#if NS_BLOCKS_AVAILABLE
/**
 * Set the imageView `image` with an `url`.
 *
 * The downloand is asynchronous and cached.
 *
 * @param url The url for the image.
 * @param success A block to be executed when the image request succeed This block has no return value and takes the retrieved image as argument.
 * @param failure A block object to be executed when the image request failed. This block has no return value and takes the error object describing the network or parsing error that occurred (may be nil).
 */
- (void)setImageWithURL:(NSURL *)url success:(SDWebImageSuccessBlock)success failure:(SDWebImageFailureBlock)failure;

/**
 * Set the imageView `image` with an `url`, placeholder.
 *
 * The downloand is asynchronous and cached.
 *
 * @param url The url for the image.
 * @param placeholder The image to be set initially, until the image request finishes.
 * @param success A block to be executed when the image request succeed This block has no return value and takes the retrieved image as argument.
 * @param failure A block object to be executed when the image request failed. This block has no return value and takes the error object describing the network or parsing error that occurred (may be nil).
 */
- (void)setImageWithURL:(NSURL *)url placeholderImage:(UIImage *)placeholder success:(SDWebImageSuccessBlock)success failure:(SDWebImageFailureBlock)failure;

/**
 * Set the imageView `image` with an `url`, placeholder and custom options.
 *
 * The downloand is asynchronous and cached.
 *
 * @param url The url for the image.
 * @param placeholder The image to be set initially, until the image request finishes.
 * @param options The options to use when downloading the image. @see SDWebImageOptions for the possible values.
 * @param success A block to be executed when the image request succeed This block has no return value and takes the retrieved image as argument.
 * @param failure A block object to be executed when the image request failed. This block has no return value and takes the error object describing the network or parsing error that occurred (may be nil).
 */
- (void)setImageWithURL:(NSURL *)url placeholderImage:(UIImage *)placeholder options:(SDWebImageOptions)options success:(SDWebImageSuccessBlock)success failure:(SDWebImageFailureBlock)failure;
#endif

/**
 * Cancel the current download
 */
- (void)cancelCurrentImageLoad;

@end
