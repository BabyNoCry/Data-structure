#include"Heap.h"
int main()
{
	int a[] = { 9,8,2,6,3,1,5,4,7,1 };
	Heap hp;
	HeapInit(&hp,a,10);
	//print(&hp);
	int i = 0;
	HeapPush(&hp, i);
	HeapPush(&hp, i);

	print(&hp);
	printf("\n");
	HeapPop(&hp);
	print(&hp);
	printf("\n");
	HeapSort(hp._array,hp._size);
	print(&hp);

	
	HeapDestory(&hp);
	system("pause");
	return 0;
}