#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    char bookname[20];
    char author[20];
    int year;
    int numOfBorrow;
    int borrow;
} Book;

int main() {
    FILE *fp;
    Book b;

    fp = fopen("db.dat", "rb");
    if (!fp) {
        printf("File open error\n");
        return 1;
    }

    printf("0: list of all books, 1: list of available books ) ");
    int mode;
    scanf("%d", &mode);

    printf("id  bookname   author   year   numOfBorrow  borrow\n");

    while (fread(&b, sizeof(Book), 1, fp) == 1) {
        if (mode == 1 && b.borrow == 1) continue;

        printf("%d  %s  %s  %d  %d  %d\n",
            b.id, b.bookname, b.author, b.year,
            b.numOfBorrow, b.borrow);
    }

    fclose(fp);
    return 0;
}

