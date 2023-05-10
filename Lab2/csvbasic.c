#include <stdio.h>
#include <stdlib.h>
int main()
{
FILE *fptr;
char name1[20], name2[20];
int ID1, ID2;
fptr = fopen("test.csv", "w");
scanf("%s %d", name1, &ID1);
scanf("%s %d", name2, &ID2);
// Recall from CP that %[^,] means read until comma
fprintf(fptr,"%s,%d,\n", name1, ID1);
fprintf(fptr,"%s,%d", name2, ID2);
fclose(fptr);
}