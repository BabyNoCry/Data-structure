#pragma once
#include"Queue.h"
void InitQueue(Queue* Q)
{
	assert(Q);
	QNode* node = (QNode*)malloc(sizeof(QNode));//头节点
	node->next = NULL;
	Q->front = Q->rear = node;
}

void DestoryQueue(Queue* Q)
{
	assert(Q); 
	QNode* node = Q->front;
	while (node)
	{
		QNode* next = node->next;
		free(node);
		node = next;
	}
	Q->front = Q->rear = NULL;
}
int EmptyQueue(Queue* Q)//空返回0，非空返回1；
{
	return Q->front == NULL ? 0 : 1;
}
int LengthQueue(Queue* Q)
{
	assert(Q);
	int count = 0;
	QNode* cur = Q->front;
	while (cur!=NULL)
	{
		count++;
		cur = cur->next;
	}
	return count;
}
void Queuepush(Queue* Q,QDataType x)
{
	assert(Q);
	QNode* newnode = (QNode*)malloc(sizeof(QNode));
	
	if (Q->rear == NULL)
	{
		Q->rear = Q->front = newnode;
	}
	else
	{
		Q->rear->next = newnode;
		Q->rear = newnode;
		Q->rear->val = x;
	}
}
void QueuePop(Queue* Q)
{
	assert(Q);
	QNode* newhead = Q->front->next;
	free(Q->front);
	Q->front = newhead;
}
QDataType QueueFront(Queue* Q)
{
	assert(Q);
	return Q->front->val;
}
