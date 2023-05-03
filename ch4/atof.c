#include <stdio.h>
#include <ctype.h>
#include <math.h>
double atof_simple(char s[]);
int main(int argc, char const *argv[])
{
    char s1[] = "123.45";
    char s2[] = "123.45e-3";
    char s3[] = "123.45e2";
    printf("s1 : %g\ts2 : %g\ts3 : %g\n", atof(s1), atof(s2), atof(s3));
    return 0;
}
double atof_simple(char s[]) {
    int i,sign;
    double value, power;
    for(i = 0; isspace(s[i]); i++)
        ;
    sign = (s[i] == '-') ? -1 : 1;
    if(sign == '-' || sign == '+') 
        i++;
    for(value = 0.0; isdigit(s[i]); i++)
        value = 10.0 * value + s[i] - '0';
    if(s[i] == '.')
        i++;
    for(power = 1.0; isdigit(s[i]); i++){
        value = 10.0 * value + s[i] - '0';
        power *= 10;
    }
    if(s[i] == 'e' || s[i] == 'E')
        i++;
    if(s[i] == '-') {
        i++;
        int x = atof_simple((char*)s[i]);
        power *= pow(10, x);
    } else {
        int x = atof_simple((char*)s[i]);
        power /= pow(10, x);
    }

    return sign * value / power;
}
