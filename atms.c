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

int GetAccountBalance(account)
{
    char buff[60] = "";
    char input[59];
    int balance;
    char balanceStr[17];

    // open the master.txt with
    FILE *fp = fopen("./master.txt", "rt");
    // fgets for lineNum times so that we can read the (lineNum)th lines
    while (fgets(buff, 60, fp) != NULL)
    {
        strcpy(balanceStr, str_slice(input, 42, 16));
        printf("balance String:%s", balanceStr);
    }

    return balance;
    fclose(fp);
}

int main()
{
    int atm_num = 0;
    FILE *fp;

    char account[17] = "";
    char password[7] = "";

    // Opening
    printf("###  Gringotts Wizarding Bank ###\n");
    printf("###           Welcome         ###\n");
    printf("###                           ###\n");

    // Choosing ATM
    while (atm_num != 1 || atm_num != 2)
    {
        printf("=> PLEASE CHOOSE THE ATM\n");
        printf("=> PRESS 1 FOR ATM 711\n");
        printf("=> PRESS 2 FOR ATM 713\n");
        scanf("%d", &atm_num);
        if (atm_num == 1 || atm_num == 2)
        {
            break;
        }
        else
        {
            continue;

            printf("=> INVALID INPUT\n");
        }
    }
    /* atm_num now will either be 1(711) or 2(713)*/

    // Check Account & Password
    int validAccountPassword = 0;
    while (validAccountPassword == 0)
    {
        printf("=> ACCOUNT\n");
        scanf("%s", account);

        printf("=> PASSWORD\n");
        scanf(" %s", password);

        if (CheckAccountPassword(account, password))
        {
            validAccountPassword = 1;
        }
        else
        {
            printf("=> INCORRECT ACCOUNT/PASSWORD\n");
        }
    }

    // Check Account Balance Postive
    int positive_balance = 0;
    if (GetAccountBalance(account) < 0)
    {
        printf("=> NEGATIVE REMAINS TRANSACTION ABORT");
        exit(1);
    }

    // THE END
    return 0;
}