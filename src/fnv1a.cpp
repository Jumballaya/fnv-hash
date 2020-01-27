#include "fnv1a.h"

#define OFFSET_32 0x811c9dc5
#define OFFSET_64 0xcbf29ce484222325

#define PRIME_32 0x01000193
#define PRIME_64 0x100000001b3

uint64_t fnv1a_hash_64(const char *string) {
    uint64_t prime = PRIME_64;
    uint64_t hash = OFFSET_64;
    int len = strlen(string);

    for (int i = 0; i < len; i++) {
        hash = hash ^ string[i];
        hash = hash * prime;
    }

    // return correct digits, based on size
    return hash;
}

uint32_t fnv1a_hash_32(const char *string) {
    uint32_t prime = PRIME_32;
    uint32_t hash = OFFSET_32;
    int len = strlen(string);

    for (int i = 0; i < len; i++) {
        hash = hash ^ string[i];
        hash = hash * prime;
    }

    // return correct digits, based on size
    return hash;
}