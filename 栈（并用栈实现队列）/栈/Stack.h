#include"common.h"
typedef int Datatype;
typedef struct Stack
{
	Datatype* data;
	int top;
	int capcity;
}Stack;
void StackInit(Stack* st);
void StackDestory(Stack* st);
int StackEmpty(Stack* st);
void StackPush(Stack* st,Datatype x);
void StackPop(Stack* st);
int StackTop(Stack* st);
int StackSize(Stack* st);