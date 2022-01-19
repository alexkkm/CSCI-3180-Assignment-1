#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Read from master.txt
void readfile(int targetID)
{
    // READ File
    char buff[10000] = "null";
    char input[58];

    // open the master.txt with
    FILE *fp = fopen("./master.txt", "rt");

    /*
    while ((fgets(buff, 10000, fp) != NULL) && (id <= targetID))
    {
        fgets(buff, 10000, fp);
        strcpy(input, buff);
        id++;
    }
    */

    for (int i = 0; i < targetID; i++)
    {
        fgets(buff, 10000, fp);
        strcpy(input, buff);
    }

    printf("%s", input);
}

// Write result into new document
void writefile()
{
    FILE *fw = fopen("result.txt", "w+"); // w+: create a document, and if the document exist, delete the existing document
    fprintf(fw, "Wite sth");
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

    printf("%s", str_slice(input, 0, 20));
}

// Not success
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
    strcpy(i, str_slice(input, 20, 36));
    // strcpy(i, str_slice(i, 0, -2));
    printf("%s", i);
}

// Success
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
    printf("%s", str_slice(input, 36, 42));
}

void TestGetFirstUserAccount()
{
    char str[] = "abcdefghijkl";
    printf("%d", strcmp(str_slice(str, 0, 2), "def") == 0);
}

int main()
{
    printf("Testing:\n");
    ReadAccountPassword(1);
    return 0;
}
