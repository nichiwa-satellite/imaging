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

unsigned char recv_data_buff[COMMAND_SIZE];
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
        recv_data_buff[recv_count] = recv_data;
        recv_count++;
    }
    return;
}

void InitializeCommUart()
{
    UART_TO_EARTH_Init();
    UART_TO_EARTH_Start();

    IsrEarthRx_StartEx(IsrEarthRx);
}

void ReceiveCommand(cmd_digit* command)
{
    recv_count = 0;
    IsrEarthRx_Enable();
    while (recv_count <= COMMAND_SIZE) {}
    IsrEarthRx_Disable();

    memcpy(command, recv_data_buff, COMMAND_SIZE);
}

rettype SendReply64(reply_digit* reply, size_t reply_size) {
    int i;
    char command[5 + 64 * 2 + 2 + 1] = "TXDA ";
    char* temp = command + 5;
    for (i = 0; (i < (int)reply_size && i < 64); i++)
    {
        sprintf(temp, "%02x", *(reply + i));
        temp += 2;
    }
    sprintf(temp, "\r\n");
    UART_TO_EARTH_PutString(command);
    return ret_success;
}

rettype SendReply(reply_digit* reply, size_t reply_size) {
    while (64 < reply_size)
    {
        SendReply64(reply, 64);
        reply += 64;
        reply_size -= 64;
    }
    SendReply64(reply, reply_size);
    return ret_success;   
}
