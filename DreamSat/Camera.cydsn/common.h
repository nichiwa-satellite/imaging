/* ========================================
 *
 * Copyright NICHIWA-SYSTEM, 2017
 * All Rights Reserved
 *
 * ========================================
*/

#ifndef DREAMSAT_CAMERA_COMMON_H_
#define DREAMSAT_CAMERA_COMMON_H_

typedef unsigned char cmd_digit;

typedef enum rettypetag
{
    ret_success,
    ret_error
}rettype;

typedef enum cmdtypetag
{
    cmd_hello,
    cmd_panic,
    cmd_parroting
}cmdtype;

void InitializeUart();

#endif //DREAMSAT_CAMERA_COMMON_H_
