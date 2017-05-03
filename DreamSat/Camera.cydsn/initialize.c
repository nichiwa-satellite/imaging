/* ========================================
 *
 * Copyright NICHIWA-SYSTEM, 2017
 * All Rights Reserved
 *
 * ========================================
*/
#include "project.h"
#include "communicate_to_earth.h"
#include "initialize.h"

void Initialize()
{
    InitializeCommUart();
    
    CyGlobalIntEnable;
    
}
