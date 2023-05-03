#include <stdio.h>

void reverse_helper(char s[], int left, int right) {
    if (left < right) {
        char temp = s[left];
        s[left] = s[right];
        s[right] = temp;
        reverse_helper(s, ++left, --right);
    } else {
        return;
    }
}
void reverse(char s[]) {
    int i = 0;
    while(s[i] != '\0')
        i++;
    reverse_helper(s, 0, i - 1);
}
int main(int argc, char const *argv[])
{
    char s[] = "123456"; 
    char s1[] = "1234567";
    printf("%s  %s\n", s, s1);
    reverse(s);
    reverse(s1);
    printf("%s  %s", s, s1);
    return 0;
}
