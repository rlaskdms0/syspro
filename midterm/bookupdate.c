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
    FILE *fp = fopen("db.dat", "rb+");
    if (!fp) {
        printf("File open error\n");
        return 1;
    }

    int cmd, bookID;
    scanf("%d %d", &cmd, &bookID);

    Book b;
    long pos;
    int found = 0;

    while (1) {
        pos = ftell(fp);
        if (fread(&b, sizeof(Book), 1, fp) != 1) break;

        if (b.id == bookID) {
            found = 1;

            if (cmd == 0) {  
                // borrow
                printf("0 bookId: borrow book, 1 bookId: return book ) 0 %d\n", bookID);
                if (b.borrow == 1) {
                    printf("You cannot borrow %s since it has been booked.\n", b.bookname);
                } else {
                    b.borrow = 1;
                    b.numOfBorrow++;
                    printf("You've got %s.\n", b.bookname);
                }
            }
            else if (cmd == 1) { 
                // return
                printf("0 bookId: borrow book, 1 bookId: return book ) 1 %d\n", bookID);
                if (b.borrow == 0) {
                    printf("You cannot return %s since it's not borrowed.\n", b.bookname);
                } else {
                    b.borrow = 0;
                    printf("You've returned %s.\n", b.bookname);
                }
            }

            fseek(fp, pos, SEEK_SET);
            fwrite(&b, sizeof(Book), 1, fp);
            break;
        }
    }

    fclose(fp);
    return 0;
}

