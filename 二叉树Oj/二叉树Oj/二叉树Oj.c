//求一个二叉树节点个数
int NodeSize(BTNode* root)
{
	if (root == NULL)
		return 0;
	return 1 + NodeSize(root - left) + NodeSize(root->right);
}

//求叶子节点个数
int NodeSize(BTNode* root)
{
	if (root == NULL)
		return 0;
	if (root->left == NULL && root - < right == NULL)
		return 1;
	return 1 + NodeSize(root - left) + NodeSize(root->right);
}

//求第K层的节点个数
int BinaryTreeLevelKSize(BTNode* root, int k)
{
	if (root == NULL)
		return 0;
	if (k == 1)
		return 1;
	return BinaryTreeLevelKSize(root->left, k - 1) + BinaryTreeLevelKSize(root->right, k - 1);
}

//求树的高度(层数)
int BinaryTreeHeight(BTNode* root)
{
	if (root == NULL)
		return 0;
	int Lheight = 1 + BinaryTreeHeight(root->left);
	int Rheight = 1 + BinaryTreeHeight(root->right);
	return Lheight > Rheight ? Lheight : Rheight;
}

//在一棵树中 查找值为x的节点
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

//用一个前序遍历的数组构建一个二叉树
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
//前序遍历非递归
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

		//子问题：访问右子树
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


//二叉树前序遍历（递归）
void PrevOrder(BTNode* root)
{
	if (root == NULL)
		return;
	printf("%d ", root->val);
	PrevOrder(root->left); 
	PrevOrder(root->right);

}
//后序遍历（递归）
void endOrder(BTNode* root)
{
	if (root == NULL)
		return;

	PrevOrder(root->left);
	PrevOrder(root->right);
	printf("%d ", root->val);

}
//后序遍历（非递归）
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
//中序遍历（递归）
void InOrder(BTNode* root)
{
	if (root == NULL)
		return;
	InOrder(root->left);
	printf("%d ", root->val);
	InOrder(root->right);
}
//中序遍历（非递归）
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

//层序遍历一棵树
//思路：建立一个队列（先进先出） 先进入一个根节点，然后判断是否对空，
//不为空就出对头元素，并分别入队该节点的左右孩子。继续以上动作，知道队空结束
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
//给定一棵二叉树，判断是不是完全二叉树。
//思路：与层序遍历相似，用队列。不同之处是：判断条件是，当出一个元素为空时，则继续出队，若后面的出队的全为空的话
//就是完全二叉树。
int BinTreeComplete(BTNode* root)
{

}

//从前序遍历与中序遍历序列构建二叉树
//根据一棵树的前序遍历与中序遍历构造二叉树。
//注意 :
//你可以假设树中没有重复的元素。
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

//给定两个二叉树，编写一个函数来检验它们是否相同。
//如果两个树在结构上相同，并且节点具有相同的值，则认为它们是相同的。
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

 //判断一棵树是否是平衡二叉树
//给定一个二叉树，判断它是否是高度平衡的二叉树。
//本题中，一棵高度平衡二叉树定义为：
//一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过1。
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
//判断一棵二叉树是否是对称二叉树
//给定一个二叉树，检查它是否是镜像对称的。
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
//编一个程序，读入用户输入的一串先序遍历字符串，根据此字符串建立一个二叉树（以指针方式存储）。
//例如如下的先序遍历字符串： ABC##DE#G##F### 其中“#”表示的是空格，空格字符代表空树。
//建立起此二叉树以后，再对二叉树进行中序遍历，输出遍历结果

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char array[101];

//二叉树结点
typedef struct BiTNode {
	char data;
	struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;

//按先序序列创建二叉树
void CreateBiTree(BiTree &T, int &index, int &n) {
	if (index == n) {
		return;
	}
	//按先序次序输入二叉树中结点的值（一个字符），‘#’表示空树
	if (array[index] == '#') {
		T = NULL;
		index++;
	}
	else {
		T = (BiTree)malloc(sizeof(BiTNode));
		//生成根结点
		T->data = array[index];
		index++;
		//构造左子树
		CreateBiTree(T->lchild, index, n);
		//构造右子树
		CreateBiTree(T->rchild, index, n);
	}
	return;
}
//输出

void Visit(BiTree T) {
	if (T->data != '#') {
		printf("%c ", T->data);
	}
}
//中序遍历
int InOrder(BiTree T) {
	if (T != NULL) {
		//访问左子结点
		InOrder(T->lchild);
		//访问根节点
		printf("%c ", T->data);
		//访问右子结点
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
		//创建二叉树
		CreateBiTree(T, index, len);
		//中序遍历
		InOrder(T);
		printf("\n");
	}
	return 0;
}
