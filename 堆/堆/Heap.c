#include"Heap.h"
void HeapInit(Heap* hp, Datatype* a, int n)
{
	assert(hp&&a);
	hp->_array = (Datatype*)malloc(sizeof(Datatype)*n);
	memcpy(hp->_array, a,sizeof(Datatype)*n);
	hp->_capcity = n;
	hp->_size = n;
	for (int i = (n - 2) / 2; i >= 0; --i)
	{
		justDown(hp->_array, hp->_size, i);
	}
}
void print(Heap* hp)
{
	assert(hp);
	for (int i = 0; i < hp->_size; ++i)
	{
		printf("%d ", hp->_array[i]);
	}
}
void HeapDestory(Heap* hp)
{
	assert(hp);
	free(hp->_array);
	hp->_array = NULL;
	hp->_size = hp->_capcity = 0;
}
void justDown(int* a, int n, int root)
{
	int parent = root;
	int child = parent * 2 + 1;
	
	
	while(child<n)
	{
		if (child + 1 < n&&a[child+1]<a[child])
		{
			child++;
		}
		if (a[parent] > a[child])
		{
			int tmp = a[parent];
			a[parent] = a[child];
			a[child] = tmp;
			parent = child;
			child = parent * 2 + 1;
		}
		else
			break;
	}
	
}
void justUP(int* a, int n, int root)
{
	assert(a);
	int child = root;

	while (child != 0)
	{
		int parent = (child - 1) / 2;
		if (a[parent] < a[child])
		{
			break;
		}
		else
		{
			int tmp = a[parent];
			a[parent] = a[child];
			a[child] = tmp;
			child = parent;
		}
	}
}
void HeapPush(Heap* hp, Datatype x)
{
	assert(hp);
	if (hp->_size == hp->_capcity)
	{
		hp->_capcity *= 2;
		hp->_array = realloc(hp->_array, sizeof(Datatype)*hp->_capcity);
	}
	hp->_array[hp->_size] = x;
	hp->_size++;
	justUP(hp->_array, hp->_size, hp->_size - 1);
	
}
void HeapPop(Heap* hp)//删除堆顶
{
	assert(hp);
	//将堆顶元素与堆底部最后一个元素交换
	int tmp = hp->_array[0];
	hp->_array[0] = hp->_array[hp->_size - 1];;
	hp->_array[hp->_size - 1] = tmp;
	//数组的大小减一
	hp->_size--;
	//重新用向下调整法，调整堆顶，将堆重新调整为小堆
	justDown(hp->_array, hp->_size, 0);
}
void HeapSort(int* a,int n)
{
	assert(a);
	for (int i = (n - 2) / 2; i >= 0; --i)
	{
		justDown(a, n, i);
	}
	for (int i = n - 1; i >= 0; i--)
	{
		int tmp = a[i];
		a[i] = a[0];
		a[0] = tmp;
		justDown(a, i, 0);
	}
}