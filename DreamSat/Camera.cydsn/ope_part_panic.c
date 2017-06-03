/* ========================================
 *
 * Copyright NICHIWA-SYSTEM, 2017
 * All Rights Reserved
 *
 * ========================================
*/

#include "ope_part_panic.h"

void OpePartPanic(reply_func reply) {
    Byte replytext[7] = "P-PANIC";
    (*reply)(replytext, sizeof(replytext));
}
