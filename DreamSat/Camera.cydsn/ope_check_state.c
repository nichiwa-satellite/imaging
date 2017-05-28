/* ========================================
 *
 * Copyright NICHIWA-SYSTEM, 2017
 * All Rights Reserved
 *
 * ========================================
*/

#include "ope_hello.h"

void OpeCheckState(reply_func reply)
{
    Byte replytext[5] = "state";
    (*reply)(replytext, sizeof(replytext));
}
