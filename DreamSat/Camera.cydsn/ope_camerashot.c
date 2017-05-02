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

#include "ope_camerashot.h"
#include "camera.h"

/* TODO : Recieve Data SIze */
#define RECIEVE_DATASIZE    ( 10 )

void OpeCameraShot()
{
    /* TODO : Set Camera Shot Command */
    request_digit request[] = "";
    /* TODO : Recieve Buffer */
    unsigned char recv_buffer[RECIEVE_DATASIZE];

    /* TODO : ERROR PROCESS */
    /* REQUEST CAMERASHOT */
    (void)SendRequest(request, sizeof(request), recv_buffer, sizeof(recv_buffer));

    return;
}


/* [] END OF FILE */
