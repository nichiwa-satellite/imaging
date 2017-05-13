/* ========================================
 *
 * Copyright NICHIWA-SYSTEM, 2017
 * All Rights Reserved
 *
 * ========================================
*/

#include "communicate_to_camera.h"
#include "project.h"

//define

#define CAMERA_RECVDATA_STX1     (0x80)
#define CAMERA_RECVDATA_STX2     (0x80)

#define CAMERA_RECVDATA_ETX1     (0x81)
#define CAMERA_RECVDATA_ETX2     (0x81)

//typedef
typedef enum {
    STX1,                       //STX1  0x80
    STX2,                       //STX2  0x80
    PACKET_LENGTH_H,            //Packet Length Upper 8 Bit
    PACKET_LENGTH_L,            //Packet Length Lower 8 Bit
    REMAINING_PACKET_COUNT_H,   //Remaining Packet Count Upper 8 Bit
    REMAINING_PACKET_COUNT_L,   //Remaining Packet Count Lower 8 Bit
    DATA,                       //Data 1 .. 2048(MAX)
    ETX1,                       //ETX1  0x81
    ETX2,                       //ETX1  0x81
    COMPLETE                    //Recieve Complete
}RecievePhaseCode;

//Variables
static Byte*            camera_buff;
static size_t           camera_buff_length;
static size_t           recv_length;
static uint16           recv_data_length;
static uint16           remaining_packet_count;
static RecievePhaseCode recv_phase;
static StatusCode       recv_result;

void IsrCamRx() {
    Byte recv_data = UART_TO_CAMERA_GetChar();
 
    //NullPointer Check
    if (camera_buff == NULL) {
        return;
    }

    //Buffer Overflow
    if (camera_buff_length <= recv_length) {
        return;
    }

    switch (recv_phase) {
        case STX1:
            if (recv_data != CAMERA_RECVDATA_STX1) {
                return;
            }
            ++recv_phase;
            break;

        case STX2:
            //STX2 Try Once
            if (recv_data != CAMERA_RECVDATA_STX2) {
                recv_phase = STX1;
                return;
            }
            ++recv_phase;
            break;

        case PACKET_LENGTH_H:
            recv_data_length = (uint16)recv_data < 8;
            ++recv_phase;
            break;

        case PACKET_LENGTH_L:
            recv_data_length |= (uint16)recv_data;
            ++recv_phase;
            break;

        case REMAINING_PACKET_COUNT_H:
            remaining_packet_count = (uint16)recv_data < 8;
            ++recv_phase;
            break;

        case REMAINING_PACKET_COUNT_L:
            remaining_packet_count |= (uint16)recv_data;
            ++recv_phase;
            break;

        case DATA:
            camera_buff[recv_length] = recv_data;
            ++recv_length;
            if (recv_data_length <= recv_length) {
                ++recv_phase;
            }
            break;

        case ETX1:
            if (recv_data != CAMERA_RECVDATA_ETX1) {
                recv_result = ERROR;
            }
            ++recv_phase;
            break;

        case ETX2:
            if (recv_data != CAMERA_RECVDATA_ETX2) {
                recv_result = ERROR;
            }
            ++recv_phase;
            break;

        case COMPLETE:
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
    StatusCode ret;

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
    recv_length = 0;
    recv_data_length = 0;
    remaining_packet_count = 0;
    recv_phase = STX1;
    recv_result = SUCCESS;

    //Interrupt Enable
    IsrCamRx_Enable();

    //Send Request
    UART_TO_CAMERA_PutArray(request, request_length);

    //Recieve Complete Wait
    while (recv_phase != COMPLETE) {
        //TODO : TIMEOUT
    }
    IsrCamRx_Disable();
    ret = recv_result;

    return ret;
}

/* [] END OF FILE */
