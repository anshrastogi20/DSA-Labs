#include "intMerge.h"
#include "intMergeAuxIter.c"
// #include "intMergeAuxRec.c"

void merge(struct person A[], int s, int mid, int e)
{
    struct person *C = (struct person *)malloc(sizeof(struct person) * (e - s + 1));
    mergeAux(A, s, mid, A, mid + 1, e, C, 0, e-s);
    for(int i = 0; i < e - s + 1; i++)
    {
        A[s + i] = C[i];
    }
    free(C); 
}