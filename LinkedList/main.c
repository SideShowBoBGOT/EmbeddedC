#include <stdio.h>
#include <string.h>

#include "list.h"

int main() {
    list l = list__new();


    list__push_front(&l,NULL, 0);

    printf("%lu", strlen("1"));
    return 0;
}
