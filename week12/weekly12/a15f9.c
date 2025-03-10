#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct book {
    char title[40];
    char author[35];
    float price;
    int published_day;
    char discount[2];
    float final_price;
};

int parse_book(struct book books[150], char filename[10]) {
    FILE *fp;

    fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("File Not Found\n");
        exit(0);
    }

    int index = 0;
    char line[100];


    while (fgets(line, sizeof(line), fp)) {
        if (line != NULL) {
            char* found =  strtok(line, ",");
            strcpy(books[index].title, found);

            found =  strtok(NULL, ",");
            strcpy(books[index].author, found);

            found =  strtok(NULL, ",");
            books[index].price = (float) atof(found);

            found =  strtok(NULL, ", ");
            books[index].published_day = atoi(found);

            found =  strtok(NULL, "\n");
            strcpy(books[index].discount, found);
            index++;
        }

    }
    return index;
}

void compute_price(int len,struct book books[150]) {
    for (int i = 0; i < len; i++) {

        if (books[i].published_day <= 2018 && books[i].price >= 20.0) {
            books[i].final_price = books[i].price * 60.0 / 100.0;
        }
        else if (books[i].published_day <= 2018) {
            books[i].final_price = books[i].price * 70.0 / 100.0;
        }
        else if (books[i].published_day >= 2018 && books[i].price >= 15.0) {
            books[i].final_price = books[i].price * 80.0 / 100.0;
        }
        else {
            books[i].final_price = books[i].price * 90.0 / 100.0;
        }
    }

}

void print_books(int length, struct book books[150], int disount) {
    printf("---- BOOKS ----\n");
    int idx = 0;
    for (int j = 0; j < length; j++) {
        // printf("%c\n", books[j].discount+1);
        if (books[j].discount[1] == 'Y' && disount) {
            printf("%s, %s (%d), %.2f final price: %.2f\n", books[j].author, books[j].title, books[j].published_day, books[j].price, books[j].final_price);
            idx++;
        }
        else if (books[j].discount[1] == 'N'&& !disount) {
            printf("%s, %s (%d), %.2f final price: %.2f\n", books[j].author, books[j].title, books[j].published_day, books[j].price, books[j].price);
            idx++;
        }
    }

    if (disount) {
        printf("Books (offer Y) %d\n\n", idx);
    }
    else {
        printf("Books (offer N) %d\n\n", idx);
    }
}

int main(void) {
    struct book books[150];

    int length = parse_book(books, "books.txt");

    compute_price(length, books);
    print_books(length, books, 1);
    print_books(length, books, 0);
    return 0;
}
