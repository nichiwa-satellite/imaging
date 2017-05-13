/* ========================================
 *
 * Copyright NICHIWA-SYSTEM, 2017
 * All Rights Reserved
 *
 * ========================================
*/

#ifndef DREAMSAT_CAMERA_COMMUNICATE_TO_CAMERA_H_
#define DREAMSAT_CAMERA_COMMUNICATE_TO_CAMERA_H_

#include "common.h"
#include <stddef.h>

void InitializeCamera();
StatusCode CommunicateToCamera(Byte* request, size_t request_size, Byte *recv_buff, size_t recv_buff_size);

#endif //DREAMSAT_CAMERA_COMMUNICATE_TO_CAMERA_H_

/* [] END OF FILE */
