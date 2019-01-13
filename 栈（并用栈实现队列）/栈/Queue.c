#include"Queue.h"
MyQueue* MyQueueInit()
{
	MyQueue* pq = (MyQueue*)malloc(sizeof(MyQueue));
	StackInit(&pq->pushst);
	StackInit(&pq->popst);
	return pq;

}
void MyQueueDestory(MyQueue* pq)
{
	assert(pq);
	StackDestory(&pq->popst);
	StackDestory(&pq->pushst);
	free(pq);

}
void MyQueuePush(MyQueue* pq, Datatype x)
{
	assert(pq);
	StackPush(&pq->pushst, x);

}
void MyQueuePop(MyQueue* pq)
{
	assert(pq&&MyQueueEmpty(pq) != 0);
	 if (StackEmpty(&pq->popst) != 0)
			StackPop(&pq->popst);
		else
		{
			while (StackEmpty(&pq->pushst) != 0)
			{
				StackPush(&pq->popst, StackTop(&pq->pushst));
				StackPop(&pq->pushst);
			}
			StackPop(&pq->popst);

		}


}
int MyQueueEmpty(MyQueue* pq)
{
	if (StackEmpty(&pq->popst) == 0 && StackEmpty(&pq->pushst) == 0)
		return 0;
	return 1;
}
int MyQueueLength(MyQueue* pq)
{
	assert(pq);
	return StackSize(&pq->popst) + StackSize(&pq->pushst);
}
Datatype MyQueueFront(MyQueue* pq)
{
	assert(pq&&MyQueueEmpty(pq)!=0);

	if (StackEmpty(&pq->popst) != 0)
		return StackTop(&pq->popst);
	else
	{
		while (StackEmpty(&pq->pushst) != 0)
		{
			StackPush(&pq->popst, StackTop(&pq->pushst));
			StackPop(&pq->pushst);
		}
		return StackTop(&pq->popst);

	}
}
