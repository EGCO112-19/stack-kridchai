
#ifndef stack_h
#define stack_h
#include "node.h"
typedef struct {
	NodePtr top;
	int size;
}Stack;

typedef Stack * StackPtr;
void push(StackPtr s, char value)
{
    NodePtr nodeptr = (NodePtr) malloc(sizeof(Node));
    nodeptr->nextPtr = s->top;
    nodeptr->data = value;
    s->top = nodeptr;
    s->size+=1;
  
}
char pop(StackPtr s){
  NodePtr t = s->top;
  char value;
    s->top = t->nextPtr;
    value = t->data;
    free(t);
    s->size-=1;
    return value;
}
void pop_all(StackPtr s){
    NodePtr t;
    while(s->size !=0)
    {
        t = s->top;
     s->top = t->nextPtr;
     free(t);
     s->size-=1;
    }
   
   
}







#endif
