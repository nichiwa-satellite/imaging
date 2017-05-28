/* ========================================
 *
 * Copyright NICHIWA-SYSTEM, 2017
 * All Rights Reserved
 *
 * ========================================
*/

#ifndef DREAMSAT_CAMERA_COMMUNICATE_TO_EARTH_H_
#define DREAMSAT_CAMERA_COMMUNICATE_TO_EARTH_H_

#include <stddef.h>
#include "common.h"

#define COMMAND_SIZE (6)

StatusCode RecieveFromEarth(Byte*);
StatusCode SendToEarth(Byte*, size_t);
void InitializeUartToEarth();

#endif //DREAMSAT_CAMERA_COMMUNICATE_TO_EARTH_H_
