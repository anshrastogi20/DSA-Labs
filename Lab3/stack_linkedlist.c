#include "element.h"
#include "stack_linkedlist.h"
#include <stdio.h>
#include <stdlib.h>

LIST createNewList(){
    LIST myList;
    myList = (LIST) malloc(sizeof(struct linked_list)); 
    myList->count=0;
    myList->head=NULL;
    return myList;
}
NODE createNewNode(Element data) {
    NODE myNode;
    myNode = (NODE) malloc(sizeof(struct node)); 
    myNode->data.float_value = data.float_value;
    myNode->data.int_value = data.int_value;
    myNode->next=NULL;
    return myNode;
}
void printList(LIST l1) {
NODE temp = l1->head; 
printf("[HEAD]\n"); 
while(temp != NULL)
{
    printf("%d %f\n", temp->data.int_value,temp->data.float_value);
    temp = temp->next;
}
    printf("[NULL]\n");
}
void insertNodeIntoList(NODE node, LIST list){
    if(list->head==NULL){
        list->head = node;
        node->next = NULL;
        list->count++;
    }
    else{
        NODE temp = list->head;
        list->head = node;
        node->next = temp;
        list->count++;
    }
}
void removeFirstNode(LIST list){
    if(list->head==NULL){
        printf("Empty Stack\n");
    }
    else{
        NODE temp = list->head;
        list->head = temp->next;
        list->count--;
        free(temp);
    }
}
void insertNodeAtEnd(NODE node, LIST list){
    if(list->head==NULL){
        list->head = node;
        node->next = NULL;
        list->count++;
    }
    else{
        NODE temp = list->head;
        while(temp->next!=NULL){
            temp = temp->next;
        }
        temp->next = node;
        node->next = NULL;
        list->count++;
    }
}
void destroyList(LIST l1){
    free(l1);
}

int main(){
    LIST L1 = createNewList();
    Element e1;
    int n;
    printf("Enter int value : ");
    scanf("%d",&n);
    float d;
    printf("Enter float value : ");
    scanf("%f",&d);
    e1.int_value = n;
    e1.float_value = d;
    NODE node1 = createNewNode(e1);
    insertNodeIntoList(node1,L1);
    Element e2;
    int n2;
    printf("Enter int value : ");
    scanf("%d",&n2);
    float d2;
    printf("Enter float value : ");
    scanf("%f",&d2);
    e2.int_value = n2;
    e2.float_value = d2;
    NODE node2 = createNewNode(e2);
    // insertNodeIntoList(node2,L1);
    Element e3;
    int n3;
    printf("Enter int value : ");
    scanf("%d",&n3);
    float d3;
    printf("Enter float value : ");
    scanf("%f",&d3);
    e3.int_value = n3;
    e3.float_value = d3;
    NODE node3 = createNewNode(e3);
    printList(L1);
    // removeFirstNode(L1);
    // printList(L1);
    insertNodeAtEnd(node3,L1);
    insertNodeAtEnd(node2,L1);
    printList(L1);
    return 0;
}