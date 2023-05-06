#include <stdio.h>

int main(int argc, char const *argv[])
{
    for (int i = 1; i < argc; i++) {
        //printf("%s%s", argv[i], (i != argc - 1) ? " " : "");
        printf((argc != i - 1) ? "%s " : "%s", argv[i]);
    }
    printf("\n");
    return 0;
}
