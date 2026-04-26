/*
Figure 2.4

Uses casting to access and PRINT THE BYTE REPRESENTATIONS OF C PROGRAM OBJECTS OF TYPE INT, FLOAT, VOID *.
We use typedef to define data type byte_pointer as a pointer to an object of type unsigned char.

This code uses casting to circumvent the type system. This cast indicates to the compiler that the program should
consider the pointer to be a sequence of bytes rather than to an object of the original data type.

You will see that the values are stored in Little-Endian.
*/

#include <stdio.h>

typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start, size_t len);
void show_int(int x);
void show_float(float x);
void show_pointer(void *x);

int main(void)
{
    int x = 12345;                   // 0x00003039 stored as 39 30 00 00
    float fval = (float) x;          // 0x41280000 stored as 00 00 28 41
    int *pval = &x;                  // 0x000000045d5ff76c stored as 6c f7 5f 5d 04 00 00 00

    printf("%s", "int 12345 -> ");
    show_int(x);

    printf("%s", "float 12345.0 -> ");
    show_float(fval);

    printf("%s", "pointer pval -> ");
    show_pointer(pval);
}

void show_bytes(byte_pointer start, // address of a sequence of bytes
    size_t len)                     // byte count from size_t
{
    int i;
    for (i = 0; i < len; i++) {
        printf(" %.2x", start[i]); // indicates an integer should be printed in hex with 2 digits
    }

    puts("");
}

void show_int(int x) 
{
    show_bytes((byte_pointer) &x, sizeof(int));
}

void show_float(float x) 
{
    show_bytes((byte_pointer) &x, sizeof(float));
}

void show_pointer(void *x) 
{
    show_bytes((byte_pointer) &x, sizeof(void *));
}