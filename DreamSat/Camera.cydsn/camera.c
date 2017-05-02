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

//struct
typedef struct recieveinfotag
{
    unsigned char   *buffer;
    unsigned int    buffer_size;
} recieveinfo;

//Variables
static unsigned char *recievebuffer;
static unsigned char recievebuffer_size;

rettype Camera_Initialize()
{
    UART_TO_CAMERA_Init();
    UART_TO_CAMERA_Start();
    Cam_Rx_Intr_StartEx(Cam_Rx_Intr );
    Cam_Rx_Intr_Disable();
}

rettype SendRequest(request_digit* request, size_t request_size, unsigned char *buffer, unsigned int buffer_size )
{
    recievebuffer = buffer;
    recievebuffer_size = buffer_size;
}

/* [] END OF FILE */
