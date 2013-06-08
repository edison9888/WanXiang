//
//  LGHelpViewController.m
//  wanxiangerweima
//
//  Created by LG on 13-4-15.
//  Copyright 2013 __MyCompanyName__. All rights reserved.
//

#import "LGHelpViewController.h"
#import "LGHelp2ViewController.h"
#import "LYGScanViewController.h"
@implementation LGHelpViewController
@synthesize helpView = _helpView;

// The designated initializer.  Override if you create the controller programmatically and want to perform customization that is not appropriate for viewDidLoad.
/*
- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil {
    self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];
    if (self) {
        // Custom initialization.
    }
    return self;
}
*/


// Implement viewDidLoad to do additional setup after loading the view, typically from a nib.
- (void)viewDidLoad {
    [super viewDidLoad];
	[self.myTableView reloadData];
	self.helpView.hidden = YES;
}


/*
// Override to allow orientations other than the default portrait orientation.
- (BOOL)shouldAutorotateToInterfaceOrientation:(UIInterfaceOrientation)interfaceOrientation {
    // Return YES for supported orientations.
    return (interfaceOrientation == UIInterfaceOrientationPortrait);
}
*/

- (IBAction) back
{
	[self.navigationController popViewControllerAnimated:YES];
}

- (IBAction) btnClick:(id)sender
{
	UIButton *btn = (UIButton *)sender;
	LGHelp2ViewController *help2VC = [[LGHelp2ViewController alloc] init];
	help2VC.helpindex = btn.tag;
	[self.navigationController pushViewController:help2VC animated:YES];
	[help2VC release];
	
}

- (void)didReceiveMemoryWarning {
    // Releases the view if it doesn't have a superview.
    [super didReceiveMemoryWarning];
    
    // Release any cached data, images, etc. that aren't in use.
}

- (void)viewDidUnload {
    [self setMyTableView:nil];
    [super viewDidUnload];
    // Release any retained subviews of the main view.
    // e.g. self.myOutlet = nil;
}


- (void)dealloc 
{
	[_helpView release];
    [_myTableView release];
    [super dealloc];
}
- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section
{
	return [_myArry count];
}
- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath
{
	static NSString *cellIdentifer = @"CellIdentifier";
	
	UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:cellIdentifer];
	HelpClass * class = [self.myArry objectAtIndex:indexPath.row];
    NSLog(@"%@",class.title);
	if (!cell)
	{
        cell = [[UITableViewCell alloc]initWithStyle:UITableViewCellStyleDefault reuseIdentifier:cellIdentifer];
        cell.textLabel.text  = class.title;
        return [cell autorelease];
    }else{
        cell.textLabel.text  = class.title;
        return cell;
    }    
    
}
- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath
{
    HelpClass * class = [self.myArry objectAtIndex:indexPath.row];
    LGHelp2ViewController * temp = [[LGHelp2ViewController alloc]init];
    temp.contents     = class.Contents;
    NSLog(@"%@",temp.contents);
    [self.navigationController pushViewController:temp animated:YES];
}




@end
