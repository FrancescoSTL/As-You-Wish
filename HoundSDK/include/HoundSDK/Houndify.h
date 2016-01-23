//
//  Houndify.h
//  HoundifySDK
//
//  Created by Cyril Austin on 10/29/15.
//  Copyright © 2015 SoundHound, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@class HoundDataHoundServer;

#pragma mark - Callbacks

typedef void (^HoundifyResponseCallback)(NSError* error, HoundDataHoundServer* response, NSDictionary* dictionary);
typedef void (^HoundifyCompletionHandler)(void);

#pragma mark - Houndify

@interface Houndify : NSObject

+ (instancetype)instance;

- (void)presentListeningViewControllerInViewController:(UIViewController*)presentingViewController
    fromView:(UIView*)presentingView
    requestInfo:(NSDictionary*)requestInfo
    endPointURL:(NSURL*)endPointURL
    responseHandler:(HoundifyResponseCallback)responseHandler;

- (void)dismissListeningViewControllerAnimated:(BOOL)animated
    completionHandler:(HoundifyCompletionHandler)completionHandler;
    
@end
