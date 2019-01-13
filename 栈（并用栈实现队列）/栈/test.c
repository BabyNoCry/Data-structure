
#include"Queue.h"
int main()
{
	/*Stack st;
	StackInit(&st);
	StackPush(&st, 1);
	StackPush(&st, 2);
	StackPush(&st, 3);
	printf("Size:%d", StackSize(&st));
	printf("ПеЃК%d\n", StackEmpty(&st));
	printf("top:%d\n", StackTop(&st));
	StackPop(&st);
	printf("ПеЃК%d\n", StackEmpty(&st));
	printf("top:%d\n", StackTop(&st));*/
	MyQueue* pq = MyQueueInit();
	MyQueuePush(pq, 1);
	MyQueuePush(pq, 2);
	MyQueuePush(pq, 3);
	printf("Empty:%d\n",MyQueueEmpty(pq));
	printf("length:%d\n", MyQueueLength(pq));
	printf("Front:%d\n", MyQueueFront(pq));
	MyQueuePop(pq);
	MyQueuePop(pq);
	MyQueuePop(pq);
	MyQueuePop(pq);

	printf("Empty:%d\n", MyQueueEmpty(pq));
	printf("length:%d\n", MyQueueLength(pq));
	printf("Front:%d\n", MyQueueFront(pq));
	MyQueueDestory(pq);
	system("pause");
	return 0;

}