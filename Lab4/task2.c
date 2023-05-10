#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h> 

struct timeval t1, t2;
double time_taken;

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
        printf("%d %s %d %d %d\n",arr[j].id,arr[j].name,arr[j].age,arr[j].weight,arr[j].height);
    }
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
    for (int j=1;j<n;j++){        // FOR HEIGHT sorting
        int k=j-1;
        struct person temp = array[j];
        while(k>=0 && temp.height<array[k].height){
            array[k+1] = array[k];
            k--;
        }
        array[k+1] = temp;
    }
    // for (int j=1;j<n;j++){        //FOR NAME sorting
    //     int k=j-1;
    //     struct person temp = array[j];
    //     while(k>=0 && strcmp(temp.name,array[k].name)<0){
    //         array[k+1] = array[k];
    //         k--;
    //     }
    //     array[k+1] = temp;
    // }
    gettimeofday(&t2, NULL);
    printelements(array,n);
    time_taken = (t2.tv_sec - t1.tv_sec) * 1e6;
    time_taken = (time_taken + (t2.tv_usec - t1.tv_usec)) * 1e-6;
    printf("The tasks took %f seconds to execute\n", time_taken);
    fclose(fp);
    return 0;
}
