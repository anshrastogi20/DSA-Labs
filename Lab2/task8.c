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
LIST createNewList()
{
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
void rotate(int k,LIST L1){
    NODE temp = L1->head;
    int count = 0;
    while(1){
        if (count==k){
            LIST L2 = createNewList();
            NODE node = createNewNode(temp->ele);
            L2->head = node;
            L2->count++;
            NODE temp2 = node;
            temp = temp->next;
            while(L2->count<L1->count){
                NODE nodeNext = createNewNode(temp->ele);
                temp2->next = nodeNext;
                temp = temp->next;
                temp2 = temp2->next;
                L2->count++;
            }
            printList(L2);
            break;
        }
        temp = temp->next;
        count++;
    }
}

int main(){
    int n;
    printf("Enter number of elements : ");
    scanf("%d",&n);
    LIST L1 = createNewList();
    NODE nodeFirst,temp;
    int num;
    printf(" Input data for node 1 : ");
    scanf("%d", &num);
    nodeFirst = createNewNode(num);
    temp = nodeFirst;
    L1->count=n;
    L1->head = nodeFirst;
    for(int i=1; i<n; i++)
    {
        NODE nodeNext;
        printf(" Input data for node %d : ", i+1);
        scanf(" %d", &num);
        nodeNext = createNewNode(num);
        temp->next = nodeNext;
        temp = temp->next; 
    }
    temp->next = nodeFirst;
    int k;
    printf("Enter shift : ");
    scanf("%d",&k);
    rotate(k,L1);
    return 0;
}
