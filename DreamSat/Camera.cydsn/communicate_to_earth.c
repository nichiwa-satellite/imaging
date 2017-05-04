/* ========================================
 *
 * Copyright NICHIWA-SYSTEM, 2017
 * All Rights Reserved
 *
 * ========================================
*/
#include <stdio.h>
#include <string.h>
#include "communicate_to_earth.h"
#include "project.h"

#define STX (0x02)
#define SEND_RELPY_HEADER_SIZE (5)
#define SEND_RELPY_DATA_SIZE (64 * 2)
#define SEND_RELPY_FOOTER_SIZE (2 + 1)
#define SEND_REPLY_SIZE (SEND_RELPY_HEADER_SIZE + SEND_RELPY_DATA_SIZE + SEND_RELPY_FOOTER_SIZE)

uint8 recv_data_buff[COMMAND_SIZE];
int recv_count = 0;
int recv_stx_flg = 0;

void IsrEarthRx()
{
    unsigned char recv_data;
    recv_data = UART_TO_EARTH_GetChar();
    
    if (!recv_stx_flg) {
        if (recv_data == STX) {
            recv_stx_flg = 1;
        }
    } else {
        if (recv_count <= COMMAND_SIZE) {
            recv_data_buff[recv_count] = recv_data;
        } else if (recv_count == COMMAND_SIZE + 1) {
            //TODO : Store Check Digit (BCC)
        } else {
            return;
        }
        recv_count++;
    }
    return;
}

void InitializeUartToEarth()
{
    UART_TO_EARTH_Init();
    UART_TO_EARTH_Start();

    IsrEarthRx_StartEx(IsrEarthRx);
}

void RecieveFromEarth(Byte* command)
{
    recv_count = 0;
    memset(recv_data_buff, 0x00, COMMAND_SIZE);
    IsrEarthRx_Enable();
    while (recv_count <= COMMAND_SIZE) {}
    IsrEarthRx_Disable();

    memcpy(command, recv_data_buff, COMMAND_SIZE);
}

StatusCode SendToEarth64(Byte* reply, size_t reply_size) {
    int i;
    char command[SEND_REPLY_SIZE] = "TXDA ";
    char* temp = command + 5;
    for (i = 0; (i < (int)reply_size && i < 64); i++)
    {
        sprintf(temp, "%02x", *(reply + i));
        temp += 2;
    }
    sprintf(temp, "\r\n");
    UART_TO_EARTH_PutString(command);
    return SUCCESS;
}

StatusCode SendToEarth(Byte* reply, size_t reply_size) {
    while (64 < reply_size)
    {
        SendToEarth64(reply, 64);
        reply += 64;
        reply_size -= 64;
    }
    SendToEarth64(reply, reply_size);
    return SUCCESS;   
}
