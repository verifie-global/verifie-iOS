//
//  HumanDetector.h
//  Verifie
//
//  Created by Misha Torosyan on 5/5/19.
//  Copyright © 2019 Misha Torosyan. All rights reserved.
//

#import <UIKit/UIKit.h>

@class HumanDetector;

typedef NS_ENUM(int, HumanDetectorResult) {
    
    HumanDetectorResultMoveCloser,
    HumanDetectorResultMoveAway,
    HumanDetectorResultBlinkEyes,
    HumanDetectorResultDetected,
    HumanDetectorResultFaceFailed,
    HumanDetectorResultEyesFailed,
};

NS_ASSUME_NONNULL_BEGIN

@protocol HumanDetectorDelegate <NSObject>

- (void)humanDetector:(HumanDetector *)sender
           didReceive:(HumanDetectorResult)result
                 with:(UIImage *)sourceImage;

@end

@interface HumanDetector : NSObject

@property (nonatomic, strong) id <HumanDetectorDelegate> delegate;

- (void)detect:(UIImage *)source;

- (void)resetFailuresCount;

@end

NS_ASSUME_NONNULL_END
