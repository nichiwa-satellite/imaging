/* ========================================
 *
 * Copyright NICHIWA-SYSTEM, 2017
 * All Rights Reserved
 *
 * ========================================
*/

#ifndef DREAMSAT_CAMERA_RECEIVE_CMD_H_
#define DREAMSAT_CAMERA_RECEIVE_CMD_H_

#include "operation.h"

#define COMMAND_SIZE (6)

typedef unsigned char cmd_digit;

typedef enum cmdtypetag
{
    cmd_hello,
    cmd_panic,
    cmd_parroting
}cmdtype;

void ReceiveCommand(cmd_digit*);
unsigned short ConvertCommand(cmd_digit*);
int SendReply(reply_digit*, size_t);

#endif //DREAMSAT_CAMERA_RECEIVE_CMD_H_
