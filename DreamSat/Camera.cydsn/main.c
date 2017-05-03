/* ========================================
 *
 * Copyright NICHIWA-SYSTEM, 2017
 * All Rights Reserved
 *
 * ========================================
*/
#include "project.h"
#include "initialize.h"
#include "communicate_to_earth.h"

#include "operation.h"
#include "ope_hello.h"
#include "ope_panic.h"
#include "ope_parroting.h"

int main(void)
{
    CommandDigit command[COMMAND_SIZE] = {0};

    Initialize();

    ReceiveCommand(command);

    switch (ConvertCommand(command)) {
      case HELLO:
        OpeHello(&SendReply);
        break;
      case PANIC:
        OpePanic(&SendReply);
        break;
      case PARROTTING:
        OpeParroting(&SendReply);
        break;
      default:
        break;
    }

    return 0;
}
