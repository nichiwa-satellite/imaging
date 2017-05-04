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

#include "camera.h"
#include "project.h"

//define

#define CAMERA_RECVDATA_HEADER_STEP1     ( 0x80 )
#define CAMERA_RECVDATA_HEADER_STEP2     ( 0x80 )

#define CAMERA_RECVDATA_FOOTER_STEP1     ( 0x81 )
#define CAMERA_RECVDATA_FOOTER_STEP2     ( 0x81 )

//typedef
typedef enum recievestatetag
{
    recv_state_header_step1,
    recv_state_header_step2,
    recv_state_body
} recvstate;

//Variables
static unsigned char    *camera_buff;
static unsigned int     camera_buff_size;
static unsigned int     recv_count;
recvstate               recv_state;

void IsrCamRx()
{
    unsigned int index;
    unsigned char recv_data;

    /* 1 byte Data Read From UART */
    recv_data = UART_TO_CAMERA_GetChar();

    /* Set Index */
    index = recv_count;
    
    /* Parameter Check */
    if (camera_buff == NULL) {
        return;
    }

    /* Buffer Overflow */
    if (camera_buff_size <= recv_count) {
        return;
    }

    switch (recv_state)
    {
        case recv_state_header_step1:
            if (recv_data != CAMERA_RECVDATA_HEADER_STEP1)
            {
                return;
            }
            camera_buff[index] = recv_data;
            recv_count++;
            recv_state++;
            break;

        case recv_state_header_step2:
            /* header check step 2 Try Once */
            if (recv_data != CAMERA_RECVDATA_HEADER_STEP2)
            {
                recv_count--;
                recv_state--;
                return;
            }

            camera_buff[index] = recv_data;
            recv_count++;
            recv_state++;
            break;

        case recv_state_body:
            camera_buff[index] = recv_data;
            recv_count++;

        default:
            break;
    }

    return;
}

void InitializeCamera()
{
    /* UART Device Init */
    UART_TO_CAMERA_Init();
    UART_TO_CAMERA_Start();

    /* Interrupt Init */
    IsrCamRx_StartEx(IsrCamRx );

    /* Interrupt Disable */
    IsrCamRx_Disable();

    return;
}

StatusCode SendRequest(Byte* request, size_t request_size, Byte *recv_buff, size_t recv_buff_size)
{
    /* Parameter Check */
    if (recv_buff == NULL) {
        return ERROR;    
    }

    /* Parameter Check */
    if (recv_buff_size == 0) {
        return ERROR;
    }

    /* Recieve Setup */
    camera_buff = recv_buff;
    camera_buff_size = recv_buff_size;
    recv_count = 0;
    recv_state = recv_state_header_step1,

    /* Interrupt Enable */
    IsrCamRx_Enable();

    /* Send Request */
    UART_TO_CAMERA_PutArray(request, request_size);

    /* Recieve Complete Wait */
    while (1) {
        /* TODO : TIMEOUT */
        if (camera_buff_size <= recv_count) {
            /* Interrupt Disanable */
            IsrCamRx_Disable();
            break;
        }
    }

    return SUCCESS;
}

/* [] END OF FILE */
