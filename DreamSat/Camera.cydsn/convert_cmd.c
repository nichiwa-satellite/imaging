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

CommandType ConvertCommand(Byte* command)
{
    Byte    hello[] = {'h','e','l','l','o'};
    Byte    panic[] = {'p','a','n','i','c'};
 
    CommandType cmd_type = 0;
    if (memcmp(command, hello, sizeof(hello))){
        cmd_type = HELLO;
    } else if (memcmp(command, panic, sizeof(panic))) {
        cmd_type = PANIC;
    } else {
        cmd_type = PARROTTING;
    }
    return cmd_type;
}
