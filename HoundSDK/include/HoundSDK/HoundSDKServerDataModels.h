//
//  HoundSDKServerDataModels.h
//  SHHound
//
//  Created by Cyril MacDonald on 2015-06-05.
//  Copyright (c) 2015 SoundHound. All rights reserved.
//

#import "HoundDataModels.h"

#pragma mark - Forward declarations

@class HoundDataBuildInfo;
@class HoundDataCommandError;
@class HoundDataCommandResult;
@class HoundDataCommandResultArray;
@class HoundDataDynamicResponse;
@class HoundDataHints;
@class HoundDataHintsSpoken;
@class HoundDataHintsWritten;
@class HoundDataHintsWrittenHints;
@class HoundDataHintsWrittenHintsArray;
@class HoundDataHoundServer;
@class HoundDataHoundServerDisambiguation;
@class HoundDataHoundServerDisambiguationChoiceData;
@class HoundDataHoundServerDisambiguationChoiceDataArray;
@class HoundDataHTMLData;
@class HoundDataHTMLDataHTMLHead;
@class HoundDataPreview;
@class HoundDataTemplate;

#pragma mark - HoundDataCommandResultViewType

typedef NS_ENUM(NSUInteger, HoundDataCommandResultViewType) {
	HoundDataCommandResultViewTypeNone,
	HoundDataCommandResultViewTypeNative,
	HoundDataCommandResultViewTypeTemplate,
	HoundDataCommandResultViewTypeHTML,
	HoundDataCommandResultViewTypeError,
};

#pragma mark - HoundDataDynamicResponseViewType

typedef NS_ENUM(NSUInteger, HoundDataDynamicResponseViewType) {
	HoundDataDynamicResponseViewTypeNone,
	HoundDataDynamicResponseViewTypeNative,
	HoundDataDynamicResponseViewTypeTemplate,
	HoundDataDynamicResponseViewTypeHTML,
	HoundDataDynamicResponseViewTypeError,
};

#pragma mark - HoundDataEmotion

typedef NS_ENUM(NSUInteger, HoundDataEmotion) {
	HoundDataEmotionNone,
	HoundDataEmotionNeutral,
	HoundDataEmotionHappy,
	HoundDataEmotionSad,
	HoundDataEmotionAngry,
};

#pragma mark - HoundDataHintsSpokenPriority

typedef NS_ENUM(NSUInteger, HoundDataHintsSpokenPriority) {
	HoundDataHintsSpokenPriorityNone,
	HoundDataHintsSpokenPriorityLow,
	HoundDataHintsSpokenPriorityMedium,
	HoundDataHintsSpokenPriorityHigh,
};

#pragma mark - HoundDataHintsWrittenHintsPriority

typedef NS_ENUM(NSUInteger, HoundDataHintsWrittenHintsPriority) {
	HoundDataHintsWrittenHintsPriorityNone,
	HoundDataHintsWrittenHintsPriorityLow,
	HoundDataHintsWrittenHintsPriorityMedium,
	HoundDataHintsWrittenHintsPriorityHigh,
};

#pragma mark - HoundDataHoundServerFormat

typedef NS_ENUM(NSUInteger, HoundDataHoundServerFormat) {
	HoundDataHoundServerFormatNone,
	HoundDataHoundServerFormatSoundHoundVoiceSearchResult,
};

#pragma mark - HoundDataHoundServerFormatVersion

typedef NS_ENUM(NSUInteger, HoundDataHoundServerFormatVersion) {
	HoundDataHoundServerFormatVersionNone,
	HoundDataHoundServerFormatVersion10,
};

#pragma mark - HoundDataHoundServerStatus

typedef NS_ENUM(NSUInteger, HoundDataHoundServerStatus) {
	HoundDataHoundServerStatusNone,
	HoundDataHoundServerStatusOK,
	HoundDataHoundServerStatusError,
};

#pragma mark - HoundDataIcon

typedef NS_ENUM(NSUInteger, HoundDataIcon) {
	HoundDataIconNone,
	HoundDataIconNeutral,
	HoundDataIconHappy,
	HoundDataIconSad,
	HoundDataIconAngry,
	HoundDataIconCoffee,
};

#pragma mark - HoundDataBuildInfo

@interface HoundDataBuildInfo : HoundData

@property(nonatomic, copy) NSString* user;
@property(nonatomic, copy) NSDate* date;
@property(nonatomic, copy) NSString* machine;
@property(nonatomic, copy) NSString* SVNRevision;
@property(nonatomic, copy) NSString* SVNBranch;
@property(nonatomic, copy) NSString* buildNumber;
@property(nonatomic, copy) NSString* kind;
@property(nonatomic, copy) NSString* variant;

@end

#pragma mark - HoundDataCommandError

@interface HoundDataCommandError : HoundData

@property(nonatomic, copy) NSString* errorMessage;
@property(nonatomic, copy) NSString* expectedCommandKind;
@property(nonatomic, copy) NSString* errorType;

@end

#pragma mark - HoundDataCommandResult

@interface HoundDataCommandResult : HoundData

@property(nonatomic, copy) NSString* spokenResponse;
@property(nonatomic, copy) NSString* spokenResponseLong;
@property(nonatomic, copy) NSString* writtenResponse;
@property(nonatomic, copy) NSString* writtenResponseLong;
@property(nonatomic, assign) BOOL autoListen;
@property(nonatomic, copy) NSString* userVisibleMode;
@property(nonatomic, assign) BOOL isRepeat;
@property(nonatomic, strong) NSDictionary* conversationState;
@property(nonatomic, strong) HoundDataNumberArray* viewType;
@property(nonatomic, copy) NSString* templateName;
@property(nonatomic, strong) HoundDataTemplate* templateData;
@property(nonatomic, strong) HoundDataPreview* preview;
@property(nonatomic, strong) HoundDataHTMLData* HTMLData;
@property(nonatomic, strong) HoundDataHints* hints;
@property(nonatomic, assign) HoundDataEmotion emotion;
@property(nonatomic, assign) HoundDataIcon icon;
@property(nonatomic, strong) HoundDataStringArray* requiredFeatures;
@property(nonatomic, strong) HoundDataDynamicResponse* clientActionSucceededResult;
@property(nonatomic, strong) HoundDataDynamicResponse* clientActionFailedResult;
@property(nonatomic, strong) HoundDataDynamicResponse* requiredFeaturesSupportedResult;
@property(nonatomic, strong) id sendBack;
@property(nonatomic, copy) NSString* errorType;
@property(nonatomic, strong) HoundDataCommandError* errorData;
@property(nonatomic, copy) NSString* commandKind;
@property(nonatomic, strong) NSDictionary* userInfo;

@end

#pragma mark - HoundDataDynamicResponse

@interface HoundDataDynamicResponse : HoundData

@property(nonatomic, copy) NSString* spokenResponse;
@property(nonatomic, copy) NSString* spokenResponseLong;
@property(nonatomic, copy) NSString* writtenResponse;
@property(nonatomic, copy) NSString* writtenResponseLong;
@property(nonatomic, assign) BOOL autoListen;
@property(nonatomic, copy) NSString* userVisibleMode;
@property(nonatomic, strong) NSDictionary* conversationState;
@property(nonatomic, assign) NSUInteger conversationStateTime;
@property(nonatomic, strong) HoundDataNumberArray* viewType;
@property(nonatomic, copy) NSString* templateName;
@property(nonatomic, strong) HoundDataTemplate* templateData;
@property(nonatomic, copy) NSString* smallScreenHTML;
@property(nonatomic, copy) NSString* largeScreenHTML;
@property(nonatomic, strong) HoundDataHints* hints;
@property(nonatomic, assign) HoundDataEmotion emotion;
@property(nonatomic, assign) HoundDataIcon icon;

@end

#pragma mark - HoundDataHints

@interface HoundDataHints : HoundData

@property(nonatomic, strong) HoundDataHintsSpoken* spoken;
@property(nonatomic, strong) HoundDataHintsWritten* written;

@end

#pragma mark - HoundDataHintsSpoken

@interface HoundDataHintsSpoken : HoundData

@property(nonatomic, copy) NSString* text;
@property(nonatomic, assign) HoundDataHintsSpokenPriority priority;

@end

#pragma mark - HoundDataHintsWritten

@interface HoundDataHintsWritten : HoundData

@property(nonatomic, strong) HoundDataHintsWrittenHintsArray* hints;

@end

#pragma mark - HoundDataHintsWrittenHints

@interface HoundDataHintsWrittenHints : HoundData

@property(nonatomic, copy) NSString* text;
@property(nonatomic, assign) HoundDataHintsWrittenHintsPriority priority;

@end

#pragma mark - HoundDataHoundServer

@interface HoundDataHoundServer : HoundData

@property(nonatomic, assign) HoundDataHoundServerFormat format;
@property(nonatomic, assign) HoundDataHoundServerFormatVersion formatVersion;
@property(nonatomic, assign) HoundDataHoundServerStatus status;
@property(nonatomic, copy) NSString* errorMessage;
@property(nonatomic, assign) NSUInteger numToReturn;
@property(nonatomic, strong) HoundDataCommandResultArray* allResults;
@property(nonatomic, strong) HoundDataHoundServerDisambiguation* disambiguation;
@property(nonatomic, strong) HoundDataNumberArray* resultsAreFinal;
@property(nonatomic, strong) HoundDataBuildInfo* buildInfo;
@property(nonatomic, copy) NSString* serverGeneratedId;
@property(nonatomic, assign) double audioLength;
@property(nonatomic, assign) double realSpeechTime;
@property(nonatomic, assign) double cpuSpeechTime;
@property(nonatomic, assign) double realTime;
@property(nonatomic, assign) double cpuTime;

@end

#pragma mark - HoundDataHoundServerDisambiguation

@interface HoundDataHoundServerDisambiguation : HoundData

@property(nonatomic, assign) NSUInteger numToShow;
@property(nonatomic, strong) HoundDataHoundServerDisambiguationChoiceDataArray* choiceData;

@end

#pragma mark - HoundDataHoundServerDisambiguationChoiceData

@interface HoundDataHoundServerDisambiguationChoiceData : HoundData

@property(nonatomic, copy) NSString* transcription;
@property(nonatomic, assign) double confidenceScore;
@property(nonatomic, copy) NSString* fixedTranscription;

@end

#pragma mark - HoundDataHTMLData

@interface HoundDataHTMLData : HoundData

@property(nonatomic, strong) HoundDataHTMLDataHTMLHead* HTMLHead;
@property(nonatomic, copy) NSString* smallScreenHTML;
@property(nonatomic, copy) NSString* largeScreenHTML;
@property(nonatomic, copy) NSURL* smallScreenURL;
@property(nonatomic, copy) NSURL* largeScreenURL;

@end

#pragma mark - HoundDataHTMLDataHTMLHead

@interface HoundDataHTMLDataHTMLHead : HoundData

@property(nonatomic, copy) NSString* CSS;
@property(nonatomic, copy) NSString* JS;

@end

#pragma mark - HoundDataPreview

@interface HoundDataPreview : HoundData


@end

#pragma mark - HoundDataTemplate

@interface HoundDataTemplate : HoundData

@property(nonatomic, copy) NSString* templateName;

@end

#pragma mark - HoundDataCommandResultArray

@interface HoundDataCommandResultArray : HoundDataArray


@end

#pragma mark - HoundDataHintsWrittenHintsArray

@interface HoundDataHintsWrittenHintsArray : HoundDataArray


@end

#pragma mark - HoundDataHoundServerDisambiguationChoiceDataArray

@interface HoundDataHoundServerDisambiguationChoiceDataArray : HoundDataArray


@end

