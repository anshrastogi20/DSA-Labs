#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fptr;
    fptr = fopen(__FILE__, "r");
    if (fptr == NULL){
        printf("Error opening file");
        exit(1);
    }
    char ch;
    ch = fgetc(fptr);
    printf("%c", ch);
    while(ch!=EOF){
        ch = fgetc(fptr);
        printf("%c", ch);
    }

    fclose(fptr);
    return 0;
}