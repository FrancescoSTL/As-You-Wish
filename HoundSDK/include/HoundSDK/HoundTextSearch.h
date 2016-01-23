//
//  HoundTextSearch.h
//  HoundSDK
//
//  Created by Cyril Austin on 5/20/15.
//  Copyright (c) 2015 SoundHound, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "HoundSDKServerDataModels.h"

#pragma mark - Callbacks

typedef void (^HoundTextSearchCallback)(NSError* error, NSString* query,
    HoundDataHoundServer* houndServer, NSDictionary* dictionary);

#pragma mark - HoundTextSearch

@interface HoundTextSearch : NSObject

+ (instancetype)instance;

- (void)searchWithQuery:(NSString*)query
    requestInfo:(NSDictionary*)requestInfo
    endPointURL:(NSURL*)endPointURL
    completionHandler:(HoundTextSearchCallback)handler;

- (void)cancelSearch;

@end
