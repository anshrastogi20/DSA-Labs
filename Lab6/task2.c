#include <stdio.h>
#include <stdlib.h>

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

int main()
{
    int n = 10;
    int array[10] = {0,1,0,1,1,1,1,0,0,1};
    part(array,0,n-1,0);
    printelements(array,n);
    return 0;
}

