#include "headers/helpers.h"

size_t strlen(const char* str) {
    size_t ret = 0;
    while ( str[ret] != 0 ) ret++;
    return ret;
}

void *memset(void *p, int c, size_t count) {
    for(unsigned int i = 0; i < count; i++) {
        ((char *)p)[i] = c;
    }
    return p;
}
