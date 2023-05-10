#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h> 

struct person {
    int id; 
    char *name; 
    int age; 
    int height; 
    int weight;
};
struct timeval t1, t2;
double time_taken;

void printelements(struct person arr[],int len){
    for (int j=0;j<len;j++){
        printf("%d %s %d %d %d\n",arr[j].id,arr[j].name,arr[j].age,arr[j].weight,arr[j].height);
    }
}
struct person* swap(struct person *Ls,int i,int j){
    struct person temp = Ls[i];
    Ls[i] = Ls[j];
    Ls[j] = temp;
    return Ls;
}
int part(struct person Ls[], int lo, int hi, int pInd){
    swap(Ls, pInd, lo);
    int pivPos, lt, rt;
    struct person pv;
    lt = lo + 1;
    rt = hi;
    pv = Ls[lo];
    while (lt < rt){
        for (; lt <= hi && Ls[lt].height <= pv.height; lt++);
        for (; Ls[rt].height > pv.height; rt--);
        if (lt < rt) {
            swap(Ls, lt, rt);
            lt++;
            rt--;
        } 
    }
    if (Ls[lt].height < pv.height && lt <= hi)
        pivPos = lt;
    else
        pivPos = lt - 1;
    swap(Ls, lo, pivPos);
    return pivPos;
}
int threePart(struct person Ls[], int lo, int hi, int pInd){
    swap(Ls, pInd, hi - 1);
    int pivPos, lt, rt, mid;
    struct person pv;
    lt = lo;
    rt = hi - 2;
    mid = lo;
    pv = Ls[hi - 1];
    while (mid <= rt){
        if (Ls[mid].height < pv.height){
            swap(Ls, lt, mid);
            lt++;
            mid++;
        }
        else if (Ls[mid].height > pv.height){
            swap(Ls, mid, rt);
            rt--; 
        }
        else{
            mid++;
        }   
    }
    swap(Ls, mid, hi - 1);
    return mid; 
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
    part(array,0,n-1,10);
    // threePart(array,0,n-1,10);
    gettimeofday(&t2, NULL);
    printelements(array,n);
    time_taken = (t2.tv_sec - t1.tv_sec) * 1e6;
    time_taken = (time_taken + (t2.tv_usec - t1.tv_usec)) * 1e-6;
    printf("The tasks took %f seconds to execute\n", time_taken);
    fclose(fp);
    return 0;
}
