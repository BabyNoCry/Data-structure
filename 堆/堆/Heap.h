#include<stdlib.h>
#include<malloc.h>
#include<string.h>
#include<assert.h>
#include<stdio.h>
typedef int Datatype;
typedef struct Heap
{
	int* _array;
	int  _size;
	int _capcity;
}Heap;
void HeapInit(Heap* hp,int* a, int capcity);
void HeapDestory(Heap* hp);
void HeapPush(Heap* hp,Datatype x);
void HeapPop(Heap* hp);
void print(Heap* hp);
void justDown(int* a, int n,int root);
void justUP(int* a, int n, int root);
void HeapSort(Heap* hp);