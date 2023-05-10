#include <stdio.h>

void counting_sort(int array[],int n,int exp){
    int output[n];
    int C[10];
    for (int i = 0; i < 10; i++) 
    {
        C[i] = 0;
    }
    // Count the number of times each element occurs in A and store it in C
    for (int j = 0; j < n; j++) 
    {
        C[(array[j]/(exp))%10]++;
    }
    
    // Place the elements of A in B in the correct position
    for (int i = 1; i < 10; i++) 
    {
        C[i] = C[i] + C[i - 1];
    }
    for (int j = n - 1; j >= 0; j--) 
    {
        output[C[(array[j]/(exp))%10] - 1] = array[j];
        C[(array[j]/(exp))%10]--;
    }
    for (int i = 0; i < n; i++)
        array[i] = output[i];
}
int* radixsort_straight(int array[],int n,int max){
    for(int exp=1;max/exp>0;exp *= 10){
        counting_sort(array,n,exp);
    }
    return array;
}

// Driver code to test the above function
int main() 
{
    int n = 8;
    int array[8] = {3,457,6572,83999,46,720,355,9};
    int max = array[0];
    for (int i = 1; i < n; i++) 
    {
        if (array[i] > max) 
        {
            max = array[i];
        }
    }
    int* out = radixsort_straight(array,n,max);
    printf("The sorted array is: ");
    for (int i = 0; i < n; i++) 
    {
        printf("%d ", out[i]);
    }
    printf("\n");
    return 0;
    // int n;
    // printf("Enter the number of elements in the array: ");
    // scanf("%d", &n);
    // printf("Enter the elements of the array: ");
    // for (int i = 0; i < n; i++) 
    // {
    //     scanf("%d", &array[i]);
    // }
}