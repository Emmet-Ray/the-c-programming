#include <stdio.h>
#include <string.h>

int main() {
    int a[26];
    memset(a, 0, 26*sizeof(int));
    for(int i = 0; i< 26; i++) {
        putchar(a[i]);
    }
}