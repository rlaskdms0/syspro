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

int cmpYear(const void *a, const void *b) {
    Book *x = (Book*)a;
    Book *y = (Book*)b;
    return y->year - x->year; 
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

    qsort(arr, n, sizeof(Book), cmpYear);

    fp = fopen("db.dat", "wb");
    for (int i = 0; i < n; i++)
        fwrite(&arr[i], sizeof(Book), 1, fp);

    fclose(fp);

    return 0;
}

