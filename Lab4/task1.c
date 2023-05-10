#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct person
{
    int id;
    char *name;
    int age;
    int height;
    int weight;
};
void printelements(struct person arr[],int len){
    for (int j=0;j<len;j++){
        printf("%d %s %d %d %d\n",arr[j].id,arr[j].name,arr[j].age,arr[j].height,arr[j].weight);
    }
}

int main()
{
    int n;
    printf("Enter number of elements : ");
    scanf("%d",&n);
    struct person *array =  (struct person *)malloc(n * sizeof(struct person));
    for (int i=0;i<n;i++){
        array[i].name = (char *)malloc(10 * sizeof(char));
        printf("Enter details for person %d\n",i+1);
        printf("Enter id : ");
        scanf("%d",&array[i].id);
        printf("Enter name : ");
        scanf("%s",array[i].name);
        printf("Enter age : ");
        scanf("%d",&array[i].age);
        printf("Enter height : ");
        scanf("%d",&array[i].height);
        printf("Enter weight : ");
        scanf("%d",&array[i].weight);
    }
    printelements(array,n);
    for (int j=1;j<n;j++){
        int k=j-1;
        struct person temp = array[j];
        while(k>=0 && temp.height<array[k].height){
            array[k+1] = array[k];
            k--;
        }
        array[k+1] = temp;
    }
    printelements(array,n);
    return 0;
}