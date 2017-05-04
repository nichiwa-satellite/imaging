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
#include "ope_camerashot.h"
#include "ope_parroting.h"

int main(void)
{
    Byte command[COMMAND_SIZE] = {0};

    Initialize();

    RecieveFromEarth(command);

    switch (ConvertCommand(command)) {
      case HELLO:
        OpeHello(&SendToEarth);
        break;
      case PANIC:
        OpePanic(&SendToEarth);
        break;
      case CAMERASHOT:
        OpeCameraShot(&SendToEarth);
        break;
      case PARROTTING:
        OpeParroting(&SendToEarth);
        break;
      default:
        break;
    }

    return 0;
}
