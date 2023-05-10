#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "intMerge.c"

void printelements(int arr[],int len){
    for (int i=0;i<len;i++){
        printf("%d\n",arr[i]);
    }
}
void mergeSort(int A[], int st, int en)
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
    int n;
    printf("Enter number of elements : ");
    scanf("%d",&n);
    int array[n];
    for (int i=0;i<n;i++){
        printf("Enter element : ");
        scanf("%d",&array[i]);
    }
    mergeSort(array,0,n-1);
    printelements(array,n);
    return 0;
}