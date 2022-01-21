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
    char buff[10000] = "null";
    char input[58];
    // char input2[58];
    int valid = 0;
    char correctAccount[16];
    char correctPassword[6];

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
        }
        printf("end single while loop\n\n");
    }
    return valid;
}

int main()
{
    int atm_num = 0;
    FILE *fp;

    char account[16] = "a";
    char password[6] = "b";

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
        printf("account before scan:%s\n", account);
        printf("password before scan:%s\n", password);
        printf("=> ACCOUNT\n");
        scanf("%s", account);
        printf("account after scan:%s\n", account);
        printf("=> PASSWORD\n");
        scanf("%s", password);
        printf("password after scan:%s\n", password);

        printf("Validation:%d\n", CheckAccountPassword(account, password));
    }

    // THE END
    return 0;
}