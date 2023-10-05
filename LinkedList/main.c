#include "containers/include/list.h"
#include "book.h"

#include <stdlib.h>
#include <stdio.h>

#define TOTAL_BOOKS 7

void print_books(const list* l);

int main() {
    book books[TOTAL_BOOKS] = {
        book__create("Philosopher's stone", 1, UKRAINIAN, 1, 1997),
        book__create("Chamber of Secrets", 2, ENGLISH, 2, 1998),
        book__create("Prisoner of Azkaban", 3, GERMAN, 3, 1999),
        book__create("Goblet of fire", 4, SPANISH, 4, 2000),
        book__create("Order of the Phoenix", 5, FRENCH, 5, 2003),
        book__create("Half-Blood Prince", 6, JAPANESE, 6, 2005),
        book__create("Deathly Hallows", 7, KOREAN, 7, 2007),
    };

    list* l = list__new();
    for(unsigned i = 0; i < TOTAL_BOOKS; ++i) {
        list__push_back(l, &books[i], sizeof(book));
    }

    printf("List:\n");

    print_books(l);

    list__pop_back(l);
    list__pop_front(l);

    printf("List modified:\n");

    print_books(l);

    list__free(l);
    return 0;
}

void print_books(const list* l) {
    for(unsigned i = 0; i < l->length; ++i) {
        const book* b;
        int err = 0;
        if((err = list__at(l, i, (void**)&b)) == -1) {
            exit(err);
        }
        book__print(b);
    }
}
