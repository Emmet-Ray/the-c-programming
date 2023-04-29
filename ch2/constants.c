#include <stdio.h>

int main(int argc, char const *argv[])
{
    enum boolean {NO, YES};
    printf("a\vb\n");
    printf("%d %d %d\n", 31, 037, 0x1f);
    printf("%f\n", 1.0);
    printf("hello, ""world\n");
    printf("YES : %d\n", YES);
    printf("NO : %d\n", NO);
    return 0;
}