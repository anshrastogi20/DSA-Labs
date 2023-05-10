#include <stdio.h>
#include<stdlib.h>
#include<string.h>

// Function to take input an array A and return an array B after performing counting sort on it with array C
char* counting_sort(char* A, char* B, int k, int n) 
{
    // Initialize array C with all 0s
    int C[k];
    for (int i = 0; i < k; i++) 
    {
        C[i] = 0;
    }

    // Count the number of times each element occurs in A and store it in C
    for (int j = 0; j < n; j++) 
    {
        C[(int)(A[j]-'a')]++;
    }
    // Place the elements of A in B in the correct position
    for (int i = 1; i < k; i++) 
    {
        C[i] = C[i] + C[i - 1];
    }
    for (int j = n - 1; j >= 0; j--) 
    {
        B[C[(int)(A[j]-'a')] - 1] = A[j];
        C[(int)(A[j]-'a')]--;
    }
    return B;
}

// Driver code to test the above function
int main() 
{
    char *s = (char*)malloc(sizeof(char*));
    printf("Enter the string: ");
    scanf("%s",s);
    int n = 0;
    for(int i=0;s[i]!='\0';i++){
        n++;
    }
    char k = s[0];
    for (int i = 1; i < n; i++) 
    {
        if ((int)s[i] > (int)k) 
        {
            k = s[i];
        }
    }
    char *news = (char*)malloc(sizeof(char*));
    news = counting_sort(s, news, (int)(k - 'a')+1, n);
    printf("The sorted string is: ");
    printf("%s",news);
    return 0;
}
