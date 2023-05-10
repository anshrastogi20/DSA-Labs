#include <stdio.h>
#include <stdlib.h>
int main(int argc,char* argv[])   // command line arguments
{
    FILE *fptr;
    int ID1, ID2;
    fptr = fopen(argv[1], "r");
    fscanf(fptr,"%d",&ID1);
    fscanf(fptr,"%d",&ID2);
    // Recall from CP that %[^,] means read until comma
    printf("%d\n",ID1);
    printf("%d\n",ID2);
    fclose(fptr);
}