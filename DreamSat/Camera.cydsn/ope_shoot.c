/* ========================================
 *
 * Copyright NICHIWA-SYSTEM, 2017
 * All Rights Reserved
 *
 * ========================================
*/

#include "ope_shoot.h"

void OpeShoot(reply_func reply) {
    Byte replytext[5] = "SHOOT";
    (*reply)(replytext, sizeof(replytext));
}
