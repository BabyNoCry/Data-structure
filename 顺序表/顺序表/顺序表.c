#include"Ë³Ðò±í.h"
#include"common.h"

void SeqListInit(SeqList* psl, size_t capacity)
{
	psl->array = (SLDataType*)malloc(capacity * sizeof(SLDataType));
	
	
	psl->capicity = capacity;
	psl->size = 0;

}
void SeqListPushBack(SeqList* psl, SLDataType x)
{
	assert(psl);
	CheckCapacity(psl);

	psl->array[psl->size] = x;
	psl->size++;
}
void SeqListPrint(SeqList* psl)
{	assert(psl);
	for (size_t i = 0; i < psl->size; i++)
	{
		printf("%d ", psl->array[i]);
	}
	printf("\n");
}
void SeqListDestory(SeqList* psl)
{
	assert(psl);
	if (psl->array)
	{
		free(psl->array);
		psl->array = NULL;
	}
	psl->capicity = 0;
	psl->size = 0;
}
void SeqListPopBack(SeqList* psl)
{
	assert(psl);
	psl->size--;
}
void SeqListPushFront(SeqList* psl, SLDataType x)
{
	assert(psl);
	CheckCapacity(psl);
	for (int i = psl->size - 1; i >= 0; i--)
	{
		psl->array[i + 1] = psl->array[i];
	}
	psl->array[0] = x;
	psl->size++;
}
void SeqListPopFront(SeqList* psl)
{
	assert(psl);
	for (size_t i = 0; i < psl->size-1; i++)
	{
		psl->array[i] = psl->array[i + 1];
	}
	psl->size--;
}

void CheckCapacity(SeqList* psl)
{
	assert(psl);
	if (psl->size== psl->capicity)
	{
		psl->capicity *= 2;
		psl->array = realloc(psl->array, psl->capicity * sizeof(SLDataType));
			assert(psl->array);
	}
}
int SeqListFind(SeqList* psl, SLDataType x)
{
	assert(psl);
	for (size_t i = 0; i < psl->size; i++)
	{
		if (psl->array[i] == x)
		{
			return i;
		}
	}
	return -1;
}
void SeqListInsert(SeqList* psl, size_t pos, SLDataType x)
{
	assert(psl);
	CheckCapacity(psl);
	size_t i = psl->size-1;
	while (i >= pos)
	{
		psl->array[i + 1] = psl->array[i];
		i--;
	}
	psl->array[pos] = x;
	psl->size++;
}
void SeqListErase(SeqList* psl, size_t pos)
{
	assert(psl&&pos<psl->size);
	size_t i = pos;
	while (i<psl->size-1)
	{
		psl->array[i] = psl->array[i+1];
		i++;
	}
	psl->size--;
}
void SeqListRemove(SeqList* psl, SLDataType x)
{
	assert(psl);
	size_t i = 0;
	while (i < psl->size)
	{
		if (psl->array[i] == x)
		{
			SeqListErase(psl, i);
			break;
		}
		i++;
	}


}
void SeqListModify(SeqList* psl, size_t pos, SLDataType x)
{
	assert(psl);
	size_t i = 0;
	psl->array[pos] = x;
}
void SeqListBubbleSort(SeqList* psl)
{
	assert(psl);
	size_t i = 0;
	size_t j = 0;
	for (i = 0; i < psl->size-1; i++)
	{
		for (j = 1; j < psl->size-i; j++)
		{
			if (psl->array[j] >psl->array[j-1])
			{
				size_t tmp = psl->array[j];
				psl->array[j] = psl->array[j-1];
				psl->array[j-1] = tmp;
			}
		}
	}
}
void SeqListRemoveAll(SeqList* psl, SLDataType x)
{
	assert(psl);
	SLDataType* c = psl->array+1;
	SLDataType* p = psl->array;
	while (c != psl->array + psl->size)
	{
		if (*p != x)
		{
			p++;
			c++;
		}
		else if (*c != x)
		{
			SLDataType m = *p;
			*p = *c;
			*c = m;
			c++;
			p++;
		}
		else
		{
			c++;
		}
	}
	psl->size = p - psl->array;	
}
int SeqListBinaryFind(SeqList* psl, SLDataType x);

void test()
{
	SeqList S;
	SeqListInit(&S, 5);
	SeqListPushBack(&S, 2);
	SeqListPushBack(&S, 2);
	SeqListPushBack(&S, 3);
	SeqListPushBack(&S, 2);
	SeqListPushBack(&S, 2);
	SeqListPushBack(&S, 6);

	/*SeqListPrint(&S);
	SeqListPopBack(&S);
	SeqListPushFront(&S, 2);
	SeqListPopFront(&S);
	SeqListPrint(&S);
	SeqListInsert(&S, 2, 5);
	SeqListPrint(&S);
	SeqListErase(&S, 0);
	SeqListPrint(&S);
	SeqListModify(&S, 0, 10);
	SeqListPrint(&S);*/
	//SeqListBubbleSort(&S);
	//SeqListPrint(&S);
	//SeqListRemove(&S, 2);
	SeqListRemoveAll(&S, 2);

	SeqListPrint(&S);
	SeqListDestory(&S);
} 

