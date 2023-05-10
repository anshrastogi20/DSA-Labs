#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h> 
#include "intMerge.c"

struct timeval t1, t2;
double time_taken;


void printelements(struct person arr[],int len){
    for (int j=0;j<len;j++){
        printf("%d %s %d %d %d\n",arr[j].id,arr[j].name,arr[j].age,arr[j].weight,arr[j].height);
    }
}
void mergeSort(struct person A[], int st, int en)
{
    if (en - st < 1)
        return;
    int mid = (st + en) / 2;   // mid is the floor of (st+en)/2
    mergeSort(A, st, mid);     // sort the first half
    mergeSort(A, mid + 1, en); // sort the second half
    merge(A, st, mid, en);     // merge the two halves
}


int main()
{
    FILE* fp = fopen("dat1000.csv", "r");
    long n = 1000;
    struct person *array =  (struct person *)malloc(n * sizeof(struct person));
    for (int i=0;i<n;i++){
        array[i].name = (char *)malloc(40 * sizeof(char));
        fscanf(fp, "%d,%[^,],%d,%d,%d",&array[i].id,array[i].name,&array[i].age,&array[i].weight,&array[i].height);
    }
    gettimeofday(&t1, NULL);
    mergeSort(array,0,n-1);
    gettimeofday(&t2, NULL);
    printelements(array,n);
    time_taken = (t2.tv_sec - t1.tv_sec) * 1e6;
    time_taken = (time_taken + (t2.tv_usec - t1.tv_usec)) * 1e-6;
    printf("The tasks took %f seconds to execute\n", time_taken);
    fclose(fp);
    return 0;
}
