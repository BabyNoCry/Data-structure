#include"Stack.h"
void StackInit(Stack* st)
{
	assert(st);
	st->capcity = 10;
	st->top = 0;
	st->data = (Datatype*)malloc(sizeof(Stack));
}
void StackDestory(Stack* st)
{
	assert(st);
	st->top = 0;
	st->capcity = 0;
	free(st->data);
}
int StackEmpty(Stack* st)
{
	assert(st);
	if (st->top == 0)
		return 0;
	else
		return 1;
}
void StackPush(Stack* st, Datatype x)
{
	assert(st);
	if (st->top == st->capcity)
	{
		st->capcity *= 2;
		st->data=realloc(st->data, sizeof(Datatype)*st->capcity);
	}
	st->data[st->top] = x;
	st->top++;
}
void StackPop(Stack* st)
{
	assert(st);
	if (StackEmpty(st) == 0)
		return;
	else
		st->top--;

}
int StackTop(Stack* st)
{
	assert(st&&st->top > 0);
	return st->data[st->top - 1];
}
int StackSize(Stack* st)
{
	if (StackEmpty(st) == 0)
		return 0;
	return st->top;
}