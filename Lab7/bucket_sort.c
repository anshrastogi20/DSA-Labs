#include<stdio.h>
#include<stdlib.h>

typedef struct node * NODE;
struct node{
    int ele;
    NODE next;
};
typedef struct linked_list * LIST;
struct linked_list{
    int count;
    NODE head;
};
void printList(LIST l1) {
NODE temp = l1->head; 
printf("[HEAD] ->"); 
while(temp != NULL)
{
    printf(" %d ->", temp->ele);
    temp = temp->next;
}
    printf(" [NULL]\n");
}
LIST createNewList(){
    LIST myList;
    myList = (LIST) malloc(sizeof(struct linked_list)); 
    myList->count=0;
    myList->head=NULL;
    return myList;
}
NODE createNewNode(int value) {
    NODE myNode;
    myNode = (NODE) malloc(sizeof(struct node)); 
    myNode->ele=value;
    myNode->next=NULL;
    return myNode;
}
void insertFirst(NODE n1,LIST L1){
    if(L1->head==NULL){
        L1->head = n1;
        n1->next = NULL;
        L1->count++;
    }
    else{
        NODE temp = L1->head;
        L1->head = n1;
        n1->next = temp;
        L1->count++;
    }
    return;
}
// void sortList(LIST l1){
//     LIST sorted = createNewList();
//     NODE temp = l1->head;
//     while (temp!=NULL){
//         NODE tempsorted = sorted->head;
//         if(tempsorted == NULL){
//             tempsorted = temp;
//         }
//         else{
//             while(tempsorted!=NULL&&temp->ele>tempsorted->ele){
//                 tempsorted = tempsorted->next;
//             }
//             tempsorted->next = tempsorted;
//             tempsorted = temp;
//         }
//         temp = temp->next;
//     }
//     l1->head = sorted->head;
// }
void sortedInsert(NODE newnode,NODE sorted){
    /* Special case for the head end */
    if (sorted == NULL || sorted->ele >= newnode->ele) {
        newnode->next = sorted;
        sorted = newnode;
    }
    else {
        NODE current = sorted;
        /* Locate the node before the point of insertion*/
        while (current->next != NULL
               && current->next->ele < newnode->ele) {
            current = current->next;
        }
        newnode->next = current->next;
        current->next = newnode;
    }
}
void sortList(LIST l1){
    NODE sorted = NULL;
    NODE current = l1->head;
    while (current!=NULL){
        NODE next = current->next;
        sortedInsert(current,sorted);
        current = next;
    }
    printList(l1);
    l1->head = sorted;
    printList(l1);
}
void intervalSort(float arr[], int n) {
    int i, j;
        // Create n empty buckets
    LIST *b = (LIST *)malloc(n* sizeof(LIST));
    for(i=0; i<n; i++) {
        b[i] = createNewList();
    }
        // Put array elements in different buckets
    for(i=0; i<n; i++) {
        insertFirst(createNewNode(arr[i]),b[(int)(n*arr[i])]); 
    }
        // Sort individual buckets
    for(i=0; i<n; i++) {
        sortList(b[i]); // sortList() function has to be implemented 
    }
        // Concatenate all buckets (in sequence) into arr[]
    for(i=0, j=0; i<n; i++) {
        NODE temp = b[i]->head; 
        while(temp != NULL){
            arr[j++] = temp->ele;
            temp = temp->next;
        }
    } 
}

int main()
{
    int n = 10;
    float array[10] =  {0.78,0.17,0.26,0.39,0.72,0.94,0.12,0.21,0.23,0.68};
    printf("The unsorted array is: ");
    for (int i = 0; i < n; i++) 
    {
        printf("%f ",array[i]);
    }
    printf("\n");
    intervalSort(array,n);
    printf("The sorted array is: ");
    for (int i = 0; i < n; i++) 
    {
        printf("%f ",array[i]);
    }
    printf("\n");
    return 0;
}
