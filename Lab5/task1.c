#include <stdio.h> 
#include <stdlib.h> 
#include <sys/time.h>
// Recursive binary search
int fibonacciRecursive(int n) {
    if(n==0)
        return 0;
    else if(n==1)
        return 1;
    else{
        return (fibonacciRecursive(n-1)+fibonacciRecursive(n-2));
    }
}
int fibonacciIterative(int n) {
    int a=0;
    int b=1;
    int c=0;
    if(n==0)
        return a;
    else if(n==1)
        return b;
    else{
        for(int i=1;i<n;i++){
            c = a + b;
            a = b;
            b = c;
        }
        return c;
    }
}
// Driver code
int main(void)
{
    int n = 45;
    struct timeval t1, t2;
    double time_taken; 
    gettimeofday(&t1, NULL); 
    printf("%d\n",fibonacciIterative(n));
    gettimeofday(&t2, NULL);
    time_taken = (t2.tv_sec - t1.tv_sec) * 1e6;
    time_taken = (time_taken + (t2.tv_usec - t1.tv_usec)) * 1e-6;
    printf("Iterative binary search took %f seconds to execute\n", time_taken);
    gettimeofday(&t1, NULL); 
    printf("ans : %d\n",fibonacciRecursive(n));
    gettimeofday(&t2, NULL);
    time_taken = (t2.tv_sec - t1.tv_sec) * 1e6;
    time_taken = (time_taken + (t2.tv_usec - t1.tv_usec)) * 1e-6;
    printf("Recursive binary search took %f seconds to execute\n", time_taken); 
    return 0;
}