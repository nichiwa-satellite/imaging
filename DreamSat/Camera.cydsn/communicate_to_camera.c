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

#include "communicate_to_camera.h"
#include "project.h"

//define

#define CAMERA_RECVDATA_HEADER_STEP1     (0x80)
#define CAMERA_RECVDATA_HEADER_STEP2     (0x80)

#define CAMERA_RECVDATA_FOOTER_STEP1     (0x81)
#define CAMERA_RECVDATA_FOOTER_STEP2     (0x81)

//typedef
typedef enum {
    HEADER_STEP1,
    HEADER_STEP2,
    DATA,
}RecievePhaseCode;

//Variables
static Byte*        camera_buff;
static size_t       camera_buff_length;
static size_t       recv_count;
RecievePhaseCode    recv_phase;

void IsrCamRx() {
    Byte recv_data = UART_TO_CAMERA_GetChar();

 
    //Parameter Check
    if (camera_buff == NULL) {
        return;
    }

    //Buffer Overflow
    if (camera_buff_length <= recv_count) {
        return;
    }

    switch (recv_phase) {
        case HEADER_STEP1:
            if (recv_data != CAMERA_RECVDATA_HEADER_STEP1) {
                return;
            }
            recv_phase++;
            break;

        case HEADER_STEP2:
            //eader check step 2 Try Once
            if (recv_data != CAMERA_RECVDATA_HEADER_STEP2) {
                recv_phase = HEADER_STEP1;
                return;
            }
            recv_phase++;
            break;

        case DATA:
            camera_buff[recv_count] = recv_data;
            recv_count++;
            break;
    }

    return;
}

void InitializeCamera() {
    //UART Device Init
    UART_TO_CAMERA_Init();
    UART_TO_CAMERA_Start();

    // Interrupt Init
    IsrCamRx_StartEx(IsrCamRx );

    //Interrupt Disable
    IsrCamRx_Disable();

    return;
}

StatusCode CommunicateToCamera(Byte* request, size_t request_length, Byte *recv_buff, size_t recv_buff_length) {
    //Parameter Check
    if (recv_buff == NULL) {
        return ERROR;    
    }

    //Parameter Check
    if (recv_buff_length == 0) {
        return ERROR;
    }

    //Recieve Setup
    camera_buff = recv_buff;
    camera_buff_length = recv_buff_length;
    recv_count = 0;
    recv_phase = HEADER_STEP1,

    //Interrupt Enable
    IsrCamRx_Enable();

    //Send Request
    UART_TO_CAMERA_PutArray(request, request_length);

    //Recieve Complete Wait
    while (1) {
        //TODO : TIMEOUT
        if (camera_buff_length <= recv_count) {
            //Interrupt Disanable
            IsrCamRx_Disable();
            break;
        }
    }

    return SUCCESS;
}

/* [] END OF FILE */
