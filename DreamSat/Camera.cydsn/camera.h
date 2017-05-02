/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/

#ifndef DREAMSAT_CAMERA_COMMUNICATE_H_
#define DREAMSAT_CAMERA_COMMUNICATE_H_

#include "common.h"

typedef unsigned char request_digit;
    
typedef enum camera_interruptstatetag
{
    interrupt_state_recvive_on,
    interrupt_state_recvive_off,
    interrupt_state_max,
} camera_interruptstate;

#endif //DREAMSAT_CAMERA_COMMUNICATE_H_

/* [] END OF FILE */
