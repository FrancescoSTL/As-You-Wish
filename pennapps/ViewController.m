//
//  ViewController.m
//  pennapps
//
//  Created by Francesco Polizzi on 1/22/16.
//  Copyright © 2016 Francesco Polizzi. All rights reserved.
//

#import "ViewController.h"
#import "ProcessSpeech.h"

@interface ViewController ()<AVAudioRecorderDelegate>

@property (nonatomic,strong) UILongPressGestureRecognizer *lpgr;
@property NSString* state;
@property NSString* returnIntent;

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    self.lpgr = [[UILongPressGestureRecognizer alloc] initWithTarget:self action:@selector(handleLongPressGestures:)];
    self.lpgr.minimumPressDuration = 0;
    self.lpgr.allowableMovement = 100.0f;
    
    [self.view addGestureRecognizer:self.lpgr];
    
}

- (void)handleLongPressGestures:(UILongPressGestureRecognizer *)sender
{
    if ([sender isEqual:self.lpgr]) {
        if (sender.state == UIGestureRecognizerStateBegan)
        {
            
            ProcessSpeech *speech = [ProcessSpeech new];
            [speech start:^(NSString *myIntent){
                _returnIntent = myIntent;
                NSLog(@"----------------------------------------------");
                NSLog(@"USER INTENT: %@", myIntent);
                NSLog(@"----------------------------------------------");
            }];
        }
    }
    
    NSLog(@"FROM CALLING FUNCTION: %@", _returnIntent);
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
