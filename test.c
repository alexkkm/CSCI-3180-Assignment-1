#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void str_slice(char *text, int position, int length)
{
    char subtext[length];
    strncpy(subtext, &text[position], length - 1);
    subtext[length - 1] = '\0';
    printf("The original string is:%s\n", text);
    printf("Substring is:%s", subtext);
}

char *str_cut(char *text, int position, int length)
{
    char subtext[length];
    strncpy(subtext, &text[position], length - 1);
    subtext[length - 1] = '\0';
    static char str[16]; // strictly be 16
    strcpy(str, subtext);
    return str;
}

int main(void)
{
    // str_slice("012345678901234567890", 2, 18);
    printf("%s", str_cut("012345678901234567890", 2, 18));

    return 0;
}