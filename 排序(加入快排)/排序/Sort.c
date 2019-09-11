//直接插入排序
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<assert.h>
void  InsertSort(int* a, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int end = i;
		int tmp = a[i + 1];
		while (end >= 0)
		{
				
			if (a[end] >tmp)
			{
				a[end + 1] = a[end];
			}
			else
			{
				break;
			}
			end--;
		}
		a[end + 1] = tmp;
	}
}
//希尔排序
void ShellSort(int* a, int n)
{
	int gop = n;
	while (gop > 1)
	{
		gop = gop / 3 + 1;
		for (int i = 0; i < n - gop; i++)
		{
			int end = i;
			int tmp = a[i + gop];
			while (end >=0)
			{
				if (a[end] > tmp)
				{
					a[end + gop] = a[end];
				}
				else
				{
					break;
				}
				end -= gop;
			}
			a[end + gop] = tmp;
		}
	}

}
//交换
void swap(int* a, int* b)
{
	int c = *a;
	*a = *b;
	
	*b =c;
}

//选择排序
void SeletSort(int* a, int n)
{
	int begin = 0;
	int end = n - 1;
	
	while (begin <end)
	{
		int min = begin;
		int max = end;
		for (int i = begin; i <= end; i++)
		{
			if (a[i] > a[max])
			{
				max = i;
			}
			if (a[i] < a[min])
			{
				min = i;
			}
		}
		swap(&a[begin], &a[min]);
		if (max == begin)
		{
			swap(&a[end], &a[min]);
		}
		else
		{
			swap(&a[end], &a[max]);
		}
		
		begin++;
		end--;
	}
}

//堆排序
void JustDown(int* a, int n, int parent)
{
	for (int i = parent; i * 2 + 1 < n; i = parent)
	{
		int child = parent * 2 + 1;
		if (a[child] < a[child + 1] && child != n - 1)
			child++;
		if (a[parent] >= a[child])
		{
			break;
		}
		else
		{
			swap(&a[parent], &a[child]);
			parent = child;
		}
	}
	
}
void HeapSort(int* a, int n)
{
	for (int i = (n - 2) / 2; i >= 0; i--)
	{
		JustDown(a, n, i);

	}
	for (int i = n - 1; i >= 0; i--)
	{
		swap(&a[0], &a[i]);
		JustDown(a, i, 0);
	}
}

//快速排序
//三数取中
int Getmid(int* a, int begin, int end)
{
	int mid = (begin + end) >> 1;
	if (a[begin] > a[mid])
	{
		if (a[begin] > a[end])
		{
			if (a[mid] > a[end])
			{
				return mid;
			}
			else
				return end;
		}
		else
			return begin;

	}
	else if (a[mid] > a[begin])
	{
		if (a[mid] > a[end])
		{
			if (a[begin] > a[end])
				return begin;
			else
				return end;
		}
		else
			return mid;


	}
	else
		return mid;
	
}
//快速排序(递归)
int partSort1(int* a, int begin, int end)
{
	
		int tmp = begin;
		int key = a[begin];
		while (begin < end)
		{
			while (begin < end&&a[end] >= key)
				end--;
			while (begin < end&&a[begin] <= key)
				begin++;
			swap(&a[begin], &a[end]);
		}
		swap(&a[tmp], &a[begin]);
		return begin;
	
}
int partSort2(int* a, int begin, int end)
{
	int tmp = a[begin];
	int key = begin;
	while (begin < end)
	{
		while (begin < end&&a[end] >= tmp)
			end--;
		if (begin < end)
			a[begin] = a[end];
		while (begin < end&&a[begin] <= tmp)
			begin++;
		if (begin < end)
			a[end] = a[begin];		
	}
	a[begin] = tmp;
	return begin;
}
int partSort3(int* a, int begin, int end)
{
	
	/*int cur = begin;
	int prev = begin - 1;
	int key = a[end];
	while (cur <= end)
	{
		if (a[cur] <= key)
		{
			prev++;

			if (prev != cur)
			{
				int tmp = a[cur];
				a[cur] = a[prev];
				a[prev] = tmp;
			}
		}
		cur++;
	}*/
	/*return prev;*/
	int prev = begin - 1;
	int cur = begin;
	int key = a[end];
	while (cur <=end)
	{
			if (a[cur] <= key)
			{
				prev++;
				if (prev != cur)
				{
					int tmp = a[cur];
					a[cur] = a[prev];
					a[prev] = tmp;
				}
			}
			cur++;
	}
	return prev;
}
void QuickSort(int* a, int begin, int end)
{
	int mid;
	int i = 0;
	
	if (begin < end)
	{
		i = Getmid(a, begin, end);
		swap(&a[begin], &a[i]);
		mid = partSort1(a, begin, end);
		QuickSort(a, begin, mid - 1);
		QuickSort(a,mid + 1,end);
	}
}
// 支持动态增长的栈
typedef  int STDataType;
typedef struct Stack
{
	STDataType* _a;
	int _top; // 栈顶
	int _capacity; // 容量
}Stack;

void StackInit(Stack* ps)
{
	assert(ps);
	ps->_a = NULL;
	ps->_capacity = 0;
	ps->_top = 0;
}

void StackDestory(Stack* ps)
{
	assert(ps);
	free(ps->_a);
	ps->_a = NULL;
	ps->_capacity = 0;
	ps->_top = 0;
}

void StackPush(Stack* ps, STDataType x)
{
	assert(ps);
	if (ps->_top == ps->_capacity)
	{
		size_t newcapacity = ps->_capacity == 0 ? 4 : ps->_capacity * 2;
		ps->_a = (STDataType*)realloc(ps->_a, sizeof(STDataType)*newcapacity);
		assert(ps->_a != NULL);
		ps->_capacity = newcapacity;
	}

	ps->_a[ps->_top] = x;
	ps->_top++;
}

void StackPop(Stack* ps)
{
	assert(ps && ps->_top > 0);
	--ps->_top;

}

STDataType StackTop(Stack* ps)
{
	assert(ps && ps->_top > 0);
	return ps->_a[ps->_top - 1];
}

int StackEmpty(Stack* ps)
{
	assert(ps);
	return ps->_top == 0 ? 0 : 1;
}

int StackSize(Stack* ps)
{
	assert(ps);
	return ps->_top;
}

//快速排序（非递归）
void QuickSortNonR(int* a, int left, int right)
{
		Stack st;
		StackInit(&st);

		StackPush(&st, left);
		StackPush(&st, right);

		while (StackEmpty(&st) != 0)
		{
			int end = StackTop(&st); StackPop(&st);
			int begin = StackTop(&st); StackPop(&st);
			int div = partSort2(a, begin, end);
			if (begin < div - 1)
			{
				StackPush(&st, begin);
				StackPush(&st, div - 1);
			}

			if (div + 1 < end)
			{
				StackPush(&st, div + 1);
				StackPush(&st, end);
				}
		}
		StackDestory(&st);

	
}

int main()
{
	int arr1[] = { 9,8,7,6,5,4,3,2,1,0 };
	int arr2[] = { 9,8,7,6,5,4,3,2,1,0 };
	int arr3[] = { 9,8,7,6,5,4,3,2,1,0 };
	int arr4[] = { 9,1,2,4,5,7,6,3,0,8 };
	int arr5[] = { 9,1,2,4,5,7,6,3,0,8 };
	ShellSort(arr2, 10);
	InsertSort(arr1, 10);
	SeletSort(arr3, 10);
	HeapSort(arr4, 10);
	
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", arr1[i]);

	}
	printf("\n");
	for (int i = 0; i < 10; i++)
	{
		
		printf("%d ", arr2[i]);
	}

	printf("\n");
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", arr3[i]);

	}
	printf("\n");
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", arr4[i]);

	}
	QuickSort(arr5, 0, 9);
	printf("\n");
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", arr5[i]);

	}
	system("pause");
	return 0;
}
