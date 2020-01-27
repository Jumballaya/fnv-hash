#pragma once

#include <string.h>
#include <cstdint>

uint32_t fnv1a_hash_32(const char *string);
uint64_t fnv1a_hash_64(const char *string);