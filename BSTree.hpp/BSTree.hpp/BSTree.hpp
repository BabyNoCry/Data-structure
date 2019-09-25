#pragma once

#include<iostream>
using namespace std;
template<class T>
struct BSTNode
{
	BSTNode(const T& data = T())
		:_pLeft(nullptr)
		, _pRight(nullptr)
		, _data(data)
	{}
	BSTNode<T>* _pLeft;
	BSTNode<T>* _pRight;
	T _data;
};

template<class T>
class BSTree
{
	typedef BSTNode<T> Node;
public:
	BSTree()
		:_pRoot(nullptr)
	{}

	~BSTree()
	{
		Destory(_pRoot);
	}
	Node* Find(const T& data)
	{
		Node* pCur = _pRoot;
		while (pCur)
		{
			if (data == pCur->_data)
				return pCur;
			else if (data > pCur->data)
			{
				pCur = pCur->_pRight;
			}
			else
				pCur = pCur->_pLeft;
		}
		return nullptr;
	}
	bool Insert(const T& data)
	{
		//����
		if (nullptr == _pRoot)
		{
			_pRoot = new Node(data);
			return true;
		}
		//�ǿ�
		//���ն����������������ҵ�ǰ�ڵ��ڶ����������е�λ��
		Node* pCur = _pRoot;
		Node* pParent = nullptr;	//����˫�׽��
		while (pCur)
		{
			pParent = pCur;
			if (data < pCur->_data)
				pCur = pCur->_pLeft;
			else if (data > pCur->_data)
				pCur = pCur->_pRight;
			else
				return false;	//��ͬ����
		}
		pCur = new Node(data);
		if (data > pParent->_data)
			pParent->_pRight = pCur;
		else
			pParent->_pLeft = pCur;
		return true;
	}

	//ɾ�����
	bool Delete(T data)
	{
		if (nullptr == _pRoot)
			return false;

		//���ն����������Ĺ����Ҵ�ɾ������λ��
		Node* pCur = _pRoot;
		Node* pParent = nullptr;
		while (pCur)
		{
			if (data == pCur->_data)
				break;
			else if(data < pCur->_data)
			{
				pParent = pCur;
				pCur = pCur->_pLeft;
			}
			else
			{
				pParent = pCur;
				pCur =  pCur->_pRight;
			}
		}
		//������������û��ֵΪdata�Ľ��
		if (pCur == nullptr)
			return false;
		/*
		1.Ҷ�ӽ��  -->ֱ��ɾ��
		2.ֻ������ --> ֱ��ɾ��
		3.ֻ���Һ��� --> ֱ��ɾ��
		4.���Һ��Ӿ�����  --->��������
		�������������ֵ�������������ֵ��
		1������2||3 �ϲ�
		*/
		//Ҷ�ӽ���ֻ���Һ���
		if (nullptr == pCur->_pLeft)
		{
			//��ɾ�����Ϊ���ڵ�
			if (pCur == _pRoot)
				_pRoot->_pRight;
			else
			{
				//��ɾ���������˫�׵�����
				if (pCur == pParent->_pLeft)
					pParent->_pLeft = pCur->_pRight;
				//��ɾ���ڵ�����˫�׵��Һ���
				else
					pParent->_pRight = pCur->_pRight;

			}
		}
		else if (nullptr == pCur->_pRight)
		{
			//pCurֻ������
			if (pCur == _pRoot)
				_pRoot->_pLeft;
			else
			{

				if (pCur == pParent->_pLeft)
					pParent->_pLeft = pCur->_pLeft;

				else
					pParent->_pRight = pCur->_pLeft;

			}
		}
		else
		{
			//pCur���Һ��Ӿ�����
			//����������������
			//������С��㼴��������������㣩
			Node* pFirstofIn = pCur->_pRight;
			pParent = pCur;
			while (pFirstofIn->_pLeft)
			{
				pParent = pFirstofIn;
				pFirstofIn = pFirstofIn->_pLeft;
			}
			pCur->_data = pFirstofIn->_data;
			if (pFirstofIn == pParent->_pLeft)
				pParent->_pLeft = pFirstofIn->_pRight;
			else
				pParent->_pRight = pFirstofIn->_pRight;

			pCur = pFirstofIn;
		}

		delete pCur;
		return true;
	}

	//�����Ԫ�� ��Сֵ
	Node* LeftMost()	
	{
		if (nullptr == _pRoot)
			return nullptr;
		Node* pCur = _pRoot;
		while (pCur->_pLeft)
		{
			pCur = pCur->_pLeft;
		}
		return pCur;
	}

	//���ұ�Ԫ�� ���ֵ
	Node* RightMost()
	{
		if (nullptr == _pRoot)
			return nullptr;
		Node* pCur = _pRoot;
		while (pCur->_pRight)
		{
			pCur = pCur->_pRight;
		}
		return pCur;
	}

	void Inorder()
	{
		_Inorder(_pRoot);
	}
private:
	void _Inorder(Node* pRoot)
	{
		if (pRoot)
		{
			_Inorder(pRoot->_pLeft);
			cout << pRoot->_data << " ";
			_Inorder(pRoot->_pRight);
		}
	}

	void Destory(Node*& pRoot)
	{
		if (pRoot)
		{
			Destory(pRoot->_pLeft);
			Destory(pRoot->_pRight);
			delete pRoot;
			pRoot = nullptr;
		}
	}

	
private:
	Node* _pRoot;
};

void TestBSTree()
{
	int array[] = { 5,3,4,1,7,8,2,6,0,9 };
	BSTree<int> t;
	for (auto e : array)
	{
		t.Insert(e);
	}
	
	cout<< t.LeftMost()->_data << " ";
	cout << t.RightMost()->_data << " ";
	cout << endl;
	t.Inorder();
	t.Delete(8);
	t.Inorder();
	cout << endl;

	t.Delete(0);
	t.Delete(1);
	t.Inorder();
	cout << endl;

	t.Delete(5);
	t.Inorder();
}