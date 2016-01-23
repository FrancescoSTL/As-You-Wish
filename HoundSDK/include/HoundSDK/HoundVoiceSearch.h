//
//  HoundVoiceSearch.h
//  HoundSDK
//
//  Created by Cyril Austin on 5/20/15.
//  Copyright (c) 2015 SoundHound, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "HoundVoiceSearchConstants.h"
#import "HoundSDKServerDataModels.h"
#import "HoundServerPartialTranscriptDataModels.h"

#pragma mark - HoundVoiceSearchResponseType

typedef NS_ENUM(NSUInteger, HoundVoiceSearchResponseType)
{
    HoundVoiceSearchResponseTypeNone,
    HoundVoiceSearchResponseTypePartialTranscription,
    HoundVoiceSearchResponseTypeHoundServer
};

#pragma mark - Callbacks

typedef void (^HoundVoiceSearchErrorCallback)(NSError* error);
typedef void (^HoundVoiceSearchResponseCallback)(NSError* error,
    HoundVoiceSearchResponseType responseType, id response,
    NSDictionary* dictionary);

#pragma mark - HoundVoiceSearch

@interface HoundVoiceSearch : NSObject

@property(nonatomic, assign, readonly) HoundVoiceSearchState state;

@property(atomic, assign) BOOL enableHotPhraseDetection;
@property(atomic, assign) BOOL enableEndOfSpeechDetection;
@property(atomic, assign) BOOL enableSpeech;

+ (instancetype)instance;

// Setup raw mode

- (void)setupRawModeWithInputSampleRate:(double)inputSampleRate
    completionHandler:(HoundVoiceSearchErrorCallback)handler;

// Automatic search methods

- (void)startListeningWithCompletionHandler:(HoundVoiceSearchErrorCallback)handler;
- (void)stopListeningWithCompletionHandler:(HoundVoiceSearchErrorCallback)handler;

// Voice search

- (void)startSearchWithRequestInfo:(NSDictionary*)requestInfo
    endPointURL:(NSURL*)endPointURL
    responseHandler:(HoundVoiceSearchResponseCallback)responseHandler;

- (void)writeRawAudioData:(NSData*)data;

// General methods

- (void)stopSearch;
- (void)cancelSearch;

- (void)stopSpeaking;

@end