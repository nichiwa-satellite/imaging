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

#include <string.h>
#include "convert_cmd.h"
#include "ope_hello.h"
#include "ope_panic.h"
#include "ope_parroting.h"

#include "ope_shoot.h"
#include "ope_send_image.h"
#include "ope_send_thumb.h"
#include "ope_delete_Image.h"
#include "ope_check_state.h"
#include "ope_part_panic.h"
#include "ope_full_panic.h"

#include "communicate_to_earth.h"
#include "operation.h"

typedef struct {
    CommandType cmd_no;
    Byte cmd_pattern[8];
}CommandList;

CommandList allCommandList[COMMAND_MAX] = {
    {SHOOT,        "11000001"},
    {SEND_THUMB,   "11000010"},
    {SEND_IMAGE,   "11000011"},
    {DELETE_IMAGE, "11000100"},
    {CHECK_STATE,  "11000101"},
    {PART_PANIC,   "01100110"},
    {FULL_PANIC,   "11100111"}
};

StatusCode AssignCommand(Byte* command)
{
    StatusCode ret = SUCCESS;
    switch (ConvertCommand(command)) {
      case SHOOT:
        OpeShoot(&SendToEarth);
        break;
      case SEND_THUMB:
        OpeSendThumb(&SendToEarth);
        break;
      case SEND_IMAGE:
        OpeSendImage(&SendToEarth);
        break;
      case DELETE_IMAGE:
        OpeDeleteImage(&SendToEarth);
        break;
      case CHECK_STATE:
        OpeCheckState(&SendToEarth);
        break;
      case PART_PANIC:
        OpePartPanic(&SendToEarth);
        break;
      case FULL_PANIC:
        OpeFullPanic(&SendToEarth);
        break;
      default:
        break;
    }
    return ret;
}

CommandType ConvertCommand(Byte* command)
{
    int i;
    CommandType cmd_type = 0;
    for (i = 0; i < COMMAND_MAX; i++) {
        if (memcmp(command, allCommandList[i].cmd_pattern, sizeof(allCommandList[i].cmd_pattern)) == 0){
            cmd_type = allCommandList[i].cmd_no;
        }
    }
    return cmd_type;
}
