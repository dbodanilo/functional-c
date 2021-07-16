#include <stdio.h>

void printnum(unsigned long long n, int (*p)(int))
{
    if(n >= 10)
        printnum(n/10, p);
    (*p) (n % 10 + '0');
}

int main() {
    unsigned long long val = 1234567890123456789;

    // printf("%llu\n", val);

    printnum(val, putchar);

    return 0;
}
