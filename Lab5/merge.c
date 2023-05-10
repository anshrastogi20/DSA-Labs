#include <stdio.h> 
#include <stdlib.h> 
#include <sys/time.h>
// Recursive binary search
void mergeAux (int L1[], int s1, int e1, int L2[], int s2, int e2, int L3[], int s3, int e3)
{
    int i,j,k;
    i=s1; j=s2; k=s3;
    while (i <= e1 && j <= e2) 
    {
        if (L1[i]< L2[j])
            L3[k++] = L1[i++];
    else
            L3[k++] = L2[j++];
    }
    while (i <= e1)
        L3[k++] = L1[i++];
    while (j <= e2)
        L3[k++] = L2[j++];
}
void merge(int A[], int s, int mid, int e)
{
    int *C = (int *)malloc(sizeof(int) * (e - s + 1));
    mergeAux(A, s, mid, A, mid + 1, e, C, 0, e-s);
    for(int i = 0; i < e - s + 1; i++)
    {
        A[s + i] = C[i];
    }
    free(C); 
}
void mergeSortRecursive(int A[], int st, int en)
{
    if (en - st < 1)
        return;
    int mid = (st + en) / 2;   // mid is the floor of (st+en)/2
    mergeSortRecursive(A, st, mid);     // sort the first half
    mergeSortRecursive(A, mid + 1, en); // sort the second half
    merge(A, st, mid, en);     // merge the two halves
}

void mergeSortIterative(int *arr, int n) {
   int curr_size;  // For current size of subarrays to be merged
                   // curr_size varies from 1 to n/2
   int left_start; // For picking starting index of left subarray
                   // to be merged
   // Merge subarrays in bottom up manner.  First merge subarrays of
   // size 1 to create sorted subarrays of size 2, then merge subarrays
   // of size 2 to create sorted subarrays of size 4, and so on.
   for (curr_size=1; curr_size<n; curr_size = 2*curr_size)
   {
       // Pick starting point of different subarrays of current size
       for (left_start=0; left_start<n-1; left_start += 2*curr_size)
       {
           // Find ending point of left subarray. mid+1 is starting 
           // point of right
        //    int mid = min(left_start + curr_size - 1, n-1);
           int mid = (left_start + curr_size - 1)<(n-1)?(left_start + curr_size - 1):(n-1);
        //    int right_end = min(left_start + 2*curr_size - 1, n-1);
           int right_end = (left_start + 2*curr_size - 1)<(n-1)?(left_start + 2*curr_size - 1):(n-1);
  
           // Merge Subarrays arr[left_start...mid] & arr[mid+1...right_end]
           merge(arr, left_start, mid, right_end);
       }
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
    mergeSortIterative(array,n);
    printelements(array,n);
    gettimeofday(&t2, NULL);
    time_taken = (t2.tv_sec - t1.tv_sec) * 1e6;
    time_taken = (time_taken + (t2.tv_usec - t1.tv_usec)) * 1e-6;
    printf("Iterative took %f seconds to execute\n", time_taken);
    gettimeofday(&t1, NULL); 
    mergeSortRecursive(array,0,n-1);
    printelements(array,n);
    gettimeofday(&t2, NULL);
    time_taken = (t2.tv_sec - t1.tv_sec) * 1e6;
    time_taken = (time_taken + (t2.tv_usec - t1.tv_usec)) * 1e-6;
    printf("Recursive took %f seconds to execute\n", time_taken); 
    return 0;
}