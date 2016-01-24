//
//  HProcessSpeech.h
//  pennapps
//
//  Created by Francesco Polizzi on 1/23/16.
//  Copyright © 2016 Francesco Polizzi. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "../HoundSDK/include/HoundSDK/HoundSDK.h"

@interface HProcessSpeech : NSObject

- (id)start;
- (void)startSearch;
- (NSString*)returnIntent

@end
