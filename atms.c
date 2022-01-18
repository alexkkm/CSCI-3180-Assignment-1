#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
    int atm_num = 0;
    FILE *fp;
    char buff[10000];
    int valid = 0;
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

    /*
        // Account & Password
        while (valid == 0)
        {
            printf("=> ACCOUNT\n");
            scanf("%d", &account);
            printf("=> PASSWORD\n");
            scanf("%d", &password);

            // READ File
            fp = fopen("master.txt", "R");
            fscanf(fp, "%s", buff);
            printf("%s", buff);
        }
    */
    // THE END
    return 0;
}