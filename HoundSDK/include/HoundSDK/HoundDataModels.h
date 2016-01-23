//
//  HoundDataModels.h
//  Hound Command Parser
//
//  Created by Cyril Austin on 6/4/15.
//  Copyright (c) 2015 SoundHound, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

#pragma mark - HoundData

@interface HoundData : NSObject

- (id)objectForKeyedSubscript:(NSString*)key;

@end

#pragma mark - HoundDataArray

@interface HoundDataArray : NSObject<NSFastEnumeration>

@property(nonatomic, strong) NSMutableArray* array;

- (NSUInteger)count;

- (id)firstObject;
- (id)lastObject;

- (void)addObject:(id)object;
- (void)addObjectsFromArray:(NSArray*)array;

- (void)removeObjectAtIndex:(NSUInteger)index;

- (id)objectAtIndexedSubscript:(NSUInteger)index;

- (void)setObject:(id)object atIndexedSubscript:(NSUInteger)index;

@end

#pragma mark - HoundDataStringArray

@interface HoundDataStringArray : HoundDataArray

@end

#pragma mark - HoundDataNumberArray

@interface HoundDataNumberArray : HoundDataArray

@end

#pragma mark - HoundDataURLArray

@interface HoundDataURLArray : HoundDataArray

@end