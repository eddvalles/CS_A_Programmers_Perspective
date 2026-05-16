/*
INT32-C. Ensure that operations on signed integers do not result in overflow.

Enter two integers: 2000000000 2000000000
Overflow! 2000000000 + 2000000000 cannot be represented as a signed int
*/

#include <stdio.h>
#include <limits.h>

void f(signed int si_a, signed int si_b);

int main(void)
{
    signed int a, b;

    printf("Enter two integers: ");
    scanf("%d %d", &a, &b);

    f(a,b);

    return 0;
}

void f(signed int si_a, signed int si_b)
{
    signed int sum;
    if (((si_b > 0) && (si_a > (INT_MAX - si_b)))
        || ((si_b < 0) && (si_a < (INT_MIN - si_b)))) {
            printf("Overflow! %d + %d cannot be represented as a signed int.\n", si_a, si_b);
    } else {
        printf("%d + %d = %d\n", si_a, si_b, si_a + si_b);
    }
}