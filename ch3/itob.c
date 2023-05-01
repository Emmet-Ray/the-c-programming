#include <stdio.h>
#include <string.h>
#include <limits.h>
// binary representation in s
void reverse(char s[]);
void itob(int n, char s[]);
int main(int argc, char const *argv[])
{
    int x = 8;
    char s[256];
    itob(x, s); 
    printf("%s", s);
    return 0;
}

void itob(int n, char s[]) {
    int i, sign, j, type_length;
    i = 0;
    j = 0; // indicate number length
    // consider of largest negative number
    if(n < 0 && (n << 1) == 0) {
        do{
            s[i++] = -(n%2) + '0';
        } while((n /= 2) != 0);
        //s[i++] = '-';
        s[i] = '\0';
        reverse(s);
        return;
    }
    if((sign = n) < 0) {
        n = -n;
    }
    do{
        s[i++] = n % 2 + '0';
        j++; // number length ++
    } while ((n /= 2) > 0);

    type_length = 8 * sizeof(int); 
    if(sign < 0 && j < type_length) {
        for(;j < type_length; j++) {
            s[i++] = '1';
        }
    } else if (sign > 0 && j < type_length) {
        for(;j < type_length; j++) {
            s[i++] = '0';
        }
    }
    /*
    if(sign < 0) 
        s[i++] = '-';
    */
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