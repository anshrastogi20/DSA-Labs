#include <stdio.h> 
#include <stdlib.h> 
#include <sys/time.h>
// Recursive binary search
void insertionSortRecursive(int *arr, int n) {
    if (n <= 1) 
        return; 
    insertionSortRecursive(arr, n-1);
    int last = arr[n-1];
    int j = n-2;
    while (j >= 0 && arr[j] > last) {
        arr[j+1] = arr[j];
        j--; 
    }
    arr[j+1] = last;
}
void insertionSortIterative(int *arr, int n) {
    for (int i = 1; i < n; i++) {
        int last = arr[i];
        int j = i-1;
        while (j >= 0 && arr[j] > last) {
            arr[j+1] = arr[j];
            j--; 
        }
        arr[j+1] = last;
    }

}
void printelements(int arr[],int len){
    for (int i=0;i<len;i++){
        printf("%d\n",arr[i]);
    }
}
// Driver code
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
    struct timeval t1, t2;
    double time_taken; 
    gettimeofday(&t1, NULL); 
    insertionSortIterative(array,n);
    // printelements(array,n);
    gettimeofday(&t2, NULL);
    time_taken = (t2.tv_sec - t1.tv_sec) * 1e6;
    time_taken = (time_taken + (t2.tv_usec - t1.tv_usec)) * 1e-6;
    printf("Iterative took %f seconds to execute\n", time_taken);
    gettimeofday(&t1, NULL); 
    insertionSortRecursive(array,n);
    // printelements(array,n);
    gettimeofday(&t2, NULL);
    time_taken = (t2.tv_sec - t1.tv_sec) * 1e6;
    time_taken = (time_taken + (t2.tv_usec - t1.tv_usec)) * 1e-6;
    printf("Recursive took %f seconds to execute\n", time_taken); 
    return 0;
}