//
//  ProcessSpeech.m
//  pennapps
//
//  Created by Francesco Polizzi on 1/23/16.
//  Copyright © 2016 Francesco Polizzi. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ProcessSpeech.h"



@implementation ProcessSpeech : NSObject

- (id)init {
    return self;
}

-(void)start:(void (^)(id))firstCompletionHandler
{
    [HoundVoiceSearch.instance
     startListeningWithCompletionHandler:^(NSError* error) {
         dispatch_async(dispatch_get_main_queue(), ^{
             if(HoundVoiceSearchStateReady){
                 NSLog(@"Started Listening (in async)");
                 
                 [self startSearchWithCompletionHandler:^(NSString *myIntent){
                     firstCompletionHandler(myIntent);
                 }];
             }
         });
     }
     ];
    
    //NSLog(@"OUT of async");
    
}

- (void)startSearchWithCompletionHandler:(void (^)(id))completionHandler
{
    NSDictionary* requestInfo = @{
                                  @"ClientMatches" : @[
                                          @{
                                              @"Expression" : @"(\"create\" | \"make\" | \"build\" | \"render\" | \"add\") . ((\"a\" | \"the\" | \"one\").(\"tree\") | (\"tree\"))",
                                              @"Result" : @{ @"Intent" : @"create tree" },
                                              @"SpokenResponse" : @"create tree",
                                              @"SpokenResponseLong" : @"create tree",
                                              @"WrittenResponse" : @"create tree",
                                              @"WrittenResponseLong" : @"create tree"
                                              },
                                          @{
                                              @"Expression" : @"(\"delete\" | \"remove\" | \"destory\" | \"render\" | \"kill\") . ((\"that\" | \"this\" | \"the\").(\"tree\") | (\"tree\"))",
                                              @"Result" : @{ @"Intent" : @"delete tree" },
                                              @"SpokenResponse" : @"delete tree",
                                              @"SpokenResponseLong" : @"delete tree",
                                              @"WrittenResponse" : @"delete tree",
                                              @"WrittenResponseLong" : @"delete tree"
                                              },
                                          @{
                                              @"Expression" : @"(\"create\" | \"make\" | \"build\" | \"render\" | \"add\") . ((\"a\" | \"the\" | \"one\").(\"trump\" | \"Donald Trump\") | (\"trump\" | \"Donald Trump\"))",
                                              @"Result" : @{ @"Intent" : @"create trump" },
                                              @"SpokenResponse" : @"create trump",
                                              @"SpokenResponseLong" : @"create trump",
                                              @"WrittenResponse" : @"create trump",
                                              @"WrittenResponseLong" : @"create trump"
                                              },
                                          @{
                                              @"Expression" : @"(\"delete\" | \"remove\" | \"destory\" | \"render\" | \"kill\") . ((\"that\" | \"this\" | \"the\").(\"Donald Trump\") | (\"Donald Trump\"))",
                                              @"Result" : @{ @"Intent" : @"delete trump" },
                                              @"SpokenResponse" : @"delete trump",
                                              @"SpokenResponseLong" : @"delete trump",
                                              @"WrittenResponse" : @"delete trump",
                                              @"WrittenResponseLong" : @"delete trump"
                                              },
                                          @{
                                              @"Expression" : @"(\"create\" | \"make\" | \"build\" | \"render\" | \"add\") . ((\"a\" | \"the\" | \"one\").(\"sun\") | (\"sun\"))",
                                              @"Result" : @{ @"Intent" : @"create sun" },
                                              @"SpokenResponse" : @"create sun",
                                              @"SpokenResponseLong" : @"create sun",
                                              @"WrittenResponse" : @"create sun",
                                              @"WrittenResponseLong" : @"create sun"
                                              },
                                          @{
                                              @"Expression" : @"(\"delete\" | \"remove\" | \"destory\" | \"render\" | \"kill\" | \"extinguish\") . ((\"that\" | \"this\" | \"the\").(\"sun\") | (\"sun\"))",
                                              @"Result" : @{ @"Intent" : @"delete sun" },
                                              @"SpokenResponse" : @"delete sun",
                                              @"SpokenResponseLong" : @"delete sun",
                                              @"WrittenResponse" : @"delete sun",
                                              @"WrittenResponseLong" : @"delete sun"
                                              },
                                          @{
                                              @"Expression" : @"(\"create\" | \"make\" | \"build\" | \"render\" | \"add\") . ((\"a\" | \"the\" | \"one\").(\"cube\") | (\"cube\"))",
                                              @"Result" : @{ @"Intent" : @"create cube" },
                                              @"SpokenResponse" : @"create cube",
                                              @"SpokenResponseLong" : @"create cube",
                                              @"WrittenResponse" : @"create cube",
                                              @"WrittenResponseLong" : @"create cube"
                                              },
                                          @{
                                              @"Expression" : @"(\"delete\" | \"remove\" | \"destory\" | \"kill\" | \"extinguish\") . ((\"that\" | \"this\" | \"the\" | \"one\").(\"cube\") | (\"cube\"))",
                                              @"Result" : @{ @"Intent" : @"delete cube" },
                                              @"SpokenResponse" : @"delete cube",
                                              @"SpokenResponseLong" : @"delete cube",
                                              @"WrittenResponse" : @"delete cube",
                                              @"WrittenResponseLong" : @"delete cube"
                                              },
                                          ],
                                  @"ClientMatchesOnly" : @YES
                                  };
    
    NSLog(@"%@", requestInfo);
    
    NSURL *URL = [NSURL URLWithString:@"https://api.houndify.com/v1/audio"];
    
    NSLog(@"creating voice search instance");
    [HoundVoiceSearch.instance startSearchWithRequestInfo:requestInfo
                                              endPointURL:URL
                                          responseHandler:^(NSError* error, HoundVoiceSearchResponseType responseType, id response, NSDictionary* dictionary) {
                                              dispatch_async(dispatch_get_main_queue(), ^{
                                                  NSLog(@"Searching Started");
                                                  
                                                  if (error)
                                                  {
                                                      // Handle errorg
                                                      
                                                      NSLog(@"search error: %@", error.localizedDescription);
                                                  }
                                                  else if (responseType == HoundVoiceSearchResponseTypeHoundServer)
                                                  {
                                                      // Display response JSON
                                                      NSLog(@"dictionary: %@", dictionary);
                                                      
                                                      // Any properties from the documentation can be accessed through the keyed accessors, e.g.:
                                                      
                                                      HoundDataHoundServer* houndServer = response;
                                                      
                                                      HoundDataCommandResult* commandResult = houndServer.allResults.firstObject;
                                                      
                                                      NSDictionary* nativeData = commandResult[@"NativeData"];
                                                      
                                                      NSLog(@"NativeData: %@", nativeData);
                                                      NSDictionary *result=[nativeData valueForKey:@"Result"];
                                                      _intent =[result valueForKey:@"Intent"];
                                                      //NSLog(@"%@", _intent);
                                                      completionHandler(_intent);
                                                      
                                                      
                                                      NSLog(@"Listening Ended");
                                                      [HoundVoiceSearch.instance
                                                       stopListeningWithCompletionHandler:^(NSError *error) {
                                                           if(error)
                                                           {
                                                               NSLog(@"stopped listening error: %@", error);
                                                               NSLog(@"returning value to calling function");
                                                           }
                                                       }
                                                       ];
                                                      
                                                      
                                                  }
                                              });
                                          }];
}


- (NSString*)returnIntent
{
    return @"null";
}

@end