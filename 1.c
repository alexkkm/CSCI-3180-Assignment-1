

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define BIGNUM 30

int main()
{
    printf("Testing:\n");
    // READ File
    char buff[10000] = "null";
    char info[BIGNUM][58];
    FILE *fp = fopen("./master.txt", "rt");

    int line = 1;
    while (fgets(buff, 60, fp) != NULL)
    {
        strcpy(info[line], buff);
        line++;
    }

    printf("%s", info[1]);
    /*
    // print out all lines
        for (int i = 1; i <= BIGNUM; i++)
        {
            printf("line%d: %s\n", i, info[i]);
        }
    */
    return 0;
}