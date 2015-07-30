//
//  W2STFeatureLogNSLog.m
//  W2STApp
//
//  Created by Giovanni Visentini on 22/04/15.
//  Copyright (c) 2015 STMicroelectronics. All rights reserved.
//

#import "W2STSDKFeatureLogNSLog.h"

@implementation W2STSDKFeatureLogNSLog
- (void)feature:(W2STSDKFeature *)feature rawData:(NSData*)raw timestamp:(uint32_t)ts data:(NSArray*)data{
    
    NSMutableString *temp = [NSMutableString string];
    [raw enumerateByteRangesUsingBlock:^(const void *bytes,
                                          NSRange byteRange,
                                          BOOL *stop) {
        for (NSUInteger i = 0; i < byteRange.length; ++i) {
            [temp appendFormat:@"%02X", ((uint8_t*)bytes)[i]];
        }
    }];
    NSLog(@"%@ ts:%d Raw:%@ Data:%@",feature.name,ts,temp,[feature description]);
    
}

@end
