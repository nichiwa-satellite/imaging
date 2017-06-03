/* ========================================
 *
 * Copyright NICHIWA-SYSTEM, 2017
 * All Rights Reserved
 *
 * ========================================
*/
#include "project.h"
#include "initialize.h"
#include "convert_cmd.h"
#include "communicate_to_earth.h"

int main(void) {

    Initialize();

    while (1) {   
        Byte command[COMMAND_SIZE] = {0};
        if (RecieveFromEarth(command) == SUCCESS) {
            AssignCommand(command);
        }
    }
    return 0;
}
