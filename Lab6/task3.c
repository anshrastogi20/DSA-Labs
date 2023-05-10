#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

void printelements(int arr[],int len){
    for (int j=0;j<len;j++){
        printf("%d\n",arr[j]);
    }
}
int* swap(int *Ls,int i,int j){
    int temp = Ls[i];
    Ls[i] = Ls[j];
    Ls[j] = temp;
    return Ls;
}
int part(int Ls[], int lo, int hi, int pInd){
    swap(Ls, pInd, lo);
    int pivPos, lt, rt;
    int pv;
    lt = lo + 1;
    rt = hi;
    pv = Ls[lo];
    while (lt < rt){
        for (; lt <= hi && Ls[lt] <= pv; lt++);
        for (; Ls[rt] > pv; rt--);
        if (lt < rt) {
            swap(Ls, lt, rt);
            lt++;
            rt--;
        } 
    }
    if (Ls[lt] < pv && lt <= hi)
        pivPos = lt;
    else
        pivPos = lt - 1;
    swap(Ls, lo, pivPos);
    return pivPos;
}
int pivot(int Ls[],int lo,int hi){
    struct timeval tv;
    gettimeofday(&tv, NULL);
    srand(tv.tv_usec * 1000000 + tv.tv_sec);
    return (rand() % (hi - lo)) + lo;
}
void qs(int Ls[], int lo, int hi){
    if (lo < hi) {
        int p = pivot(Ls, lo, hi);   // Ls[p] is the pivot
        p = part(Ls, lo, hi, p); // Ls[p] is the pivot
        qs(Ls, lo, p - 1);
        qs(Ls, p + 1, hi);
    } 
}

int main()
{
    FILE* fp = fopen("int2.txt", "r");
    int n = 1000;
    int array[n];
    int x;
    for (int i=0;i<n;i++){
        fscanf(fp,"%d",&x);
        array[i] = x;
    }
    qs(array,0,n-1);
    printelements(array,n);
    fclose(fp);
    return 0;
}

