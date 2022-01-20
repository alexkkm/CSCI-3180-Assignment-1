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

// comparing each character of the two strings
int stringCompare(char *a, char *b)
{
    int ctr = 0;
    for (int i = 0; i < strlen(a); ++i)
    {
        if (a[i] != b[i])

        {
            ctr = 1;
            break;
            printf("At postion %d\n", i);
        }
    }
    return ctr;
}

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
    int valid = 0;
    char buff[59];

    char correctAccount[16];
    char correctPassword[6];

    // open the master.txt with
    FILE *fp = fopen("./master.txt", "rt");
    // fgets for lineNum times so that we can read the (lineNum)th lines
    while (fgets(buff, 59, fp) != NULL)
    {
        printf("buff before slice:%s\n", buff);
        strcpy(correctAccount, str_slice(buff, 20, 16));
        strcpy(correctPassword, str_slice(buff, 36, 6));
        printf("input password:%s\n", password);
        printf("Correct Password:%s\n", correctPassword);
        account[strlen(account - 1)] = '\0';
        correctAccount[strlen(correctAccount - 1)] = '\0';
        printf("input account:%s\n", account);
        printf("Correct Account:%s\n", correctAccount);
        //  Cut the account number and check
        if (strcmp(account, correctAccount) == 0)
        {
            printf("Account Found!\n");

            if (strcmp(password, correctPassword) == 0)
            {
                printf("Account and Password Correct\n");
                valid = 1;
            }
        }

        printf("end single while loop\n");
    }
    return valid;
}

int main()
{
    printf("Result:%d", CheckAccountPassword("1234567890123456", "123456"));
    return 0;
}
