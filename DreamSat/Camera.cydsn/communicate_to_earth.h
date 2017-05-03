/* ========================================
 *
 * Copyright NICHIWA-SYSTEM, 2017
 * All Rights Reserved
 *
 * ========================================
*/

#ifndef DREAMSAT_CAMERA_RECEIVE_CMD_H_
#define DREAMSAT_CAMERA_RECEIVE_CMD_H_

#include <stddef.h>
#include "operation.h"
#include "common.h"

#define COMMAND_SIZE (6)

void ReceiveCommand(cmd_digit*);
unsigned short ConvertCommand(cmd_digit*);
rettype SendReply(reply_digit*, size_t);
void InitializeUartToEarth();

#endif //DREAMSAT_CAMERA_RECEIVE_CMD_H_
