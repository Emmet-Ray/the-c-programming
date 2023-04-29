#include <stdio.h>

int setbits(int x, int p, int n, int y);
int main(int argc, char const *argv[])
{
    int x, y;
    x = 2;
    y = 1;    

    printf("%d\n", setbits(x, 5, 0, y));
    return 0;
}

int setbits(int x, int p, int n, int y) {
    int temp1 = ~0 << (p + 1); // mask off lower n bits 
    int temp2 = ~(~0 << (p+1-n));
    int mask = temp1 | temp2;  // used to mask off the replaced bits in the middle, but leave other bits
    int not_mask = ~mask;  // used to leave the desired bits in y, mask off other bits;
    return (x & mask) | (y & not_mask);
}