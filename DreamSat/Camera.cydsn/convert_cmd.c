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
#include "comunicate.h"

unsigned short ConvertCommand(cmd_digit* command)
{
    unsigned short cmd_type = 0;
    if (strcmp((char *)command, "hello")) {
        cmd_type = cmd_hello;
    } else if (strcmp((char *)command, "panic")) {
        cmd_type = cmd_panic;
    } else {
        cmd_type = cmd_parroting;
    }
    return cmd_type;
}
