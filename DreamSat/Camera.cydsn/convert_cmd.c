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

unsigned short ConvertCommand(cmd_digit* command)
{
    unsigned short cmd_type = 0;
    if (strcmp((char *)command, "hello")) {
        cmd_type = kcmd_hello;
    } else if (strcmp((char *)command, "panic")) {
        cmd_type = kcmd_panic;
    } else {
        cmd_type = kcmd_parroting;
    }
    return cmd_type;
}
