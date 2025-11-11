#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
    int c;
    FILE *fp1, *fp2;
    int option;

    if (argc != 4) {
        fprintf(stderr, "Usage: %s <option> <source> <destination>\n", argv[0]);
        return 1;
    }

    option = atoi(argv[1]);

    fp1 = fopen(argv[2], "r");
    if (fp1 == NULL) {
        fprintf(stderr, "File %s open error\n", argv[2]);
        return 2;
    }

    fp2 = fopen(argv[3], "w");
    if (fp2 == NULL) {
        fprintf(stderr, "File %s create error\n", argv[3]);
        fclose(fp1);
        return 3;
    }

    while ((c = fgetc(fp1)) != EOF) {
        if (option == 1)
            c = tolower((unsigned char)c);
        else if (option == 2)
            c = toupper((unsigned char)c);
        fputc(c, fp2);
    }

    fclose(fp1);
    fclose(fp2);

    return 0;
}

