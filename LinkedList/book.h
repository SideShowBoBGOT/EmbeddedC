#ifndef LINKEDLIST_BOOK_H
#define LINKEDLIST_BOOK_H

typedef struct book_struct {
    char* title;
    double price;
    int pages_num;
    enum {
        UKRAINIAN,
        ENGLISH,
    } language;
    double weight;
    int pub_year;
} book;

#endif //LINKEDLIST_BOOK_H
