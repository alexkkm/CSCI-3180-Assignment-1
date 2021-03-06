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

// Read the Account Name until the end of the file
void ReadAccountName()
{
    // READ File
    char buff[10000] = "null";
    char input[58];

    // open the master.txt with
    FILE *fp = fopen("./master.txt", "rt");

    // fgets for lineNum times so that we can read the (lineNum)th lines
    while (fgets(buff, 60, fp) != NULL)
    {
        // fgets(buff, 60, fp);
        strcpy(input, buff);
    }

    printf("Account Name:%s\n", str_slice(input, 0, 20));
}

// Read Account Number until end of file
void ReadAccountNumber()
{
    // READ File
    char buff[10000] = "null";
    char input[] = "null";

    // open the master.txt with
    FILE *fp = fopen("./master.txt", "rt");

    // fgets for lineNum times so that we can read the (lineNum)th lines
    while (fgets(buff, 60, fp) != NULL)
    {
        // fgets(buff, 10000, fp);
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

// Read Account Balance
void ReadAccountBalance(int lineNum)
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
    printf("Account Balance:%s\n", str_slice(input, 42, 16));
}

int main()
{
    printf("Testing:\n");
    ReadAccountName(11);
    ReadAccountNumber(11);
    ReadAccountPassword(11);
    ReadAccountBalance(11);

    return 0;
}
