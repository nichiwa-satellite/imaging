/* ========================================
 *
 * Copyright NICHIWA-SYSTEM, 2017
 * All Rights Reserved
 *
 * ========================================
*/
#include "project.h"
#include "communicate_to_earth.h"
#include "communicate_to_camera.h"
#include "initialize.h"

void Initialize() {
    InitializeUartToEarth();
    InitializeCamera();

    CyGlobalIntEnable;
    
}
