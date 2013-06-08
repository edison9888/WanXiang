//
// SVSegmentedThumb.h
// SVSegmentedControl
//
// Created by Sam Vermette on 25.05.11.
// Copyright 2011 Sam Vermette. All rights reserved.
//
// https://github.com/samvermette/SVSegmentedControl
//

#import <UIKit/UIKit.h>

@class SVSegmentedControl;

@interface SVSegmentedThumb : UIView

@property (nonatomic, retain) UIImage *backgroundImage; // default is nil;
@property (nonatomic, retain) UIImage *highlightedBackgroundImage; // default is nil;

@property (nonatomic, retain) UIColor *tintColor; // default is [UIColor grayColor]
@property (nonatomic, retain) UIColor *textColor; // default is [UIColor whiteColor]
@property (nonatomic, retain) UIColor *textShadowColor; // default is [UIColor blackColor]
@property (nonatomic, readwrite) CGSize textShadowOffset; // default is CGSizeMake(0, -1)
@property (nonatomic, readwrite) BOOL shouldCastShadow; // default is YES (NO when backgroundImage is set)

-(void)setTitleData:(id)title;
// deprecated properties
@property (nonatomic, retain) UIColor *shadowColor DEPRECATED_ATTRIBUTE; // use textShadowColor instead
@property (nonatomic, readwrite) CGSize shadowOffset DEPRECATED_ATTRIBUTE; // use textShadowOffset instead
@property (nonatomic, readwrite) BOOL castsShadow DEPRECATED_ATTRIBUTE; // use shouldCastShadow instead

@end
