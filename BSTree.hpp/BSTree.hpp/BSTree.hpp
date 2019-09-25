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
		//空树
		if (nullptr == _pRoot)
		{
			_pRoot = new Node(data);
			return true;
		}
		//非空
		//按照二叉搜索树的性质找当前节点在二叉搜索树中的位置
		Node* pCur = _pRoot;
		Node* pParent = nullptr;	//保存双亲结点
		while (pCur)
		{
			pParent = pCur;
			if (data < pCur->_data)
				pCur = pCur->_pLeft;
			else if (data > pCur->_data)
				pCur = pCur->_pRight;
			else
				return false;	//相同不插
		}
		pCur = new Node(data);
		if (data > pParent->_data)
			pParent->_pRight = pCur;
		else
			pParent->_pLeft = pCur;
		return true;
	}

	//删除结点
	bool Delete(T data)
	{
		if (nullptr == _pRoot)
			return false;

		//按照二叉搜索树的规则找待删除结点的位置
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
		//二叉搜索树中没有值为data的结点
		if (pCur == nullptr)
			return false;
		/*
		1.叶子结点  -->直接删除
		2.只有左孩子 --> 直接删除
		3.只有右孩子 --> 直接删除
		4.左右孩子均存在  --->找替代结点
		（左子树找最大值，右子树找最大值）
		1可以与2||3 合并
		*/
		//叶子结点和只有右孩子
		if (nullptr == pCur->_pLeft)
		{
			//待删除结点为根节点
			if (pCur == _pRoot)
				_pRoot->_pRight;
			else
			{
				//待删除结点是其双亲的左孩子
				if (pCur == pParent->_pLeft)
					pParent->_pLeft = pCur->_pRight;
				//待删除节点是其双亲的右孩子
				else
					pParent->_pRight = pCur->_pRight;

			}
		}
		else if (nullptr == pCur->_pRight)
		{
			//pCur只有左孩子
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
			//pCur左右孩子均存在
			//找右子树中替代结点
			//（找最小结点即右子树中最左侧结点）
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

	//最左边元素 最小值
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

	//最右边元素 最大值
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