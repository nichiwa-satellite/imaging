/* ========================================
 *
 * Copyright NICHIWA-SYSTEM, 2017
 * All Rights Reserved
 *
 * ========================================
*/

#include "ope_hello.h"

void OpeDeleteImage(reply_func reply)
{
    Byte replytext[6] = "delete";
    (*reply)(replytext, sizeof(replytext));
}
