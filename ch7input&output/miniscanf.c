#include <stdio.h>
#include <stdarg.h>
#include <ctype.h>
#include <string.h>
//****************** this is buggy!!!
void miniscanf(char *fmt, ...);
int main(int argc, char const *argv[])
{
    int i;
    double f;
    char s[100]; 
    miniscanf("  %f  %d", &f, &i);
    printf("%f %d", f, i);
    return 0;
}
void miniscanf(char *fmt, ...) {
    va_list ap;
    char *p;
    int *ivalue;
    double *fvalue;
    char s[100];
    va_start(ap, fmt);
    
    for(p = fmt; *p; p++) {
        if (isspace(*p)) {
            continue;
        }
        if(*p == '%'){
            switch (*++p)
            {
            case 'd' :
                ivalue = va_arg(ap, int *);
                scanf("%d", ivalue);
                break;
            case 'f' :
                fvalue = va_arg(ap, double *);
                scanf("%f", fvalue);
                break;
            /*
            case 's' :
                scanf("%s", s);
                for(int i = 0; i < strlen(s); i++) 
                    *(char *)va_arg(ap, char *) = s[i];
            **/
            default:
                break;
            }
        }
   }
   va_end(ap);
}
