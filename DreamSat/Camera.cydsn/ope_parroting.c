/* ========================================
 *
 * Copyright NICHIWA-SYSTEM, 2017
 * All Rights Reserved
 *
 * ========================================
*/

#include "ope_parroting.h"

void OpeParroting(reply_func reply) {
    Byte replytext[6] = "PARROT";
    (*reply)(replytext, sizeof(replytext));
}
