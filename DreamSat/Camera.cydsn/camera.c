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

//Prototypes
CY_ISR_PROTO(Cam_Rx_Intr);

//Variables
static unsigned char   *buffer;
static unsigned int    buffer_size;
static unsigned int    recieve_size;

void Camera_Initialize()
{
    /* UART Device Init */
    UART_TO_CAMERA_Init();
    UART_TO_CAMERA_Start();

    /* Interrupt Init */
    Cam_Rx_Intr_StartEx(Cam_Rx_Intr );

    /* Interrupt Disable */
    Cam_Rx_Intr_Disable();
}

rettype SendRequest(request_digit* request, size_t request_size, unsigned char *recievebuffer, unsigned int recievebuffer_size )
{
    /* Parameter Check */
    if (recievebuffer == NULL) {
        return ret_error;    
    }

    /* Parameter Check */
    if (buffer_size == 0) {
        return ret_error;
    }

    /* Recieve Setup */
    buffer = recievebuffer;
    buffer_size = recievebuffer_size;
    recieve_size = 0;

    /* Interrupt Enable */
    Cam_Rx_Intr_Enable();

    /* Send Request */
    UART_TO_CAMERA_PutArray(request,request_size);

    /* Recieve Complete Wait */
    while (1) {
        /* TODO : TIMEOUT */
        if (buffer_size <= recieve_size) {
            /* Interrupt Disanable */
            Cam_Rx_Intr_Enable();
            break;
        }
    }

    return ret_success;
}

#pragma interrupt_handler Cam_Rx_Intr

void Cam_Rx_Intr()
{
    unsigned int index;
    unsigned char recv_data;

    /* 1 byte Data Read From UART */
    recv_data = UART_TO_CAMERA_GetChar();

    /* Set Index */
    index = recieve_size;
    
    /* Parameter Check */
    if (buffer == NULL) {
        return;
    }
    
    /* Buffer Overflow */
    if (buffer_size <= recieve_size) {
        return;
    }

    buffer[index] = recv_data;
    recieve_size++;

    return;
}

/* [] END OF FILE */
