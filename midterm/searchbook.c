#include <stdio.h>
#include <string.h>

typedef struct {
    int id;
    char bookname[20];
    char author[20];
    int year;
    int numOfBorrow;
    int borrow;
} Book;

int main() {
    FILE *fp = fopen("db.dat", "rb");
    if (!fp) {
        printf("File open error\n");
        return 1;
    }

    char key[20];
    printf("input name of book ) ");
    scanf("%s", key);

    Book b;
    int found = 0;

    while (fread(&b, sizeof(Book), 1, fp) == 1) {
        if (strcmp(b.bookname, key) == 0) {
            if (!found)
                printf("id  bookname  author  year  numOfBorrow  borrow\n");

            printf("%d  %s  %s  %d  %d  %d\n",
                b.id, b.bookname, b.author,
                b.year, b.numOfBorrow, b.borrow);
            found = 1;
        }
    }

    if (!found)
        printf("not found book name : '%s'\n", key);

    fclose(fp);
    return 0;
}

