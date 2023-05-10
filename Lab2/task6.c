#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fptr1;
    fptr1 = fopen("test1.txt", "r");
    FILE *fptr2;
    fptr2 = fopen("test2.txt", "w");
    if (fptr1 == NULL){
        printf("Error opening file1");
        exit(1);
    }
    if (fptr2 == NULL){
        printf("Error opening file2");
        exit(1);
    }
    char ch;
    ch = fgetc(fptr1);
    // fprintf(fptr2,"%c", ch);
    while(ch!=EOF){
        
        fprintf(fptr2,"%c", ch);
        ch = fgetc(fptr1);
    }
    fclose(fopen("test1.txt", "w"));
    fclose(fptr2);

    return 0;
}