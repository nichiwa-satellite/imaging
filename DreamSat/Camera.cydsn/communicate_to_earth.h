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
#include "operation.h"
#include "common.h"

#define COMMAND_SIZE (6)

void ReceiveCommand(CommandDigit*);
unsigned short ConvertCommand(CommandDigit*);
StatusCode SendReply(ReplyDigit*, size_t);
void InitializeUartToEarth();

#endif //DREAMSAT_CAMERA_COMMUNICATE_TO_EARTH_H_
