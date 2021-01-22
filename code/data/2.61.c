/**
 * 
 * 2.61.c
*/

#include <stdio.h>
#include <assert.h>

int A(int x) {
    return !(~x);
}

int main ( void ) {
    int all_bit_one = ~0;

    assert(A(all_bit_one));
}