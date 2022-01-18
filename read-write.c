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

// Return the string starting with (slice_to)th character, and ending from (slice_from)th character
char *
str_slice(char str[], int slice_from, int slice_to)
{
    // if a string is empty, returns nothing
    if (str[0] == '\0')
        return NULL;

    char *buffer;
    size_t str_len, buffer_len;

    // for negative indexes "slice_from" must be less "slice_to"
    if (slice_to < 0 && slice_from < slice_to)
    {
        str_len = strlen(str);

        // if "slice_to" goes beyond permissible limits
        if (abs(slice_to) > str_len - 1)
            return NULL;

        // if "slice_from" goes beyond permissible limits
        if (abs(slice_from) > str_len)
            slice_from = (-1) * str_len;

        buffer_len = slice_to - slice_from;
        str += (str_len + slice_from);

        // for positive indexes "slice_from" must be more "slice_to"
    }
    else if (slice_from >= 0 && slice_to > slice_from)
    {
        str_len = strlen(str);

        // if "slice_from" goes beyond permissible limits
        if (slice_from > str_len - 1)
            return NULL;

        buffer_len = slice_to - slice_from;
        str += slice_from;

        // otherwise, returns NULL
    }
    else
        return NULL;

    buffer = calloc(buffer_len, sizeof(char));
    strncpy(buffer, str, buffer_len);
    return buffer;
}

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
    printf("%s", str_slice(input, 20, 37));
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
    ReadAccountNumber(2);
    return 0;
}