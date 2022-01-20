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

void test()
{
    // READ File
    char buff[10000] = "null";
    char input[58];
    int found = 0;

    // open the master.txt with
    FILE *fp = fopen("./master.txt", "rt");
    fgets(buff, 10000, fp);
    strcpy(input, buff);
    fclose(fp);
    fp = fopen("./master.txt", "rt");
    strcpy(input, buff);
    fclose(fp);
    printf("Account Name:%s\n", str_slice(input, 0, 20));
}

// Read the Account Name
void ReadAccountName(int lineNum)
{
    // READ File
    char buff[10000] = "null";
    char input[58];

    // open the master.txt with
    FILE *fp = fopen("./master.txt", "rt");

    // fgets for lineNum times so that we can read the (lineNum)th lines
    for (int i = 0; i < lineNum; i++)
    {
        fgets(buff, 10000, fp);
        strcpy(input, buff);
    }

    printf("Account Name:%s\n", str_slice(input, 0, 20));
}

// Read Account Number
void ReadAccountNumber(int lineNum)
{
    // READ File
    char buff[10000] = "null";
    char input[] = "null";

    // open the master.txt with
    FILE *fp = fopen("./master.txt", "rt");

    // fgets for lineNum times so that we can read the (lineNum)th lines
    for (int i = 0; i < lineNum; i++)
    {
        fgets(buff, 10000, fp);
        strcpy(input, buff);
    }
    char i[] = "null";
    strcpy(i, str_slice(input, 20, 16));
    printf("Account Number:%s\n", i);
}

// Read Account Password
void ReadAccountPassword(int lineNum)
{
    // READ File
    char buff[10000] = "null";
    char input[] = "null";

    // open the master.txt with
    FILE *fp = fopen("./master.txt", "rt");

    // fgets for lineNum times so that we can read the (lineNum)th lines
    for (int i = 0; i < lineNum; i++)
    {
        fgets(buff, 10000, fp);
        strcpy(input, buff);
    }
    printf("Account Password:%s\n", str_slice(input, 36, 6));
}

int main()
{
    printf("Testing:\n");
    ReadAccountName(1);
}