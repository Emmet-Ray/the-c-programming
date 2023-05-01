#include <stdio.h>
#include <limits.h>
#include <string.h>
// convert n to character in s
void itoa(int n, char s[]);

void reverse(char s[]);
int main(int argc, char const *argv[])
{
    char s[256];
    printf("%d\n", INT_MIN);
    itoa(INT_MIN, s);
    printf("%s", s);
    return 0;
}

void itoa(int n, char s[]) {

    int i, sign;
    i = 0;
    // consider of largest negative number
    if(n < 0 && (n << 1) == 0) {
        do{
            s[i++] = -(n%10) + '0';
        } while((n /= 10) != 0);
        s[i++] = '-';
        s[i] = '\0';
        reverse(s);
        return;
    }
    if((sign = n) < 0) {
        n = -n;
    }
    do{
        s[i++] = n % 10 + '0';
    } while ((n /= 10) > 0);
    if(sign < 0) 
        s[i++] = '-';
    s[i] = '\0'; 
    reverse(s);
}
void reverse(char s[]) {
    int i, j, temp;
    for(i = 0, j = strlen(s) - 1; i < j; i++, j--) {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
}