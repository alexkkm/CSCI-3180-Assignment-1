#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Return 0 if account password pair not found, return 1 if found
int CheckAccountPassword(char *account, char *password)
{
    // READ File
    char buff[10000] = "null";
    char input[58];
    int valid = 0;
    char *correctAccount;
    // open the master.txt with
    FILE *fp = fopen("./master.txt", "rt");
    // fgets for lineNum times so that we can read the (lineNum)th lines
    while (fgets(buff, 60, fp) != NULL)
    {
        strcpy(input, buff);
        // Cut the account number and check
        if (strcmp(account, strcpy(correctAccount, str_slice(input, 20, 16))))
        {
            printf("Corret");
        }
        // cut the account password and check
    }

    return valid;
}

int main()
{
    int atm_num = 0;
    FILE *fp;
    char buff[10000];
    int account;
    int password;

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
            printf("=> INVALID INPUT\n");
        }
    }
    /* atm_num now will either be 1(711) or 2(713)*/

    // Check Account & Password
    int valid = 0;
    while (valid == 0)
    {
        printf("=> ACCOUNT\n");
        scanf("%d", &account);
        printf("=> PASSWORD\n");
        scanf("%d", &password);
    }

    // THE END
    return 0;
}