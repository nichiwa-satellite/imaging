/* ========================================
 *
 * Copyright NICHIWA-SYSTEM, 2017
 * All Rights Reserved
 *
 * ========================================
*/

#include "ope_hello.h"

void OpeHello(reply_func reply)
{
    Byte replytext[5] = "HELLO";
    (*reply)(replytext, sizeof(replytext));
}
