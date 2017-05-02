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

void ReceiveCommand(cmd_digit* command)
{
    memcpy(command, "\x02Hello", COMMAND_SIZE);
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
