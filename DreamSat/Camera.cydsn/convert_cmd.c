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
#include "common.h"

unsigned short ConvertCommand(CommandDigit* command)
{
    unsigned short cmd_type = 0;
    if (strcmp((char *)command, "hello")) {
        cmd_type = HELLO;
    } else if (strcmp((char *)command, "panic")) {
        cmd_type = PANIC;
    } else {
        cmd_type = PARROTTING;
    }
    return cmd_type;
}
