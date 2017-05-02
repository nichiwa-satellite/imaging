/* ========================================
 *
 * Copyright NICHIWA-SYSTEM, 2017
 * All Rights Reserved
 *
 * ========================================
*/
#include "project.h"
#include "comunicate.h"

void Initialize()
{
    InitializeCommUart();
    
    CyGlobalIntEnable;
    
}
