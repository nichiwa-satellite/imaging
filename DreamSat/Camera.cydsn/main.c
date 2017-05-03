/* ========================================
 *
 * Copyright NICHIWA-SYSTEM, 2017
 * All Rights Reserved
 *
 * ========================================
*/
#include "project.h"
#include "initialize.h"
#include "earth.h"
#include "operation.h"

int main(void)
{
    cmd_digit command[COMMAND_SIZE] = {0};

    Initialize();

    ReceiveCommand(command);

    switch (ConvertCommand(command)) {
      case cmd_hello:
        OpeHello(&SendReply);
        break;
      case cmd_panic:
        OpePanic(&SendReply);
        break;
      case cmd_parroting:
        OpeParroting(&SendReply);
        break;
      default:
        break;
    }

    return 0;
}
