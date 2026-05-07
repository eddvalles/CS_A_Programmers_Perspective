/*
When run as a 32-bit program on a big-endian machine, that uses a two's complement representation, this
code prints the output:

sx = -12345:    cf c7
usx = 53191:    cf c7
x   = -12345:   ff ff cf c7     // sign extended; 16 copies of the most significant bit 1
ux  = 53191:    00 00 cf c7     // sign extended; 16 copies of the most significant bit 0
*/

#include <stdio.h>

typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start, size_t len);

int main(void)
{
    short sx = -12345;          /* -12345 */
    unsigned short usx = sx;    /*  53191 */
    int x = sx;                 /* -12345 */
    unsigned ux = usx;          /*  53191 */

    printf("%sx = %d:\t", sx);
    show_bytes((byte_pointer) &sx, sizeof(short));

    printf("usx = %u:\t", usx);
    show_bytes((byte_pointer) &usx, sizeof(unsigned short));

    printf("x    = %d:\t", x);
    show_bytes((byte_pointer) &x, sizeof(int));

    printf("%ux    = %u\t", ux);
    show_bytes((byte_pointer) &ux, sizeof(unsigned));
}

void show_bytes(byte_pointer start, size_t len)
{
    int i;
    for (i = 0; i < len; i++) {
        printf("%.2x", start[i]); // indicates an integer should be printed in hex with 2 digits
    }

    puts("");
}
