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
    const Byte    kcamerashot[] = {'c','a','m','e','r','a'};
 
    CommandType cmd_type = 0;
    if (memcmp(command, khello, sizeof(khello)) == 0){
        cmd_type = HELLO;
    } else if (memcmp(command, kpanic, sizeof(kpanic)) == 0) {
        cmd_type = PANIC;
    } else if (memcmp(command, kcamerashot, sizeof(kcamerashot)) == 0) {
        cmd_type = CAMERASHOT;
    } else {
        cmd_type = PARROTTING;
    }
    return cmd_type;
}
