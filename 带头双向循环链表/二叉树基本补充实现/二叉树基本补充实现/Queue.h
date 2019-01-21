#pragma once
#include"BinTree.h"
typedef BTNode* QDataType;
typedef struct QNode
{
	QDataType val;
	struct QNode* next;
}QNode;
typedef struct Queue
{
	QNode* front;
	QNode* rear;
}Queue;
void InitQueue(Queue* Q);
void DestoryQueue(Queue* Q);
void Queuepush(Queue* Q, QDataType x);
void QueuePop(Queue* Q);
int EmptyQueue(Queue* Q);
int lengthQueue(Queue* Q);
QDataType QueueFront(Queue* Q);