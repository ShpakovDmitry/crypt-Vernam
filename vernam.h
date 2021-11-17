/*
 * file:   vernam.h 
 * author: Shpakov Dmitry
 * date:   2021-11-17
 *
 */

#ifndef __VERNAM_H__
#define __VERNAM_H__

#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

/* 'data' is rewritten with encrypted/decrypted data */
/* 'len' is data and key length in bytes */
typedef struct {
    size_t len;
    char* data;
    char* key;
} VernamData;

/* this method simply does (data ^ key) operation */
void Vernam_crypt(VernamData* data);

#ifdef __cplusplus
}
#endif

#endif//__VERNAM_H__
