#include "element.h"
#include "stack_array.h"
#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 1000
struct Stack
{
    int top;
    Element data[STACK_SIZE];
};

void printStack(Stack *s){
    if (s->top == -1){
        printf("Empty Stack\n");
    }
    for(int i=s->top;i>=0;i--){
        printf("%d %f\n",(s->data+i)->int_value,(s->data+i)->float_value);
    }
}
Stack *newStack()
{
    Stack *s = (Stack *)malloc(sizeof(Stack));
    if(s != NULL)
        s->top = -1;
    return s;
}
bool push(Stack *s, Element e)
{
    if(s->top == STACK_SIZE - 1)
        return false;
    s->data[++(s->top)] = e;
    return true;
}
Element *top(Stack *s){
    if(s->top == -1){
        return NULL;
    }
    return (s->data + s->top);
}
bool pop(Stack *s){
    if(s->top == - 1)
        return false;
    s->data[s->top].float_value = 0;
    s->data[s->top].int_value = 0;
    s->top--;
    return true;
}
bool isEmpty(Stack *s){
    if (s->top == -1){
        return true;
    }
    return false;
}
void freeStack(Stack *s){
    free(s);
}

int main(){
    Stack *s = newStack();
    Element e1;
    int n;
    printf("Enter int value : ");
    scanf("%d",&n);
    float d;
    printf("Enter float value : ");
    scanf("%f",&d);
    e1.int_value = n;
    e1.float_value = d;
    push(s,e1);
    Element e2;
    int n2;
    printf("Enter int value : ");
    scanf("%d",&n2);
    float d2;
    printf("Enter float value : ");
    scanf("%f",&d2);
    e2.int_value = n2;
    e2.float_value = d2;
    push(s,e2);
    Element e3;
    int n3;
    printf("Enter int value : ");
    scanf("%d",&n3);
    float d3;
    printf("Enter float value : ");
    scanf("%f",&d3);
    e3.int_value = n3;
    e3.float_value = d3;
    push(s,e3);
    printStack(s);
    return 0;
}