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
#include "communicate_to_camera.h"

/* TODO : Recieve Data SIze */
#define RECIEVE_DATASIZE    ( 5 )

void OpeCameraShot(reply_func reply)
{
    /* TODO : Set Camera Shot Command */
    Byte request[] = {0x56, 0x00, 0x36, 0x01, 0x00};
    /* TODO : Recieve Buffer */
    unsigned char recv_buffer[RECIEVE_DATASIZE];

    /* TODO : ERROR PROCESS */
    /* REQUEST CAMERASHOT */
    (void)CommunicateToCamera(request, sizeof(request) / sizeof(request[0]), recv_buffer, sizeof(recv_buffer) / sizeof(recv_buffer[0]));
    (*reply)(recv_buffer, sizeof(recv_buffer) / sizeof(recv_buffer[0]));
    return;
}


/* [] END OF FILE */
