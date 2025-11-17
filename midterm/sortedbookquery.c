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

int cmp(const void *a, const void *b) {
    Book *x = (Book*)a;
    Book *y = (Book*)b;
    return y->numOfBorrow - x->numOfBorrow;
}

int main() {
    FILE *fp = fopen("db.dat", "rb");
    if (!fp) {
        printf("File open error\n");
        return 1;
    }

    Book arr[100];
    int n = 0;

    while (fread(&arr[n], sizeof(Book), 1, fp) == 1)
        n++;
    fclose(fp);

    int mode;
    printf("0: list of all books, 1: list of available books ) ");
    scanf("%d", &mode);

    qsort(arr, n, sizeof(Book), cmp);

    printf("id  bookname  author  year  numOfBorrow  borrow\n");

    for (int i = 0; i < n; i++) {
        if (mode == 1 && arr[i].borrow == 1)
            continue;

        printf("%d  %s  %s  %d  %d  %d\n",
            arr[i].id, arr[i].bookname, arr[i].author,
            arr[i].year, arr[i].numOfBorrow, arr[i].borrow);
    }

    return 0;
}

