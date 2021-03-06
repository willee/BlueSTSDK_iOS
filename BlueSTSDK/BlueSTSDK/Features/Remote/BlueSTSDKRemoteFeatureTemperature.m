/*******************************************************************************
 * COPYRIGHT(c) 2016 STMicroelectronics
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *   1. Redistributions of source code must retain the above copyright notice,
 *      this list of conditions and the following disclaimer.
 *   2. Redistributions in binary form must reproduce the above copyright notice,
 *      this list of conditions and the following disclaimer in the documentation
 *      and/or other materials provided with the distribution.
 *   3. Neither the name of STMicroelectronics nor the names of its contributors
 *      may be used to endorse or promote products derived from this software
 *      without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 ******************************************************************************/

#import "BlueSTSDKRemoteFeatureTemperature.h"
#import "BlueSTSDKFeature_pro.h"
#import "BlueSTSDKFeature+Remote.h"
#import "BlueSTSDKFeatureField.h"

#import "NSData+NumberConversion.h"

#define FEATURE_NAME @"Remote Temperature"
// census degree
#define FEATURE_UNIT @"\u2103"
#define FEATURE_MIN 0
#define FEATURE_MAX 100
#define FEATURE_TYPE BlueSTSDKFeatureFieldTypeFloat

/**
 * @memberof BlueSTSDKRemoteFeatureTemperature
 *  array with the description of field exported by the feature
 */
static NSArray *sFieldDesc;

@interface BlueSTSDKRemoteFeatureTemperature ()<BlueSTSDKRemoteFeature>

@end


@implementation BlueSTSDKRemoteFeatureTemperature{
    NSMutableDictionary * mNodeUnWrapper;
}

+(void)initialize{
    if(self == [BlueSTSDKRemoteFeatureTemperature class]){
        sFieldDesc = [[NSArray alloc] initWithObjects:
                      [BlueSTSDKFeatureField  createWithName: FEATURE_NAME
                                                        unit:FEATURE_UNIT
                                                        type:FEATURE_TYPE
                                                         min:@FEATURE_MIN
                                                         max:@FEATURE_MAX ],
                      [BlueSTSDKFeature getNodeIdFieldDesc],
                      nil];
    }//if
}//initialize

-(instancetype) initWhitNode:(BlueSTSDKNode *)node{
    self = [super initWhitNode:node name:FEATURE_NAME];
    mNodeUnWrapper = [NSMutableDictionary dictionary];
    return self;
}

+(int)getNodeId:(BlueSTSDKFeatureSample*)sample{
    return [self getNodeId:sample idPos:1];
}

-(NSArray*) getFieldsDesc{
    return sFieldDesc;
}

-(BlueSTSDKExtractResult*) extractRemoteData:(uint64_t)timestamp
                                        data:(NSData *)data
                                  dataOffset:(uint32_t)offset{
    return [super extractData:timestamp data:data dataOffset:offset];
}

-(BlueSTSDKExtractResult*) extractData:(uint64_t)timestamp data:(NSData*)rawData
                            dataOffset:(uint32_t)offset{
    
    return [BlueSTSDKFeature extractRemoteData: self
                                   unTsWrapper:mNodeUnWrapper
                                     timestamp:timestamp
                                          data:rawData
                                    dataOffset:offset];
    
}

@end

#import "BlueSTSDKFeature+fake.h"

@implementation BlueSTSDKRemoteFeatureTemperature (fake)

-(NSData*) generateFakeData{
    static uint16_t ts=0;
    NSMutableData *data = [NSMutableData dataWithCapacity:4];
    
    int16_t temp = FEATURE_MIN*10 + rand()%((FEATURE_MAX-FEATURE_MIN)*10);
    [data appendBytes:&ts length:2];
    [data appendBytes:&temp length:2];
    ts++;
    return data;
}

@end