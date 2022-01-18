#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void readfile()
{
}

// Write Result into new document
void writefile()
{
    FILE *fw = fopen("result.txt", "w+"); // w+: create a document, and if the document exist, delete the existing document
    fprintf(fw, "Wite sth");
}

int main()
{
    printf("Testing:\n");

    // READ File
    char buff[10000] = "null";
    char input[58];
    FILE *fp = fopen("./master.txt", "rt");

    int id = 0;

    while ((fgets(buff, 10000, fp) != NULL) && (id < 8))
    {
        strcpy(input, buff);
        id++;
    }

    printf("%s", input);
    printf("%d", id);

    return 0;
}