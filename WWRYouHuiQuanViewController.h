//
//  WWRYouHuiQuanViewController.h
//  wanxiangerweima
//
//  Created by mac on 13-4-3.
//  Copyright 2013 __MyCompanyName__. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "WWRYHLFatherViewController.h"
#import "WWRWXBEngine.h"

@interface WWRYouHuiQuanViewController : WWRYHLFatherViewController<WWRWXBEnginePreQRListDelegate,UIAlertViewDelegate>

{
	WWRWXBEngine   *_engine;
    NSArray        *_statuesArray;
	
}
@property (nonatomic,retain) NSArray  *statuesArray;

@end
