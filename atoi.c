#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Copy the (length) characters form (target) string form (poisition)th position
char *str_slice(char *target, int position, int length)
{
    char *temp = (char *)malloc(strlen(target) * sizeof(char));
    char subtext[length];
    strncpy(subtext, &target[position], length);
    subtext[length] = '\0';
    strcpy(temp, subtext);
    return temp;
}

char *LargeNumberToString(int *largeNumber)
{
    static char str[16];
    char buff[4];
    for (int i = 0; i < 4; i++)
    {
        sprintf(buff, "%d", largeNumber[i]);
        strcat(str, buff);
    }
    return str;
}

// Large Number Calculation
int *StringToLargeNumber(char *source)
{
    static int b[4] = {0, 0, 0, 0};
    b[3] = atoi(str_slice(source, 12, 4));
    b[2] = atoi(str_slice(source, 8, 4));
    b[1] = atoi(str_slice(source, 4, 4));
    b[0] = atoi(str_slice(source, 0, 4));
    return b;
}

int main()
{
    int *l;
    l = StringToLargeNumber("1234567890123456");
    printf("%d", l[0]);
    return 0;
}