/**
 * 
 * generate-a-word.c
*/

#include <stdio.h>
#include <assert.h>

typedef unsigned char *byte_pointer;

int main(int argc, char** argv) {
    size_t mask = 0xff;
    size_t x = 0x89ABCDEF;
    size_t y = 0x76543210;

    size_t res = (x & mask) | (y & ~mask);
    byte_pointer p = (byte_pointer)&res;
    size_t i;
    for ( i = 0; i < sizeof(int); i++) {
        printf("%x",p[i]);
    }
    assert(res == 0x765432EF);
 //   assert(0x)

    return 0;
}