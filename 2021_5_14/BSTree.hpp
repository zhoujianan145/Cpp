#include<iostream>
using namespace std;
#pragma once

//K,��ֵ
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
		//�ߵ��⣬˵��curΪ�գ�parentΪ������һ���ڵ㡣
		//ȷ��������λ�ã���ʼ�͸��ױȽϣ�������߻����ұ�
		Node* newNode = new Node(val);
		if (val > parent->_key)
		{
			parent->_right = newNode;
		}
		else//�����ڵ�����������ڵĻ���ǰ��϶�����false��
		{
			parent->_left = newNode;
		}

		return true;
	}
	//�������
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


	//�����ݹ���ӽṹ
	void _Inorder(Node* root)
	{
		if (root == nullptr)
			return;

			_Inorder(root->_left);
		    cout << root->_key<<" ";
			_Inorder(root->_right);
	}
    //��װ������������Ե���
	void Inorder()
	{
		_Inorder(_root);
		cout << endl;
	}
private:
	Node* _root = nullptr;
};

