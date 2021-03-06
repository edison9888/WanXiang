//
//  UIFolderTableView.h
//  top100
//
//  Created by Dai Cloud on 12-7-22.
//  Copyright (c) 2012年 __MyCompanyName__. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "FolderCoverView.h"

@class CAMediaTimingFunction;
@class UIFolderTableView;

typedef void (^FolderCompletionBlock)(void);
typedef void (^FolderCloseBlock)(UIView *subClassView, CFTimeInterval duration, CAMediaTimingFunction *timingFunction);
typedef void (^FolderOpenBlock)(UIView *subClassView, CFTimeInterval duration, CAMediaTimingFunction *timingFunction);

@protocol UIFolderTableViewDelegate <NSObject>

@optional
- (CGFloat)tableView:(UIFolderTableView *)tableView xForRowAtIndexPath:(NSIndexPath *)indexPath;

@end

@interface UIFolderTableView : UITableView

@property (retain, nonatomic) UIView *subClassContentView;
@property (assign, nonatomic) IBOutlet id<UIFolderTableViewDelegate> folderDelegate;
- (FolderCoverView *)buttonForRect:(CGRect)aRect
                            screen:(UIImage *)screen
                          position:(CGPoint)position
                               top:(BOOL)isTop
                       transparent:(BOOL)isTransparent;
- (void)openFolderAtIndexPath:(NSIndexPath *)indexPath
              WithContentView:(UIView *)subClassContentView
                    openBlock:(FolderOpenBlock)openBlock 
                   closeBlock:(FolderCloseBlock)closeBlock
              completionBlock:(FolderCompletionBlock)completionBlock;
- (void)performClose:(id)sender;
@end
