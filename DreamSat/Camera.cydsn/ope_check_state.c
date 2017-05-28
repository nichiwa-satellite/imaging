/* ========================================
 *
 * Copyright NICHIWA-SYSTEM, 2017
 * All Rights Reserved
 *
 * ========================================
*/

#include "ope_check_state.h"

void OpeCheckState(reply_func reply) {
    Byte replytext[5] = "state";
    (*reply)(replytext, sizeof(replytext));
}
