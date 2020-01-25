#include "fnv1a.h"

#define FNV_OFFSET 0xcbf29ce484222325
#define FNV_PRIME 0x100000001b3


unsigned long fnv1a_hash(const char *string) {
    unsigned long hash = FNV_OFFSET;
    int len = strlen(string);

    for (int i = 0; i < len; i++) {
        hash = hash ^ string[i];
        hash = hash * FNV_PRIME;
    }

    return hash;
}