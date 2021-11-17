/*
 * file:   vernam.c
 * author: Shpakov Dmitry
 * date:   2021-11-17
 *
 */

#include <stdbool.h>
#include "vernam.h"

static bool isVernamDataCorrect(VernamData* data) {
    bool res;

    if (data->len == 0) {
        res = false;
    } else if (data->data == NULL) {
        res = false;
    } else if (data->key == NULL) {
        res = false;
    } else {
        res = true;
    }

    return res;
}

/* straight forward Vernam cipher realisation */
void Vernam_crypt(VernamData* data) {
    if ( !isVernamDataCorrect(data) ) {
        return;
    }

    for (size_t i = 0; i < data->len; i++) {
        data->data[i] ^= data->key[i];
    }
}
