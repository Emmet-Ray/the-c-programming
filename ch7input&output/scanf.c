#include <stdio.h>

int main(int argc, char const *argv[])
{
    int month, day, year;
    scanf("m/d/y  %d/  %d/  %d", &month, &day, &year);
    printf("%d/%d/%d", month, day, year);
    return 0;
}
