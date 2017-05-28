/* ========================================
 *
 * Copyright NICHIWA-SYSTEM, 2017
 * All Rights Reserved
 *
 * ========================================
*/

#ifndef DREAMSAT_CAMERA_CONVERT_CMD_H_
#define DREAMSAT_CAMERA_CONVERT_CMD_H_

#include "common.h"

typedef enum {
    SHOOT,
    SEND_THUMB,
    SEND_IMAGE,
    DELETE_IMAGE,
    CHECK_STATE,
    PART_PANIC,
    FULL_PANIC,
    COMMAND_MAX
}CommandType;

CommandType ConvertCommand(Byte*);
StatusCode AssignCommand(Byte* command);

#endif //DREAMSAT_CAMERA_CONVERT_CMD_H_
