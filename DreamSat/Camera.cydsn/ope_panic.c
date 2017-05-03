/* ========================================
 *
 * Copyright NICHIWA-SYSTEM, 2017
 * All Rights Reserved
 *
 * ========================================
*/

#include "ope_panic.h"

void OpePanic(reply_func reply)
{
    ReplyDigit replytext[5] = "PANIC";
    (*reply)(replytext, sizeof(replytext));
}
