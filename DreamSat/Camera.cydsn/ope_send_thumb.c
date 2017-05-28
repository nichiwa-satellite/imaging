/* ========================================
 *
 * Copyright NICHIWA-SYSTEM, 2017
 * All Rights Reserved
 *
 * ========================================
*/

#include "ope_hello.h"

void OpeSendThumb(reply_func reply)
{
    Byte replytext[6] = "SEND-T";
    (*reply)(replytext, sizeof(replytext));
}
