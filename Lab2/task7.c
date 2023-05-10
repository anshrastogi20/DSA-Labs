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

void insertAfter(int searchEle,NODE n1,LIST L1){
    if(L1->head==NULL){
        L1->head = n1;
        n1->next = NULL;
        L1->count++;
    }
    else{
        NODE temp = L1->head;
        NODE prev = temp;
        while (temp!=NULL)
        {
            if(temp->ele == searchEle){
                break;
            }
            prev = temp;
            temp = temp->next;
        }
        if (temp==NULL){
            printf("Element not found!\n");
            return;
        }
        else{
            if(temp->next==NULL){
                temp->next = n1;
                n1->next = NULL;
                L1->count++;
            }
            else{
                prev = temp;
                temp = temp->next;
                prev->next = n1;
                n1->next = temp;
                L1->count++;
            }
            return;
        }
    }
    return;
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
void deleteFirst(LIST L1){
    if(L1->head==NULL){
        printf("List has no elements!\n");
    }
    else{
        NODE temp = L1->head;
        L1->head = temp->next;
        free(temp);
        L1->count--;
    }
    return;
}
void deleteAt(int pos,LIST L1){
    if(L1->head==NULL){
        printf("List has no elements!\n");
    }
    if(pos==1){
        deleteFirst(L1);
    }
    else{
        NODE temp = L1->head;
        NODE prev = temp;
        int count = 1;
        while (temp!=NULL)
        {
            if(count == pos){
                NODE del = temp;
                prev->next = del->next; 
                free(del);
                L1->count--;
                break;
            }
            prev = temp;
            temp = temp->next;
            count++;
        }
    }
    return;
}
int search(int searchEle,LIST L1){
    if(L1->head==NULL){
        return -1;
    }
    else{
        NODE temp = L1->head;
        NODE prev = temp;
        int count = 1;
        while (temp!=NULL)
        {
            if(temp->ele == searchEle){
                return count;
            }
            prev = temp;
            temp = temp->next;
            count++;
        }
        return -1;
    }
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
// void sortList(LIST l1){
//     LIST sorted = createNewList();
//     NODE temp = l1->head;
//     while (temp!=NULL){
//         NODE tempsorted = sorted->head;
//         if(tempsorted == NULL){
//             tempsorted = temp;
//             tempsorted->next = NULL;
//             sorted->count++;
//             printf("first\n");
//         }
//         else{
//             while(tempsorted->next!=NULL&&temp->next->ele>tempsorted->next->ele){
//                 tempsorted = tempsorted->next;
//             }
//             tempsorted->next = tempsorted;
//             tempsorted = temp;
//             sorted->count++;
//         }
//         temp = temp->next;
//         printList(sorted);
//     }
//     printList(sorted);
//     printList(l1);
//     l1->head = sorted->head;
// }

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
    while (1)
    {
        printf("1) deleteAt(): Deletes the node at the specified position.\n");
        printf("2) insertFirst(): Inserts a new node at the starting position of the linked list.\n");
        printf("3) insertAfter(): Inserts a new node after a given node.\n");
        printf("4) deleteFirst(): Deletes the node at the starting position of the linked list.\n");
        printf("5) search(): Scans through the linked list for a specific value (data).\n");
        printf("6) Display linked list\n");
        printf("7) Exit\n");
        int ch;
        printf("Enter choice : ");
        scanf("%d", &ch);
        if (ch == 1)
        {
            int x;
            printf("Enter position of element to delete : ");
            scanf("%d", &x);
            deleteAt(x,L1);
        }
        else if (ch == 2)
        {
            int ele;
            printf("Enter element to insert : ");
            scanf("%d", &ele);
            NODE node = createNewNode(ele);
            insertFirst(node,L1);
        }
        else if (ch == 3)
        {
            int x;
            printf("Enter element to insert after : ");
            scanf("%d", &x);
            int ele;
            printf("Enter element to insert : ");
            scanf("%d", &ele);
            NODE node = createNewNode(ele);
            insertAfter(x,node,L1);
        }
        else if (ch == 4)
        {
            deleteFirst(L1);
        }
        else if (ch == 5)
        {
            int x;
            printf("Enter element to search : ");
            scanf("%d", &x);
            int res = search(x,L1);
            printf("Result = %d\n",res);
        }
        else if (ch == 6)
        {
            printList(L1);
        }
        else if (ch == 7)
        {
            printf("Exiting... \n");
            break;
        }
        else if(ch==8){
            sortList(L1);
        }
        else
        {
            printf("Please choose a valid option\n");
        }
    }
    return 0;
}