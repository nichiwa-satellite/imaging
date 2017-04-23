/* ========================================
 *
 * Copyright NICHIWA-SYSTEM, 2017
 * All Rights Reserved
 *
 * ========================================
*/

#ifndef DREAMSAT_CAMERA_OPERATION_H_
#define DREAMSAT_CAMERA_OPERATION_H_

#include <stddef.h>

typedef unsigned char reply_digit;
typedef int (*reply_func)(reply_digit*, size_t);

void OpeHello(reply_func);
void OpePanic(reply_func);
void OpeParroting(reply_func);

#endif //DREAMSAT_CAMERA_OPERATION_H_
