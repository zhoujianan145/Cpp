#include<iostream>
using namespace std;
#pragma once

//K,键值
template<class K>
struct BSTreeNode
{
	K _key;
	struct BSTreeNode<K>* _left;
	struct BSTreeNode<K>* _right;

	BSTreeNode(const K& k)
		:_key(k)
		,_left(nullptr)
		,_right(nullptr)
	{}
};

template<class K>
class BSTree
{
	typedef BSTreeNode<K> Node;
public:
	bool Insert(const K& val)
	{
		if (_root == nullptr)
		{
			_root = new Node(val);
			return true;
		}
		Node* parent = nullptr;
		Node* cur = _root;
		while (cur)
		{
			if (val > cur->_key)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if(val < cur->_key)
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				return false;
			}
		}
		//走到这，说明cur为空，parent为他的上一个节点。
		//确定了他的位置，开始和父亲比较，看放左边还是右边
		Node* newNode = new Node(val);
		if (val > parent->_key)
		{
			parent->_right = newNode;
		}
		else//不存在等于情况，等于的话在前面肯定返回false了
		{
			parent->_left = newNode;
		}

		return true;
	}
	//不允许改
	const Node* Find(const K& key)
	{
		Node* cur = root;
		while (cur)
		{

			if (key > cur->_key)
			{
				cur = cur->_right;
			}
			else if (key == cur->_key)
			{
				return cur;
			}
			else
			{
				cur = cur->_left;
			}
		}
		return nullptr;
	}


	//用来递归的子结构
	void _Inorder(Node* root)
	{
		if (root == nullptr)
			return;

			_Inorder(root->_left);
		    cout << root->_key<<" ";
			_Inorder(root->_right);
	}
    //封装起来让外面可以调用
	void Inorder()
	{
		_Inorder(_root);
		cout << endl;
	}
private:
	Node* _root = nullptr;
};

