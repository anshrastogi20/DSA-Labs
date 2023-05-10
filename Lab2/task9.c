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
void hasCycle(LIST L1){
    NODE fast = L1->head;
    NODE slow = L1->head;
    fast = fast->next->next;
    slow = slow->next;
    while(1){
        if(fast == slow){
            printf("There is a cycle\n");
            break;
        }
        if(fast == NULL || slow == NULL || fast->next == NULL){
            printf("There is no cycle\n");
            break;
        }
        fast = fast->next->next;
        slow = slow->next;
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
    // temp->next = nodeFirst;      // Making it a cycle
    hasCycle(L1);
    return 0;
}
