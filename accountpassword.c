#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

// Read all lines into the buff
void ReadAllLine()
{
    // READ File
    char buff[10000] = "null";
    char input[59];

    // open the master.txt with
    FILE *fp = fopen("./master.txt", "rt");
    // fgets for lineNum times so that we can read the (lineNum)th lines
    while (fgets(buff, 60, fp) != NULL)
    {
        strcpy(input, buff);
        printf("Input: %s\n", input);
    }
}

// Return 0 if account password pair not found, return 1 if found
int CheckAccountPassword(char *account, char *password)
{
    // READ File
    char buff[60] = "null";
    char input[59];
    int valid = 0;
    char correctAccount[17];
    char correctPassword[7];

    // open the master.txt with
    FILE *fp = fopen("./master.txt", "rt");
    // fgets for lineNum times so that we can read the (lineNum)th lines
    while (fgets(buff, 60, fp) != NULL)
    {
        strcpy(input, buff);
        strcpy(correctAccount, str_slice(input, 20, 16));
        printf("Input Account:%s\n", account);
        printf("Correct Account:%s\n", correctAccount);
        // Cut the account number and check
        if (strcmp(account, correctAccount) == 0)
        {
            printf("Account Found!\n");
            // fclose(fp);
            strcpy(correctPassword, str_slice(buff, 36, 6));
            printf("Correct Password:%s\n", correctPassword);
            if (strcmp(password, correctPassword) == 0)
            {
                printf("Account and Password Correct\n");
                valid = 1;
            }
            else
            {
                printf("Password Incorrect!\n");
            }
        }
        printf("end single while loop\n\n");
    }
    return valid;
}

//////////////////////////////////////////////////////////////////////////////////////////////
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

//////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
    printf("Result:%d", CheckAccountPassword("1234567890123456", "123457")); // password incorrect
    return 0;
}