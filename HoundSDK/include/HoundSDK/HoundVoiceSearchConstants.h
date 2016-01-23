//
//  HoundVoiceSearchConstants.h
//  HoundSDK
//
//  Created by Cyril Austin on 10/9/15.
//  Copyright © 2015 SoundHound, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

#pragma mark - Notifications

extern NSString* HoundVoiceSearchStateChangeNotification;
extern NSString* HoundVoiceSearchHotPhraseNotification;
extern NSString* HoundVoiceSearchAudioLevelNotification;
extern NSString* HoundVoiceSearchFinalTranscriptionNotification;

#pragma mark - Errors

extern NSString* HoundVoiceSearchErrorDomain;

#pragma mark - HoundVoiceSearchErrorCode

typedef NS_ENUM(NSUInteger, HoundVoiceSearchErrorCode)
{
    HoundVoiceSearchErrorCodeNone,
    HoundVoiceSearchErrorCodeCancelled,
    HoundVoiceSearchErrorCodeNotReady,
    HoundVoiceSearchErrorCodeServerStatusError,
    HoundVoiceSearchErrorCodeNoResponseReceived,
    HoundVoiceSearchErrorCodeInvalidResponse,
    HoundVoiceSearchErrorCodeAudioInterrupted,
    HoundVoiceSearchErrorCodeParseFailed,
    HoundVoiceSearchErrorCodeAuthenticationFailed,
    HoundVoiceSearchErrorCodeInternalError,
    HoundVoiceSearchErrorCodePermissionDenied,
    HoundVoiceSearchErrorCodeConnectionFailure,
    HoundVoiceSearchErrorCodeConnectionTimeout,
};

#pragma mark - HoundVoiceSearchState

typedef NS_ENUM(NSUInteger, HoundVoiceSearchState)
{
    HoundVoiceSearchStateNone,
    HoundVoiceSearchStateReady,
    HoundVoiceSearchStateRecording,
    HoundVoiceSearchStateSearching,
    HoundVoiceSearchStateSpeaking
};
