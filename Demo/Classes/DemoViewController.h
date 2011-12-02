//
//  DemoViewController.h
//  Demo
//
//  Created by Sixten Otto on 3/31/10.
//  Copyright Results Direct 2010. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "RDLinkedInEngineDelegate.h"
#import "RDLinkedInAuthorizationControllerDelegate.h"


@interface DemoViewController : UIViewController <RDLinkedInEngineDelegate, RDLinkedInAuthorizationControllerDelegate>
{
}

@property (nonatomic, retain) IBOutlet UILabel *statusLabel;
@property (nonatomic, retain) IBOutlet UIButton *logInButton;
@property (nonatomic, retain) IBOutlet UIButton *logOutButton;
@property (nonatomic, retain) IBOutlet UILabel *connectionsLabel;
@property (nonatomic, retain) IBOutlet UIButton *getConnectionsButton;

- (IBAction)logIn:(id)sender;
- (IBAction)logOut:(id)sender;
- (IBAction)getConnections:(id)sender;

-(void)fetchConnections;

@end

