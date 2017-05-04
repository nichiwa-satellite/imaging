/* ========================================
 *
 * Copyright NICHIWA-SYSTEM, 2017
 * All Rights Reserved
 *
 * ========================================
*/

#ifndef DREAMSAT_CAMERA_COMMON_H_
#define DREAMSAT_CAMERA_COMMON_H_

typedef unsigned char Byte;

typedef enum {
    SUCCESS,
    ERROR
}StatusCode;

typedef enum {
    HELLO,
    PANIC,
    PARROTTING
}CommandType;


#endif //DREAMSAT_CAMERA_COMMON_H_
