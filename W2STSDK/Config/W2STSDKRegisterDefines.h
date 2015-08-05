//
//  W2STSDKRegisterDefines.h
//
//  Created by Antonino Raucea on 06/15/15.
//  Copyright (c) 2015 STMicroelectronics. All rights reserved.
//

#ifndef W2STSDKRegisterDefines_h
#define W2STSDKRegisterDefines_h

#import <Foundation/Foundation.h>
#import "W2STSDKRegister.h"

@interface W2STSDKRegisterDefines : NSObject

/**
 * This enum contains the registers name */
typedef NS_ENUM(NSInteger, W2STSDKRegisterName_e) {
    W2STSDK_REGISTER_NAME_NONE,
    
    /*Mandatory registers*/
    W2STSDK_REGISTER_NAME_FW_VER,
    W2STSDK_REGISTER_NAME_LED_CONFIG,
    W2STSDK_REGISTER_NAME_BLE_LOC_NAME,
    W2STSDK_REGISTER_NAME_BLE_PUB_ADDR,
    
    W2STSDK_REGISTER_NAME_BATTERY_LEVEL,
    W2STSDK_REGISTER_NAME_BATTERY_VOLTAGE,
    W2STSDK_REGISTER_NAME_CURRENT,
    W2STSDK_REGISTER_NAME_PWRMNG_STATUS,
    
    /*optional generic*/
    W2STSDK_REGISTER_NAME_RADIO_TXPWR_CONFIG,
    W2STSDK_REGISTER_NAME_TIMER_FREQ,
    W2STSDK_REGISTER_NAME_PWR_MODE_CONFIG,
    W2STSDK_REGISTER_NAME_HW_FEATURES_MAP,
    W2STSDK_REGISTER_NAME_HW_FEATURE_CTRLS_0001,
    W2STSDK_REGISTER_NAME_HW_FEATURE_CTRLS_0002,
    W2STSDK_REGISTER_NAME_HW_FEATURE_CTRLS_0004,
    W2STSDK_REGISTER_NAME_HW_FEATURE_CTRLS_0008,
    W2STSDK_REGISTER_NAME_HW_FEATURE_CTRLS_0010,
    W2STSDK_REGISTER_NAME_HW_FEATURE_CTRLS_0020,
    W2STSDK_REGISTER_NAME_HW_FEATURE_CTRLS_0040,
    W2STSDK_REGISTER_NAME_HW_FEATURE_CTRLS_0080,
    W2STSDK_REGISTER_NAME_HW_FEATURE_CTRLS_0100,
    W2STSDK_REGISTER_NAME_HW_FEATURE_CTRLS_0200,
    W2STSDK_REGISTER_NAME_HW_FEATURE_CTRLS_0400,
    W2STSDK_REGISTER_NAME_HW_FEATURE_CTRLS_0800,
    W2STSDK_REGISTER_NAME_HW_FEATURE_CTRLS_1000,
    W2STSDK_REGISTER_NAME_HW_FEATURE_CTRLS_2000,
    W2STSDK_REGISTER_NAME_HW_FEATURE_CTRLS_4000,
    W2STSDK_REGISTER_NAME_HW_FEATURE_CTRLS_8000,
    W2STSDK_REGISTER_NAME_SW_FEATURES_MAP,
    W2STSDK_REGISTER_NAME_SW_FEATURE_CTRLS_0001,
    W2STSDK_REGISTER_NAME_SW_FEATURE_CTRLS_0002,
    W2STSDK_REGISTER_NAME_SW_FEATURE_CTRLS_0004,
    W2STSDK_REGISTER_NAME_SW_FEATURE_CTRLS_0008,
    W2STSDK_REGISTER_NAME_SW_FEATURE_CTRLS_0010,
    W2STSDK_REGISTER_NAME_SW_FEATURE_CTRLS_0020,
    W2STSDK_REGISTER_NAME_SW_FEATURE_CTRLS_0040,
    W2STSDK_REGISTER_NAME_SW_FEATURE_CTRLS_0080,
    W2STSDK_REGISTER_NAME_SW_FEATURE_CTRLS_0100,
    W2STSDK_REGISTER_NAME_SW_FEATURE_CTRLS_0200,
    W2STSDK_REGISTER_NAME_SW_FEATURE_CTRLS_0400,
    W2STSDK_REGISTER_NAME_SW_FEATURE_CTRLS_0800,
    W2STSDK_REGISTER_NAME_SW_FEATURE_CTRLS_1000,
    W2STSDK_REGISTER_NAME_SW_FEATURE_CTRLS_2000,
    W2STSDK_REGISTER_NAME_SW_FEATURE_CTRLS_4000,
    W2STSDK_REGISTER_NAME_SW_FEATURE_CTRLS_8000,
    W2STSDK_REGISTER_NAME_BLE_DEBUG_CONFIG,
    W2STSDK_REGISTER_NAME_USB_DEBUG_CONFIG,
    W2STSDK_REGISTER_NAME_HW_CALIBRATION_MAP,
    W2STSDK_REGISTER_NAME_SW_CALIBRATION_MAP,
    
    W2STSDK_REGISTER_NAME_DFU_REBOOT,
    W2STSDK_REGISTER_NAME_HW_CALIBRATION,
    W2STSDK_REGISTER_NAME_HW_CALIBRATION_STATUS,
    W2STSDK_REGISTER_NAME_SW_CALIBRATION,
    W2STSDK_REGISTER_NAME_SW_CALIBRATION_STATUS
};

/**
 * Lookup the register through the name
 * @param name name of the register
 *
 * @return the register if exist otherwise nil
 */
+(W2STSDKRegister *) lookUpWithRegisterName:(W2STSDKRegisterName_e)name;
/**
 * Lookup the register through the name
 * @param address address of the register
 * @param target target of the register
 *
 * @return the register if exist otherwise nil
 */
+(W2STSDKRegister *) lookUpRegisterWithAddress:(NSInteger)address target:(W2STSDKRegisterTarget_e)target;
/**
 * Lookup the register through the name
 * @param address address of the register
 * @param target target of the register
 *
 * @return the register name if exist, otherwise W2STSDK_REGISTER_NAME_NONE
 */
+(W2STSDKRegisterName_e) lookUpRegisterNameWithAddress:(NSInteger)address target:(W2STSDKRegisterTarget_e)target;

/**
 * Get the list of available registers
 *
 * @return a dictionary with all registers
 */
+(NSDictionary *)registers;
@end
#endif //W2STSDKRegisterDefines_h