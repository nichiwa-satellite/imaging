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

void Camera_Initialize();
StatusCode SendRequest(Byte* request, size_t request_size, Byte *recv_buff, size_t recv_buff_size);

#endif //DREAMSAT_CAMERA_COMMUNICATE_H_

/* [] END OF FILE */
