#include<stdio.h>
main() {
    char buffer[1024];

    printf("buffer=%p\n", buffer);
    gets(buffer);           /* insecure! */
    return 0;
}