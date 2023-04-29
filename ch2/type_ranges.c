#include <stdio.h>
#include <limits.h>
#include <float.h>

// determint the ranges of different integral types
// char short int long, signed and unsigned
int main(int argc, char const *argv[])
{
    printf("CHAR_BIT : %d\n", CHAR_BIT); 
    printf("UCHAR_MIN : %d\n", 0);
    printf("UCHAR_MAX : %d\n", UCHAR_MAX);
    printf("SCHAR_MIN : %d\n", SCHAR_MIN);
    printf("SCHAR_MAX : %d\n", SCHAR_MAX);
    printf("\n");

    printf("USHRT_MIN : 0\n");
    printf("USHRT_MAX : %d\n", USHRT_MAX); // short 16 bits
    printf("SHRT_MIN : %d\n", SHRT_MIN);
    printf("SHRT_MAX : %d\n", SHRT_MAX);
    printf("\n");

    printf("UINT_MIN : %d\n", 0);
    printf("UINT_MAX : %u\n", UINT_MAX); // %u format specifier of unsigned int
    printf("INT_MIN : %d\n", INT_MIN);   // int 32 bits
    printf("INT_MAX : %d\n", INT_MAX);
    printf("\n");

    printf("ULONG_MIN : 0\n");
    printf("ULONG_MAX : %lu\n", ULONG_MAX); // long 32 bits
    printf("LONG_MIN : %ld\n", LONG_MIN);
    printf("LONG_MAX : %ld\n", LONG_MAX);
    printf("\n");

    printf("FLT_RADIX : %d\n", FLT_RADIX);
    printf("FLT_DIG : %d\n", FLT_DIG);
    printf("FLT_MIN : %f\n", FLT_MIN);
    printf("FL_MIN_EXP : %d\n", FLT_MIN_EXP);
    printf("FLT_MAX : %f\n", FLT_MAX);
    printf("FLT_MAX_EXP : %d\n", FLT_MAX_EXP);
    printf("\n");

    printf("DBL_DIG : %d\n", DBL_DIG);
    printf("DBL_MIN : %f\n", DBL_MIN);
    printf("DBL_MIN_EXP : %d\n", DBL_MIN_EXP);
    printf("DBL_MAX : %f\n", DBL_MAX);
    printf("DBL_MAX_EXP : %d\n", DBL_MAX_EXP);
    printf("\n"); 
    return 0;
}
