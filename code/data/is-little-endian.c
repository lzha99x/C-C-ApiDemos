/***
 *is-little-endian.c 
 *
 * 0x123456   --> is big endian
 * 0x563412   --> is little endian.
 */

#include <stdio.h>
#include <assert.h>

typedef unsigned char* byte_pointer;

int is_little_endian() {
    int test_num = (~0x0) & (0xff);
    byte_pointer byte_start = (byte_pointer) &test_num;

    if ( byte_start[0] ==  0xff) {
        return 1;
    } else {
        return 0;
    }
}


void main (void) {
    assert(is_little_endian());
}
