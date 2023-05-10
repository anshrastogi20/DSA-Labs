#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printelements(int arr[],int len){
    for (int i=0;i<len;i++){
        printf("%d\n",arr[i]);
    }
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
    for (int j=1;j<n;j++){
        int k=j-1;
        int temp=array[j];
        while(k>=0 && temp<array[k]){
            array[k+1] = array[k];
            k--;
        }
        array[k+1] = temp;
    }
    printelements(array,n);
    return 0;
}