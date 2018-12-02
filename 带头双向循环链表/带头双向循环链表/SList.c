#include"SList.h"
ListNode* buyNode(LTDataType x)
{
	ListNode* new = (ListNode*)malloc(sizeof(ListNode));
	new->_data = x;
	new->_next = NULL;
	new->_prev = NULL;
	return new;
}
void ListInit(List* plist)
{
	assert(plist);
	plist->_head = buyNode(-1);
	plist->_head->_next = plist->_head;
	plist->_head->_prev = plist->_head;
}
void ListDestory(List* plist)
{
	assert(plist);
	ListNode* cur = plist->_head->_next;
	while (cur != plist->_head)
	{
		ListNode* next = cur->_next;
		free(cur);
		cur = next;
	}
	free(plist->_head);
	plist->_head = NULL;
}

void ListPushBack(List* plist, LTDataType x)
{
	assert(plist);
	//ListNode* head= plist->_head;
	//ListNode* new = buyNode(x);
	//new->_prev = head->_prev;
	//new->_next = head;
	//head->_prev->_next = new;
	//head->_prev = new;
	ListInsert(plist->_head->_prev, x);
}
void ListPopback(List* plist)
{
	assert(plist);
	ListErase(plist->_head->_prev);
}

ListNode* ListFind(List* plist, LTDataType x)
{
	assert(plist);
	ListNode* cur = plist->_head->_next;
	while (cur != plist->_head)
	{
		if(cur->_data==x)
		{
			return cur;
		}
		cur = cur->_next;
	}
	return NULL;
}
// 在pos的前面进行插入 
void ListInsert(ListNode* pos, LTDataType x)
{
	assert(pos);
	ListNode* head = pos;
	ListNode* new = buyNode(x);
	new->_prev = head->_prev;
	new->_next = head;
	head->_prev->_next = new;
	head->_prev = new;
}
// 删除pos位置的节点 
void ListErase(ListNode* pos)
{
	assert(pos);
	ListNode* node = pos->_next;
	pos->_prev->_next = node;
	free(pos);
	pos = NULL;
}

void ListPushFront(List* plist, LTDataType x)
{
	ListInsert(plist->_head->_next, x);

}
void ListPopFront(List* plist)
{
	assert(plist);
	ListErase(plist->_head->_next);

}
void Listprint(List* plist)
{
	assert(plist);
	ListNode* cur = plist->_head->_next;
		printf("<-head->");
	while (cur != plist->_head)
	{
		printf("<-%d->", cur->_data);
		cur = cur->_next;
	}
	printf("NULL");
	printf("\n");
}
void ListRemove(List* plist, LTDataType x)
{
	assert(plist);
	ListNode* node = ListFind(plist,x);
	ListErase(node);
}

void test()
{
	List S;
	ListInit(&S);
	ListPushBack(&S, 5);
	ListPushBack(&S, 4);
	ListPushBack(&S, 3);
	ListPushBack(&S, 2);
	ListPushBack(&S, 1);

	Listprint(&S);
	ListPushFront(&S, 9);
	ListPushFront(&S, 8);
	ListPushFront(&S, 7);
	ListPushFront(&S, 6);
	ListPushFront(&S, 5);
	Listprint(&S);
	ListPopFront(&S);
	ListPopback(&S);
	Listprint(&S); 
	ListRemove(&S, 4);
	Listprint(&S);




	ListDestory(&S);
}
