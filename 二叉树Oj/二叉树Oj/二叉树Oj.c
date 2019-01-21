//��һ���������ڵ����
int NodeSize(BTNode* root)
{
	if (root == NULL)
		return 0;
	return 1 + NodeSize(root - left) + NodeSize(root->right);
}

//��Ҷ�ӽڵ����
int NodeSize(BTNode* root)
{
	if (root == NULL)
		return 0;
	if (root->left == NULL && root - < right == NULL)
		return 1;
	return 1 + NodeSize(root - left) + NodeSize(root->right);
}

//���K��Ľڵ����
int BinaryTreeLevelKSize(BTNode* root, int k)
{
	if (root == NULL)
		return 0;
	if (k == 1)
		return 1;
	return BinaryTreeLevelKSize(root->left, k - 1) + BinaryTreeLevelKSize(root->right, k - 1);
}

//�����ĸ߶�(����)
int BinaryTreeHeight(BTNode* root)
{
	if (root == NULL)
		return 0;
	int Lheight = 1 + BinaryTreeHeight(root->left);
	int Rheight = 1 + BinaryTreeHeight(root->right);
	return Lheight > Rheight ? Lheight : Rheight;
}

//��һ������ ����ֵΪx�Ľڵ�
BTNode* BinTreeFind(BTNode* root, BTDataType x)
{
	if (root->NULL)
		return NULL;
	if (root->val == x)
		return root;
	BTNode* ret = BinTreeFind(root->left, x);
	if (ret)
		return ret;
	ret= BinTreeFind(root->right, x);
	if (ret)
		return ret;
	return NULL;

		
}

//��һ��ǰ����������鹹��һ��������
BTNode* CreatTree(char* array, int* pIndex)
{
	if (array[pIndex] == '#')
	{
		(*pIndex)++;
		return NULL;
	}
	else
	{
		BTNode* root = (BTNode*)mallocx(sizeof(BTNode));
		root->left = NULL;
		root->right = NULL;
		root->val = array[*pIndex];
		(*pIndex)++;
		root->left = CreatTree(array, pIndex);
		root->right = CreatTree(array, pIndex);

		return root;
	}

}
//ǰ������ǵݹ�
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 /**
  * Return an array of size *returnSize.
  * Note: The returned array must be malloced, assume caller calls free().
  */
typedef struct TreeNode* STDataType;
typedef struct Stack
{
	STDataType* _a;
	int _top; // ջ��
	int _capacity; // ����
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

int* preorderTraversal(struct TreeNode* root, int* returnSize) {

	Stack st;
	StackInit(&st);
	struct TreeNode* cur = root;
	while (StackEmpty(&st) != 0 || cur != NULL)
	{
		while (cur != NULL)
		{
			++(*returnSize);

			StackPush(&st, cur);

			cur = cur->left;
		}
		struct TreeNode* top = StackTop(&st);
		StackPop(&st);

		//�����⣺����������
		cur = top->right;
	}


	int* arry = (int*)malloc(4 * (*returnSize));
	int i = 0;
	cur = root;
	while (StackEmpty(&st) != 0 || cur)
	{
		while (cur != NULL)
		{
			arry[i++] = cur->val;
			StackPush(&st, cur);
			cur = cur->left;
		}
		struct TreeNode* top = StackTop(&st);
		StackPop(&st);
		cur = top->right;
	}
	return arry;

}


//������ǰ��������ݹ飩
void PrevOrder(BTNode* root)
{
	if (root == NULL)
		return;
	printf("%d ", root->val);
	PrevOrder(root->left); 
	PrevOrder(root->right);

}
//����������ݹ飩
void endOrder(BTNode* root)
{
	if (root == NULL)
		return;

	PrevOrder(root->left);
	PrevOrder(root->right);
	printf("%d ", root->val);

}
//����������ǵݹ飩
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 /**
  * Return an array of size *returnSize.
  * Note: The returned array must be malloced, assume caller calls free().
  */
typedef struct TreeNode* STDataType;
typedef struct Stack
{
	STDataType* _a;
	int _top; // ջ��
	int _capacity; // ����
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

int* postorderTraversal(struct TreeNode* root, int* returnSize) {
	struct TreeNode* prev = NULL;
	Stack st;
	StackInit(&st);
	struct TreeNode* cur = root;
	while (StackEmpty(&st) != 0 || cur != NULL)
	{
		while (cur != NULL)
		{
			(*returnSize)++;
			StackPush(&st, cur);
			cur = cur->left;
		}
		struct TreeNode* top = StackTop(&st);
		if (top->right == NULL || prev == top->right)
		{
			prev = top;
			StackPop(&st);
		}
		else
			cur = top->right;
	}
	int* arry = (int*)malloc(4 * (*returnSize));
	cur = root;
	prev = NULL;
	int i = 0;
	while (StackEmpty(&st) != 0 || cur != NULL)
	{
		while (cur)
		{
			StackPush(&st, cur);
			cur = cur->left;
		}
		struct TreeNode* top = StackTop(&st);
		if (prev == top->right || top->right == NULL)
		{
			prev = top;
			arry[i++] = top->val;

			StackPop(&st);
		}
		else
		{
			cur = top->right;
		}
	}

	return arry;
}
//����������ݹ飩
void InOrder(BTNode* root)
{
	if (root == NULL)
		return;
	InOrder(root->left);
	printf("%d ", root->val);
	InOrder(root->right);
}
//����������ǵݹ飩
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 /**
  * Return an array of size *returnSize.
  * Note: The returned array must be malloced, assume caller calls free().
  */

typedef struct TreeNode* STDataType;
typedef struct Stack
{
	STDataType* _a;
	int _top; // ջ��
	int _capacity; // ����
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

int* inorderTraversal(struct TreeNode* root, int* returnSize) {
	Stack st;
	StackInit(&st);
	struct TreeNode* cur = root;
	while (StackEmpty(&st) != 0 || cur != NULL)
	{
		while (cur)
		{
			(*returnSize)++;
			StackPush(&st, cur);
			cur = cur->left;
		}

		struct TreeNode* top = StackTop(&st);
		StackPop(&st);
		cur = top->right;
	}

	int* arry = (int*)malloc(4 * (*returnSize));
	cur = root;
	int i = 0;
	while (StackEmpty(&st) != 0L || cur != NULL)
	{
		while (cur != NULL)
		{

			StackPush(&st, cur);
			cur = cur->left;
		}

		struct TreeNode* top = StackTop(&st);
		arry[i++] = top->val;
		StackPop(&st);
		cur = top->right;
	}
	return arry;
}

//�������һ����
//˼·������һ�����У��Ƚ��ȳ��� �Ƚ���һ�����ڵ㣬Ȼ���ж��Ƿ�Կգ�
//��Ϊ�վͳ���ͷԪ�أ����ֱ���Ӹýڵ�����Һ��ӡ��������϶�����֪���ӿս���
void LevelOrder(BTNode* root)
{
	Queue pq;
	QueueInit(&pq);
	if (root == NULL)
		return 0;
	while (QueueEmpty(&pq) != 0)
	{
		printf("%d ", QueueFront(&pq));
		QueuePush(pq, root);
		QueuePop(&pq);
		QueuePush(&pq, root->left);
		QueuePush(&pq, root->right);
	}
}
//����һ�ö��������ж��ǲ�����ȫ��������
//˼·�������������ƣ��ö��С���֮ͬ���ǣ��ж������ǣ�����һ��Ԫ��Ϊ��ʱ����������ӣ�������ĳ��ӵ�ȫΪ�յĻ�
//������ȫ��������
int BinTreeComplete(BTNode* root)
{

}

//��ǰ�����������������й���������
//����һ������ǰ�������������������������
//ע�� :
//����Լ�������û���ظ���Ԫ�ء�
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* _buildTree(int* preorder, int* ppindex, int* inorder, int inbegin, int inend)
{


	if (inbegin > inend)
	{
		return NULL;
	}
	struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
	root->val = preorder[*ppindex];
	(*ppindex)++;
	if (inbegin == inend)
	{
		root->left = NULL;
		root->right = NULL;
		return root;

	}
	int rootindex = inbegin;
	while (rootindex <= inend)
	{
		if (inorder[rootindex] == root->val)
		{
			break;
		}
		else
			rootindex++;
	}
	assert(rootindex <= inend);
	root->left = _buildTree(preorder, ppindex, inorder, inbegin, rootindex - 1);
	root->right = _buildTree(preorder, ppindex, inorder, rootindex + 1, inend);
	return root;


}
struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize) {
	int pindex = 0;
	return _buildTree(preorder, &pindex, inorder, 0, inorderSize - 1);
}

//������������������дһ�����������������Ƿ���ͬ��
//����������ڽṹ����ͬ�����ҽڵ������ͬ��ֵ������Ϊ��������ͬ�ġ�
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
	if (p == q && q == NULL)
	{
		return true;
	}
	else if (p == NULL || q == NULL)
	{
		return false;
	}
	else
	{
		return (p->val == q->val) && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
	}
}

 //�ж�һ�����Ƿ���ƽ�������
//����һ�����������ж����Ƿ��Ǹ߶�ƽ��Ķ�������
//�����У�һ�ø߶�ƽ�����������Ϊ��
//һ��������ÿ���ڵ� ���������������ĸ߶Ȳ�ľ���ֵ������1��
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int maxDepth(struct TreeNode* root) {

	if (root == NULL)
	{
		return 0;
	}
	int left = maxDepth(root->left);
	int right = maxDepth(root->right);
	return left > right ? left + 1 : right + 1;
}
bool isBalanced(struct TreeNode* root) {
	if (root == NULL)
		return true;
	int Lh = maxDepth(root->left);
	int Rh = maxDepth(root->right);
	if (abs(Lh - Rh) <= 1)
	{

		return isBalanced(root->left) && isBalanced(root->right);
	}
	else
	{
		return false;
	}

}
//�ж�һ�ö������Ƿ��ǶԳƶ�����
//����һ����������������Ƿ��Ǿ���ԳƵġ�
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool _isSymmetric(struct TreeNode* Tleft, struct TreeNode* Tright)
{
	if (Tleft == NULL && Tright == NULL)
		return true;
	if (Tleft == NULL || Tright == NULL)
		return false;
	if (Tleft->val == Tright->val)
	{
		return _isSymmetric(Tleft->left, Tright->right) && _isSymmetric(Tleft->right, Tright->left);
	}
	return false;

}
bool isSymmetric(struct TreeNode* root) {
	if (root == NULL)
		return true;
	return _isSymmetric(root->left, root->right);
}
//��һ�����򣬶����û������һ����������ַ��������ݴ��ַ�������һ������������ָ�뷽ʽ�洢����
//�������µ���������ַ����� ABC##DE#G##F### ���С�#����ʾ���ǿո񣬿ո��ַ����������
//������˶������Ժ��ٶԶ����������������������������

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char array[101];

//���������
typedef struct BiTNode {
	char data;
	struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;

//���������д���������
void CreateBiTree(BiTree &T, int &index, int &n) {
	if (index == n) {
		return;
	}
	//�������������������н���ֵ��һ���ַ�������#����ʾ����
	if (array[index] == '#') {
		T = NULL;
		index++;
	}
	else {
		T = (BiTree)malloc(sizeof(BiTNode));
		//���ɸ����
		T->data = array[index];
		index++;
		//����������
		CreateBiTree(T->lchild, index, n);
		//����������
		CreateBiTree(T->rchild, index, n);
	}
	return;
}
//���

void Visit(BiTree T) {
	if (T->data != '#') {
		printf("%c ", T->data);
	}
}
//�������
int InOrder(BiTree T) {
	if (T != NULL) {
		//�������ӽ��
		InOrder(T->lchild);
		//���ʸ��ڵ�
		printf("%c ", T->data);
		//�������ӽ��
		InOrder(T->rchild);
	}
	return 0;
}
int main()
{
	int len, index;
	while (scanf("%s", array) != EOF) {
		BiTree T;
		len = strlen(array);
		index = 0;
		//����������
		CreateBiTree(T, index, len);
		//�������
		InOrder(T);
		printf("\n");
	}
	return 0;
}
