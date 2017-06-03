/* ========================================
 *
 * Copyright NICHIWA-SYSTEM, 2017
 * All Rights Reserved
 *
 * ========================================
*/

#include "ope_send_image.h"

void OpeSendImage(reply_func reply) {
    Byte replytext[6] = "SEND-I";
    (*reply)(replytext, sizeof(replytext));
}
