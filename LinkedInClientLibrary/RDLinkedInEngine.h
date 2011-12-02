//
//  RDLinkedInEngine.h
//  LinkedInClientLibrary
//
//  Created by Sixten Otto on 12/30/09.
//  Copyright 2010 Results Direct. All rights reserved.
//
//  Significant inspiration and code from MGTwitterEngine by Matt Gemmell
//    and the OAuth enhancements to same by Ben Gottlieb
//  <http://mattgemmell.com/source#mgtwitterengine>
//  <http://github.com/bengottlieb/Twitter-OAuth-iPhone>
//

#import <Foundation/Foundation.h>

#import "RDLinkedInTypes.h"
#import "RDLinkedInEngineDelegate.h"
#import "RDLinkedInHTTPURLConnection.h"

@class OAConsumer;
@class OAToken;


extern NSString *const RDLinkedInEngineRequestTokenNotification;
extern NSString *const RDLinkedInEngineAccessTokenNotification;
extern NSString *const RDLinkedInEngineTokenInvalidationNotification;
extern NSString *const RDLinkedInEngineAuthFailureNotification;
extern NSString *const RDLinkedInEngineTokenKey;

extern const NSUInteger kRDLinkedInMaxStatusLength;


@interface RDLinkedInEngine : NSObject {
  id<RDLinkedInEngineDelegate> rdDelegate;
  OAConsumer* rdOAuthConsumer;
  OAToken*    rdOAuthRequestToken;
  OAToken*    rdOAuthAccessToken;
  NSString*   rdOAuthVerifier;
  NSMutableDictionary* rdConnections;
}

@property (nonatomic, readonly) BOOL isAuthorized;
@property (nonatomic, readonly) BOOL hasRequestToken;
@property (nonatomic, retain) NSString* verifier;

+ (id)engineWithConsumerKey:(NSString *)consumerKey consumerSecret:(NSString *)consumerSecret delegate:(id<RDLinkedInEngineDelegate>)delegate;
- (id)initWithConsumerKey:(NSString *)consumerKey consumerSecret:(NSString *)consumerSecret delegate:(id<RDLinkedInEngineDelegate>)delegate;

// connection management
- (NSUInteger)numberOfConnections;
- (NSArray *)connectionIdentifiers;
- (RDLinkedInHTTPURLConnection *)connectionWithID:(RDLinkedInConnectionID *)identifier;
- (void)closeConnectionWithID:(RDLinkedInConnectionID *)identifier;
- (void)closeAllConnections;

// authorization
- (void)requestRequestToken;
- (void)requestAccessToken;
- (void)requestTokenInvalidation;
- (NSURLRequest *)authorizationFormURLRequest;

// API methods
- (RDLinkedInConnectionID *)profileForCurrentUser;
- (RDLinkedInConnectionID *)profileForPersonWithID:(NSString *)memberID;

- (RDLinkedInConnectionID *)connectionsForCurrentUser;

- (RDLinkedInConnectionID *)updateStatus:(NSString *)newStatus;

@end
