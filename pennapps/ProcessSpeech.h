//
//  ProcessSpeech.h
//  pennapps
//
//  Created by Francesco Polizzi on 1/23/16.
//  Copyright © 2016 Francesco Polizzi. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "../HoundSDK/include/HoundSDK/HoundSDK.h"

@import AVFoundation;

@interface ProcessSpeech : NSObject

- (void)start:(void (^)(id))firstCompletionHandler;
- (void)startSearchWithCompletionHandler:(void (^)(id))completionHandler;
- (NSString*)returnIntent;
@property NSString *intent;
@property dispatch_semaphore_t sema;

@end
