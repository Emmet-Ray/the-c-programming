#include <stdio.h>

// count the number of 1 in x (binary)
int bitcount(int x);
int main(int argc, char const *argv[])
{
    
    char x = 7;
    short y = 8;
    int z = 9;
    printf("%d  %d  %d\n", bitcount(x),bitcount(y),bitcount(z));
    return 0;
}

int bitcount(int x) {
    int n=0;
    while(x != 0) {

        if(x & 1) // last bit is one
            n++;
        x >>= 1;
        //x &= (x-1);
    }
    return n;
}