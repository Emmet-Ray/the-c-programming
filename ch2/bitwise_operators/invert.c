#include <stdio.h>


// !!!!!!!!!!!!!!!!       use getbits, setbits to do the job, step by step
int invert(int x,int p,int n);


int getbits(int x, int p, int n){
    return (x >> (p+1-n)) & ~(~0 << n);
}
int setbits(int x, int p, int n, int y) {
    int temp1 = ~0 << (p + 1); // mask off lower n bits 
    int temp2 = ~(~0 << (p+1-n));
    int mask = temp1 | temp2;  // used to mask off the replaced bits in the middle, but leave other bits
    int not_mask = ~mask;  // used to leave the desired bits in y, mask off other bits;
    return (x & mask) | (y & not_mask);
}
int main(int argc, char const *argv[])
{
    int x = 7;
    printf("%d\n", invert(x, 2, 3)); // should be 0
    return 0;
}

int invert(int x,int p,int n) {
    int temp = getbits(x, p, n);
    temp = getbits(~x, p, n); 
    temp = temp << (p+1-n);
    return setbits(x, p, n, temp);
}