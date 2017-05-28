/* ========================================
 *
 * Copyright NICHIWA-SYSTEM, 2017
 * All Rights Reserved
 *
 * ========================================
*/

#include "ope_delete_image.h"

void OpeDeleteImage(reply_func reply) {
    Byte replytext[6] = "delete";
    (*reply)(replytext, sizeof(replytext));
}
