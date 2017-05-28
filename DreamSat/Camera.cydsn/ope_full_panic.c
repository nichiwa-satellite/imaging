/* ========================================
 *
 * Copyright NICHIWA-SYSTEM, 2017
 * All Rights Reserved
 *
 * ========================================
*/

#include "ope_hello.h"

void OpeFullPanic(reply_func reply)
{
    Byte replytext[7] = "F-PANIC";
    (*reply)(replytext, sizeof(replytext));
}
