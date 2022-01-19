#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void simple_str_slice(char *text, int position, int length)
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

char *str_slice(char *target, int position, int length)
{
    char *temp = (char *)malloc(strlen(target) * sizeof(char));
    char subtext[length];
    strncpy(subtext, &target[position], length - 1);
    subtext[length - 1] = '\0';
    strcpy(temp, subtext);
    return temp;
}

int main(void)
{
    // str_slice("012345678901234567890", 2, 18);
    printf("%s", str_slice("012345678901234567890", 2, 18));

    return 0;
}