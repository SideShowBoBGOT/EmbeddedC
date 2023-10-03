#include <stdio.h>

#define ARRAY_SIZE 255

int main() {

    printf("Enter characters: ");
    char buf[ARRAY_SIZE] = {0};
    fgets(buf, sizeof(buf), stdin);

    for(unsigned i = 0; buf[i] != '\0'; ++i) {
        if(buf[i] >= 32) {
            printf("%c\t%d\n", buf[i], buf[i]);
        }
    }

    return 0;
}
