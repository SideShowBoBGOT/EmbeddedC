#ifndef LINKEDLIST_BOOK_H
#define LINKEDLIST_BOOK_H

typedef enum {
    UKRAINIAN,
    ENGLISH,
    SPANISH,
    GERMAN,
    FRENCH,
    JAPANESE,
    KOREAN
} language;

const char* language__serialize(language lang);

typedef struct {
    char* title;
    double price;
    int pages_num;
    language lang;
    double weight;
    int pub_year;
} book;

//book book__create(const char* title, double price, language lang, double weight, int pub_year);
book* book__new(const char* title, double price, language lang, double weight, int pub_year);
void* book__cpy(const void* self);
void book__dtor(void* self);
void book__print(const book* self);

#endif //LINKEDLIST_BOOK_H
