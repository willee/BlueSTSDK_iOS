/*******************************************************************************
 * COPYRIGHT(c) 2015 STMicroelectronics
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

#import "BlueSTSDKFeature.h"

@protocol BlueSTSDKFeatureAccelerationEnableTypeDelegate;

/**
 *  Feature containing the event that are detected from the accelerometer data
 *  only one event type can be detected at time.
 *
 * @author STMicroelectronics - Central Labs.
 */
@interface BlueSTSDKFeatureAccelerometerEvent : BlueSTSDKFeature


/**
 *  different type of position recognized by the node
 */
typedef NS_ENUM(NSInteger, BlueSTSDKFeatureAccelerometerEventType){

    BlueSTSDKFeatureAccelerometerOrientationTopRight =0x01,
    BlueSTSDKFeatureAccelerometerOrientationBottomRight =0x02,
    BlueSTSDKFeatureAccelerometerOrientationBottomLeft =0x03,
    BlueSTSDKFeatureAccelerometerOrientationTopLeft =0x04,
    BlueSTSDKFeatureAccelerometerOrientationUp =0x05,
    BlueSTSDKFeatureAccelerometerOrientationDown =0x06,
    BlueSTSDKFeatureAccelerometerTilt =0x08,
    BlueSTSDKFeatureAccelerometerFreeFall =0x10,
    BlueSTSDKFeatureAccelerometerSingleTap =0x20,
    BlueSTSDKFeatureAccelerometerDoubleTap =0x40,
    BlueSTSDKFeatureAccelerometerWakeUp =0x80,
    BlueSTSDKFeatureAccelerometerPedometer =0x100,
    BlueSTSDKFeatureAccelerometerNoEvent,
    BlueSTSDKFeatureAccelerometerError
};

typedef NS_ENUM(char, BlueSTSDKFeatureAccelerationDetectableEventType){
    
    BlueSTSDKFeatureEventTypeOrientation='o',
    BlueSTSDKFeatureEventTypeFreeFall='f',
    BlueSTSDKFeatureEventTypeSingleTap='s',
    BlueSTSDKFeatureEventTypeDoubleTap='d',
    BlueSTSDKFeatureEventTypeWakeUp='w',
    BlueSTSDKFeatureEventTypeTilt='t',
    BlueSTSDKFeatureEventTypePedometer='p',
    BlueSTSDKFeatureEventTypeNone='\0',
    
};

+(NSString*) detectableEventTypeToString:(BlueSTSDKFeatureAccelerationDetectableEventType)event;
+(NSString*) eventTypeToString:(BlueSTSDKFeatureAccelerometerEventType)event;

/**
 *  enable an event detection
 *
 *  @param type   event to detect
 *  @param enable true for enable, false for disable the detection
 *
 *  @return true if the command is correctly send to the node
 */
-(BOOL) enableEvent:(BlueSTSDKFeatureAccelerationDetectableEventType) type enable:(BOOL)enable;

/**
 *  get the event that is currently enabled
 *
 *  @return event that is currently enable on the node
 */
-(BlueSTSDKFeatureAccelerationDetectableEventType) getEnalbledEvent;

/**
 *  tell if the event type is currently enabled
 *
 *  @param type event to enable
 *
 *  @return true id the event is enabled
 */
-(BOOL) isEnableEvent:(BlueSTSDKFeatureAccelerationDetectableEventType) type;


/**
 *  register a delegate for this feature
 *  @note the callback are done in an concurrent queue
 *
 *  @param delegate object where notify the configuration change
 */
-(void) addFeatureAccelerationEnableTypeDelegate:
    (id<BlueSTSDKFeatureAccelerationEnableTypeDelegate>)delegate;

/**
 *  remove a delegate for this feature
 *
 *  @param delegate delegate to remove
 */
-(void) removeFeatureAccelerationEnableTypeDelegate:
    (id<BlueSTSDKFeatureAccelerationEnableTypeDelegate>)delegate;

/**
 *  extract the acceleration event
 *
 *  @param sample sample read from the node
 *
 *  @return acceleration event
 */
+(BlueSTSDKFeatureAccelerometerEventType)getAccelerationEvent:(BlueSTSDKFeatureSample*)sample;

/**
 * if you are running the pedometer, you get the number of detected steps otherwise
 * a negative number
 * @param sample sample read form the node
 * @return number of steps, or a negative number if the pedometer isn't enabled 
 */
+(int32_t) getPedometerSteps:(BlueSTSDKFeatureSample*)sample;

@end

/**
 *  Protocol used for notify the change configuration change
 */
@protocol  BlueSTSDKFeatureAccelerationEnableTypeDelegate <NSObject>

 /**
 *  method called when the node notify that the configuration routine start
 *
 *  @param feature feature that start the auto configuration process
 *  @param type      event that change the status
 *  @param newStatus true if the event is enable, false if it disabled
 */
@optional
-(void)didTypeChangeStatus:(BlueSTSDKFeatureAccelerometerEvent *)feature
                                type:(BlueSTSDKFeatureAccelerationDetectableEventType)type
                           newStatus:(BOOL)newStatus;


@end