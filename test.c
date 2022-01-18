#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
    printf("Testing:\n");
    // READ File
    char buff[10000] = "null";
    char line2[10000] = "null";
    char info[10][58];
    FILE *fp = fopen("./master.txt", "rt");
    fgets(buff, 59, fp);
    fgets(info[1], 60, fp);
    fgets(info[2], 60, fp);
    fgets(info[3], 60, fp);
    // return string in buff into other string
    // strcpy(info[1], buff);
    printf("buff: %s\n", buff);
    printf("info[1]: %s\n", info[1]);
    printf("info[2]:%s\n", info[2]);
    printf("info[3]:%s\n", info[2]);

    // write result
    /*
    FILE *fw = fopen("result.txt", "w+");
    fprintf(fw, "Wite sth");
    */
    return 0;
}