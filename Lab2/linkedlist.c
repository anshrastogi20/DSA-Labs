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
LIST createNodeList(int n)
{
    NODE nodeNext, tmp, nodeFirst;
    LIST myList = (LIST) malloc(sizeof(struct linked_list)); 
    nodeFirst = (NODE) malloc(sizeof(struct node)); 
    if(myList == NULL)
    {
        printf(" Memory can not be allocated.");
    }
    else
    {
        myList->count = n;
        myList->head = nodeFirst;
// Creating node 1 and linking it to head
        int num;
        printf(" Input data for node 1 : ");
        scanf("%d", &num);
        nodeFirst->ele = num;      
        nodeFirst->next = NULL;
        tmp = nodeFirst;
// Creating remaining nodes and adding to linked list
        for(int i=1; i<n; i++)
        {
            nodeNext = (NODE) malloc(sizeof(struct node)); 
            if(nodeNext == NULL)
            {
                printf(" Memory can not be allocated.");
                break;
            }
            else
            {
                printf(" Input data for node %d : ", i+1);
                scanf(" %d", &num);

                nodeNext->ele = num;      // links the num field of nodeNext with num
                nodeNext->next = NULL; // links the address field of nodeNext with NULL
                
                tmp->next = nodeNext; // links previous node i.e. tmp to the nodeNext
                tmp = tmp->next; 
            }
        }
    }
    return myList;
}

int main()
{
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
    printList(L1);
    return 0;
}