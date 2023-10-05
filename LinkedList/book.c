#define _GNU_SOURCE

#include "book.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

const char* language__serialize(language lang) {
    switch(lang) {
        case UKRAINIAN: return "UKRAINIAN";
        case ENGLISH: return "ENGLISH";
        case SPANISH: return "SPANISH";
        case GERMAN: return "GERMAN";
        case FRENCH: return "FRENCH";
        case JAPANESE: return "JAPANESE";
        case KOREAN: return "KOREAN";
        default: return "";
    }
}

book book__create(const char* title, double price, language lang, double weight, int pub_year) {
    book new_book = {.title=strdup(title), .price=price, .lang=lang, .weight=weight, .pub_year=pub_year};
    return new_book;
}

book* book__new(char* title, double price, language lang, double weight, int pub_year) {
    book* b = (book*)malloc(sizeof(book));
    b->title = title;
    b->price = price;
    b->lang = lang;
    b->weight = weight;
    b->pub_year = pub_year;
    return b;
}

void* book__cpy(const void* b) {
    book* bb = (book*)b;
    book* new_book = book__new(strdup(bb->title), bb->price, bb->lang, bb->weight, bb->pub_year);
    return new_book;
}

void book__dtor(void* b) {
    book* bb = (book*)b;
    free(bb->title);
}

void book__print(const book* self) {
    printf("title: %s, price: %lf, lang: %s, weight: %lf, pub_year: %u\n",
        self->title, self->price, language__serialize(self->lang), self->weight, self->pub_year);
}


