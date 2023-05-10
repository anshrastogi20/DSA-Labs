#include "queue_array.h"
#include <stdio.h>
#include <stdlib.h>

#define QUEUE_SIZE 4
struct Queue
{
    int front;
    int rear;
    Element data[QUEUE_SIZE];
};

void printQueue(Queue *q){
    if (q->front == -1){
        printf("Empty Queue\n");
        return;
    }
    int i=q->front;
    while(i!=q->rear){
        printf("%d %f\n",(q->data+i)->int_value,(q->data+i)->float_value);
        if(i==QUEUE_SIZE-1){
            i=0;
        }
        else{
            i++;
        }
    }
    printf("%d %f\n",(q->data+i)->int_value,(q->data+i)->float_value);
}
Queue *createQueue()
{
    Queue *q = (Queue *)malloc(sizeof(Queue));
    if(q != NULL)
        q->front = -1;
        q->rear = -1;
    return q;
}
bool enqueue(Queue *q,Element e){
    if((q->front == 0 && q->rear == QUEUE_SIZE-1)||(q->rear==((q->front-1)%(QUEUE_SIZE-1)))){
        printf("Queue is full\n");
        return false;
    }
    else if(q->front==-1){
        q->front = 0;
        q->rear = 0;
        q->data[q->rear] = e;
        return true;
    }
    else if((q->rear == QUEUE_SIZE-1) && (q->front!=0)){
        q->rear = 0;
        q->data[q->rear] = e;
        return true;
    }
    else{
        q->rear++;
        q->data[q->rear] = e;
        return true;
    }
}
bool dequeue(Queue *q){
    if (q->front == -1){
        printf("Empty Queue\n");
        return false;
    }
    if(q->front==q->rear){
        q->front=-1;
        q->rear=-1;
        return true;
    }
    else if(q->front == QUEUE_SIZE-1){
        q->front=0;
        return true;
    }
    else{
        q->front++;
        return true;
    }
}
Element *front(Queue *q){
    if (q->front == -1){
        printf("Empty Queue\n");
        return NULL;
    }
    return (q->data + q->front);
}
int size(Queue *q){
    if(q->front==-1){
        return 0;
    }
    else if(q->rear>=q->front){
        return (q->rear-q->front+1);
    }
    else{
        return (QUEUE_SIZE-(q->front-q->rear-1));
    }
}
bool isEmpty(Queue *q){
    if (q->front == -1){
        return true;
    }
    return false;
}
void destroyQueue(Queue *q){
    free(q);
}

int main(){
    Queue *q = createQueue();
    Element e1;
    int n;
    printf("Enter int value : ");
    scanf("%d",&n);
    float d;
    printf("Enter float value : ");
    scanf("%f",&d);
    e1.int_value = n;
    e1.float_value = d;
    enqueue(q,e1);
    printQueue(q);
    Element e2;
    int n2;
    printf("Enter int value : ");
    scanf("%d",&n2);
    float d2;
    printf("Enter float value : ");
    scanf("%f",&d2);
    e2.int_value = n2;
    e2.float_value = d2;
    enqueue(q,e2);
    printQueue(q);
    Element e3;
    int n3;
    printf("Enter int value : ");
    scanf("%d",&n3);
    float d3;
    printf("Enter float value : ");
    scanf("%f",&d3);
    e3.int_value = n3;
    e3.float_value = d3;
    enqueue(q,e3);
    printQueue(q);
    dequeue(q);
    printQueue(q);
    dequeue(q);
    printQueue(q);
    Element e4;
    int n4;
    printf("Enter int value : ");
    scanf("%d",&n4);
    float d4;
    printf("Enter float value : ");
    scanf("%f",&d4);
    e4.int_value = n4;
    e4.float_value = d4;
    enqueue(q,e4);
    return 0;
}