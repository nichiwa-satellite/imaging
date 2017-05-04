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
    const Byte    khello[] = {'h','e','l','l','o'};
    const Byte    kpanic[] = {'p','a','n','i','c'};
 
    CommandType cmd_type = 0;
    if (memcmp(command, khello, sizeof(khello))){
        cmd_type = HELLO;
    } else if (memcmp(command, kpanic, sizeof(kpanic))) {
        cmd_type = PANIC;
    } else {
        cmd_type = PARROTTING;
    }
    return cmd_type;
}
