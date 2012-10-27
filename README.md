ImageCacheResize
=========

This library integrates two existing works:

- [SDWebImage](https://github.com/rs/SDWebImage): It is an excellent work that provides (Async image downloader, cache on memory, cache on disk, great performance).
- [UIImage+Resize](https://github.com/coryalder/UIImage_Resize):  By Trevor Harmon. Also, an improvement to this library is used. It is described [here](http://smallduck.wordpress.com/2010/01/14/improvement-to-uiimageplusresize-m/). The original post describing image scaling, resizing and cropping is [http://vocaro.com/trevor/blog/2009/10/12/resize-a-uiimage-the-right-way/](http://vocaro.com/trevor/blog/2009/10/12/resize-a-uiimage-the-right-way/).


The project is a single view iOS project that shows some of the transformations that can be done. Specially one of them is very useful and hard to achieve using remote images: When the developer wants to show a remote image that need to be shown with a specific width and height but must preserve the aspect ratio. The solution is something described by Trevor, which is to shrink the content just enough to fit the smaller dimension within the view. Some parts of the images are cropped and the dimensions of the UIImageView can be anticipated. In order to achieve this effect the dimensions of the original file should be known (which can be done by reading the first bytes of data, there several posts about this on StackOverflow). 


New methods
----------
New methods were added to UIImageView (additionally to the methods added by the original SDWebImage version).

```objective-c

- (void)setImageWithURL:(NSURL *)url andCropToBounds:(CGRect)bounds;

- (void)setImageWithURL:(NSURL *)url andResize:(CGSize)size withContentMode:(UIViewContentMode)mode;

- (void)setImageWithURL:(NSURL *)url placeholderImage:(UIImage *)placeholder andCropToBounds:(CGRect)bounds;

- (void)setImageWithURL:(NSURL *)url placeholderImage:(UIImage *)placeholder options:(SDWebImageOptions)options  andResize:(CGSize)size;

- (void)setImageWithURL:(NSURL *)url placeholderImage:(UIImage *)placeholder options:(SDWebImageOptions)options  andResize:(CGSize)size withContentMode:(UIViewContentMode)mode;

- (void)setImageWithURL:(NSURL *)url placeholderImage:(UIImage *)placeholder options:(SDWebImageOptions)options  andCropToBounds:(CGRect)bounds;

```

How to integrate into your project
----------

- Copy SDWebImage and UIImage+Resize folders content to your project. 
- Add the frameworks ImageIO.framework and MapKit.framework
- Import UIImageView+WebCache.h. 


How to use
----------
Here are some examples using images in google:

```objective-c

[imageview setImageWithURL:[NSURL URLWithString:@"http://t0.gstatic.com/images?q=tbn:ANd9GcQfraHpiabjEY8iDdBe9OUQYHMtwfuAv9ZRR0RYKuoVF_EpE8Fp5A"] andResize:CGSizeMake(30, 30) withContentMode:UIViewContentModeScaleAspectFit];


[imageview setImageWithURL:[NSURL URLWithString:@"http://t0.gstatic.com/images?q=tbn:ANd9GcQfraHpiabjEY8iDdBe9OUQYHMtwfuAv9ZRR0RYKuoVF_EpE8Fp5A"] andCropToBounds:CGRectMake(0, 0, 100, 100)];

```


This project include some examples. Just clone and execute it.
