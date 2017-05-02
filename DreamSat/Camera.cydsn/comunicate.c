/* ========================================
 *
 * Copyright NICHIWA-SYSTEM, 2017
 * All Rights Reserved
 *
 * ========================================
*/
#include <stdio.h>
#include <string.h>
#include "comunicate.h"
#include "project.h"

#pragma interrupt_handler CmdRxIntr

#define STX_DEF (0x02)

unsigned char recv_data_buff[COMMAND_SIZE];
int recv_count = 0;
int recv_stx_flg = 0;

void CmdRxIntr()
{
    unsigned char recv_data;
    recv_data = UART_TO_CAMERA_GetChar();
    
    if (!recv_stx_flg) {
        if (recv_data == STX_DEF) {
            recv_stx_flg = 1;
        }
    } else {
        recv_data_buff[recv_count] = recv_data;
        recv_count++;
    }
    return;
}

void InitializeUart()
{
    UART_TO_COMM_Init();
    UART_TO_COMM_Start();

    Comm_Rx_Intr_StartEx(CmdRxIntr);
}

void ReceiveCommand(cmd_digit* command)
{
    recv_count = 0;
    Comm_Rx_Intr_Enable();
    while (recv_count > COMMAND_SIZE) {}
    Comm_Rx_Intr_Disable();

//    memcpy(command, "\x02Hello", COMMAND_SIZE);
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
    UART_TO_COMM_PutString(command);
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
