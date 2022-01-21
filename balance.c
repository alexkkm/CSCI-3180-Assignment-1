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

        // Cut the account number and check
        if (strcmp(account, correctAccount) == 0)
        {
            strcpy(correctPassword, str_slice(buff, 36, 6));
            if (strcmp(password, correctPassword) == 0)
            {
                valid = 1;
            }
        }
    }
    fclose(fp);
    return valid;
}

int GetAccountBalance(char *account)
{
    char buff[60] = "null";
    char input[59];
    char targetAccount[17];
    int balance;
    char balanceStr[17];
    char balanceValue[16];

    // open the master.txt with
    FILE *fp = fopen("./master.txt", "rt");
    // fgets for lineNum times so that we can read the (lineNum)th lines
    while (fgets(buff, 60, fp) != NULL)
    {

        strcpy(input, buff);
        printf("input:%s\n", input);
        strcpy(targetAccount, str_slice(input, 20, 16));

        // find the target account
        if (strcmp(account, targetAccount) == 0)
        {
            printf("Account Found!\n");
            strcpy(balanceStr, str_slice(input, 42, 16));
            printf("balance String:%s\n", balanceStr);
            // copy the string og value of balanceStr string into balanceValue string
            strcpy(balanceValue, str_slice(balanceStr, 1, 15));
            printf("balance vale String:%s\n", balanceValue); // CORRECT!!!!!!!!!!!!!!!!!!!

            // if balance string[0] is "+", the balance should be positive
            if (balanceStr[0] = '+')
            {
                balance = atoi(balanceValue);
            }
            else if (balanceStr[0] = '-') // balance is negative
            {
                balance = atoi(balanceValue) * (-1);
            }
        }
    }

    return balance;
    fclose(fp);
}

int main()
{
    printf("Result:%d", GetAccountBalance("1234567890123456"));
    return 0;
}