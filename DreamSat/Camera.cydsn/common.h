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

typedef enum {
    kstatus_code_success,
    kstatus_code_error
}StatusCode;

typedef enum {
    kcmd_hello,
    kcmd_panic,
    kcmd_parroting
}CommandType;


#endif //DREAMSAT_CAMERA_COMMON_H_
