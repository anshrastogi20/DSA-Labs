#ifndef INTMERGEAUX_H
#define INTMERGEAUX_H
struct person
{
    int id;
    char *name;
    int age;
    int height;
    int weight;
};
void mergeAux(struct person A[], int s1, int e1, struct person B[], int s2, int e2, struct person C[], int s3, int e3);
#endif
