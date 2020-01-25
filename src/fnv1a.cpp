#include "fnv1a.h"

unsigned long offsets[2] = {
    0x811c9dc5,
    0xcbf29ce484222325
};

unsigned long primes[2] = {
    0x01000193,
    0x100000001b3
};

unsigned long get_prime(int size) {
    switch (size) {
        case 32: {
            return primes[0];
        }
        case 64: {
            return primes[1];
        }
        default: {
            return primes[0];
        }
    }
}

unsigned long get_offset(int size) {
    switch (size) {
        case 32: {
            return offsets[0];
        }
        case 64: {
            return offsets[1];
        }
        default: {
            return offsets[0];
        }
    }
}

unsigned long fnv1a_hash(const char *string, int size) {
    unsigned long prime = get_prime(size);
    unsigned long hash = get_offset(size);
    int len = strlen(string);

    for (int i = 0; i < len; i++) {
        hash = hash ^ string[i];
        hash = hash * prime;
    }

    // return correct digits, based on size
    return (hash << size) >> size;
}