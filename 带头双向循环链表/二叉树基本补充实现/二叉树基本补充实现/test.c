#include"Queue.h"
int main()
{
	int pi = 0;
	char arr[] = "ABD##E#H##CF##G##";
	BTNode* root = BinaryTreeCreate(arr,&pi);//先序创建
	//Queue* Q;
	BinaryTreePrevOrder(root);//前序遍历

	printf("\n");
	BinaryTreePostOrder(root);//后序遍历

	printf("\n");
	BinaryTreeInOrder(root);//中序遍历
	printf("\n");
	printf("%d",BinaryTreeSize(root));//节点数目
	printf("\n");
	printf("%d", BinaryTreeLeafSize(root));//叶子节点数目
	printf("\n");
	char x = 'B';
	BTNode* p ;
	p=BinaryTreeFind(root, x);
	if(p!=NULL)
	printf("%c", p->_data);
	printf("\n");
	//7TreeLevelOrder(root);
	//int i=BinaryTreeLevelKSize(root, 2);
	//printf("%d\n", i);
	int j = BinTreeComplete(root);
	printf("%d", j);
	BinaryTreeDestory(root);//销毁
	system("pause");
	return 0;
}