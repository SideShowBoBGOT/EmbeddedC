#ifndef LINKEDLIST_SBOOK_H
#define LINKEDLIST_SBOOK_H

struct SBook {
    char* Title;
    double Price;
    int NumberOfPages;
    enum {
        Ukrainian,
        English,
    } Language;
    double Weight;
    int YearOfPublishing;
};

#endif //LINKEDLIST_SBOOK_H
