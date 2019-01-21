#include"Queue.h"
// 通过前序遍历的数组"ABD##E#H##CF##G##"构建二叉树
BTNode* BinaryTreeCreate(BTDataType* a,int* pi)
{	
	if (a[*pi] == '#')
		{
			(*pi)++;
			return NULL;
		}
		else
		{
		BTNode* root = (BTNode*)malloc(sizeof(BTNode));
			root->_data = a[*pi];
			root->_left = NULL;
			root->_right = NULL;
			(*pi)++;
			root->_left = BinaryTreeCreate(a,pi);
			root->_right = BinaryTreeCreate(a,pi);
			return root;
		}
	
	
}
void BinaryTreeDestory(BTNode* root)
{
	if (root == NULL)
	{
		return;
	}
	BinaryTreeDestory(root->_left);
	BinaryTreeDestory(root->_right);
	free(root);

}
int BinaryTreeSize(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
		int left = BinaryTreeSize(root->_left);
		int right= BinaryTreeSize(root->_right);
		return left + right + 1;
}
int BinaryTreeLeafSize(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	if (root->_left == NULL && root->_right == NULL)
	{
		return 1;
	}
	return BinaryTreeLeafSize(root->_left)+	BinaryTreeLeafSize(root->_right);

}
int BinaryTreeLevelKSize(BTNode* root, int k)
{
	if (root = NULL)
		return 0;
	if (k == 1)
	{
		return 1;
	}
	return BinaryTreeLevelKSize(root->_left, k-1) + BinaryTreeLevelKSize(root->_right, k-1);
}
BTNode* BinaryTreeFind(BTNode* root, BTDataType x)
{
	if (root == NULL)
		return NULL;
	if (root->_data == x)
		return root;
	BTNode* ret;
	ret = BinaryTreeFind(root->_left, x);
	if (ret)
	{
		return ret;
	}
	ret = BinaryTreeFind(root->_right, x);
	if (ret)
	{
		return ret;
	}
	return NULL;
}


//
void BinaryTreePrevOrder(BTNode* root)
{
	if (root == NULL)
	{
		return;
	}
	else
	{
		printf("%c", root->_data);
		BinaryTreePrevOrder(root->_left);
		BinaryTreePrevOrder(root->_right);
	}

}
void BinaryTreeInOrder(BTNode* root)
{
	if (root == NULL)
	{
		return;
	}
	else
	{
		BinaryTreeInOrder(root->_left);
		printf("%c", root->_data);
		BinaryTreeInOrder(root->_right);

	}
}
void BinaryTreePostOrder(BTNode* root)
{
	if (root == NULL)
	{
		return;
	}
	else
	{
		BinaryTreePostOrder(root->_left);
		BinaryTreePostOrder(root->_right);
		printf("%c", root->_data);
	}
}
void TreeLevelOrder(BTNode* root)
{
	Queue q;
	InitQueue(&q);
	if (root)
		Queuepush(&q, root);
	while (EmptyQueue(&q) != 0)
	{
		BTNode* front = QueueFront(&q);
		printf("%c", front->_data);
		if (front->_left!= NULL)
		{
			Queuepush(&q, front->_left);
		}
		if (front->_right!= NULL)
		{
			Queuepush(&q, front->_right);
		}
		QueuePop(&q);
	}
}
int BinTreeComplete(BTNode* root)
{
	Queue q;
	InitQueue(&q);
	if (root != NULL)
	{
		Queuepush(&q, root);
		while (EmptyQueue(&q) != 0)
		{
			BTNode* front = QueueFront(&q);
			QueuePop(&q);
			if (front == NULL)
			{
				break;
			}
			Queuepush(&q,front->_left);
			Queuepush(&q, front->_right);

		}
		while (EmptyQueue(&q) != 0)
		{
			BTNode* front = QueueFront(&q);
			QueuePop(&q);
			if (front != NULL)
			{
				DestoryQueue(&q);
				return 0;
			}
		}
	}
}