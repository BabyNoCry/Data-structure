#include"Stack.h"
typedef struct MyQueue
{
	Stack pushst;
	Stack popst;
}MyQueue;
MyQueue* MyQueueInit();
void MyQueueDestory(MyQueue* pq);
void MyQueuePush(MyQueue* pq, Datatype x);
void MyQueuePop(MyQueue* pq);
int MyQueueEmpty(MyQueue* pq);
int MyQueueLength(MyQueue* pq);
Datatype MyQueueFront(MyQueue* pa);
