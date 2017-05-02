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
#include <stddef.h>

typedef unsigned char request_digit;

void Camera_Initialize();
rettype SendRequest(request_digit* request, size_t request_size, unsigned char *recv_buff, unsigned int recv_buff_size);

#endif //DREAMSAT_CAMERA_COMMUNICATE_H_

/* [] END OF FILE */
