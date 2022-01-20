#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _accountInfo
{
    char accountName[21];
    char accountNumber[17];
    char accountPassword[7];
    char accountBalance[17];
} AccountInfo;

AccountInfo getAccountInformationFromLine(char *line)
{
    AccountInfo newAccount;

    // Name
    strncpy(newAccount.accountName, line, 20);
    newAccount.accountName[20] = '\0';
    line += 20;

    // Account Number
    char rawAccountNumber[16];
    // strncpy(rawAccountNumber, line, 15);
    //  newAccount.accountNumber = atoi(rawAccountNumber);
    strncpy(newAccount.accountNumber, line, 16);
    newAccount.accountNumber[16] = '\0';
    line += 16;

    // Password
    char rawPassword[6];
    // strncpy(rawPassword, line, 6);
    //  newAccount.accountPassword = atoi(rawAccountNumber);
    strncpy(newAccount.accountPassword, line, 6);
    newAccount.accountPassword[6] = '\0';
    line += 6;

    // Balance
    strncpy(newAccount.accountBalance, line, 16);
    newAccount.accountBalance[16] = '\0';
    line += 16;

    return newAccount;
}

int checkAccountPassword(AccountInfo account, char *number, char *password)
{
    if (strncmp(account.accountNumber, number, sizeof(&number)))
    {
        if (strncmp(account.accountPassword, password, sizeof(&password)))
        {
            return 0;
        }
        else
            return 1;
    }
    else
    {
        return 1;
    }
}

int main()
{
    char lineBuffer[59];

    FILE *fp = fopen("master.txt", "r");
    if (NULL == fp)
    {
        printf("Fail to open the file\n");
    }
    while (fgets(lineBuffer, sizeof(lineBuffer), fp) != NULL)
    {
        lineBuffer[strlen(lineBuffer) - 1] = '\0';
        AccountInfo account = getAccountInformationFromLine(lineBuffer);
        printf("Name:%s\n", account.accountName);
        printf("Number:%s\n", account.accountNumber);
        printf("Password:%s\n", account.accountPassword);
        printf("Balance:%s\n", account.accountBalance);
    }
    fclose(fp);

    return 0;
}