#include"Queue.h"
int main()
{
	int pi = 0;
	char arr[] = "ABD##E#H##CF##G##";
	BTNode* root = BinaryTreeCreate(arr,&pi);//���򴴽�
	//Queue* Q;
	BinaryTreePrevOrder(root);//ǰ�����

	printf("\n");
	BinaryTreePostOrder(root);//�������

	printf("\n");
	BinaryTreeInOrder(root);//�������
	printf("\n");
	printf("%d",BinaryTreeSize(root));//�ڵ���Ŀ
	printf("\n");
	printf("%d", BinaryTreeLeafSize(root));//Ҷ�ӽڵ���Ŀ
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
	BinaryTreeDestory(root);//����
	system("pause");
	return 0;
}