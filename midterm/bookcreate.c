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
    int n;

    scanf("%d", &n);

    fp = fopen("db.dat", "wb");
    if (!fp) {
        printf("File open error\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        scanf("%d %s %s %d %d %d",
            &b.id, b.bookname, b.author,
            &b.year, &b.numOfBorrow, &b.borrow
        );
        fwrite(&b, sizeof(Book), 1, fp);
    }

    fclose(fp);
    return 0;
}

