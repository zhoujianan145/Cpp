#include<iostream>

using namespace std;
#pragma once

//K,��ֵ
template<class K,class V>
struct BSTreeNode
{
	const K _key;
	V _val;
	struct BSTreeNode<K,V>* _left;
	struct BSTreeNode<K,V>* _right;

	BSTreeNode(const K& k,const V& v)
		:_key(k)
		, _val(v)
		,_left(nullptr)
		,_right(nullptr)
	{}
};

template<class K,class V>
class BSTree
{
	typedef BSTreeNode<K,V> Node;
public:
	bool Insert(const K& key,const V& val)
	{
		if (_root == nullptr)
		{
			_root = new Node(key,val);
			return true;
		}
		Node* parent = nullptr;
		Node* cur = _root;
		while (cur)
		{
			if (key > cur->_key)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if(key < cur->_key)
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
		Node* newNode = new Node(key,val);
		if (key > parent->_key)
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
	 Node* Find(const K& key)
	{
		Node* cur = _root;
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
		    cout << root->_key<<" : "<<root->_val;
			cout << endl;
			_Inorder(root->_right);
	}
    //��װ������������Ե���
	void Inorder()
	{
		_Inorder(_root);
		cout << endl;
	}
	//bool Erase(const K& val)
	//{
	//	Node* parent = nullptr;
	//	Node* cur = _root;
	//	while (cur)
	//	{
	//		if (val > cur->_key)
	//		{
	//			parent = cur;
	//			cur = cur->_right;
	//		}
	//		else if (val<cur->_key)
	//		{
	//			parent = cur;
	//			cur = cur->_left;
	//		}
	//		else//�ҵ��ˣ�׼��ɾ���߼�
	//		{
	//			
	//			//ɾ���ڵ����Ϊ�գ�ֻ���Һ��ӣ�
	//			if (cur->_left == nullptr)
	//			{
	//				//����Ҫɾͷ������ͷ�����Ϊ�գ���������������ͳ��ҵ�֧��
	//				if (cur == _root)
	//				{
	//					_root = cur->_right;
	//				}
	//				else
	//				{
	//					//�ȿ����Լ����ģ����׵�������

	//					//���ڸ��׵���ߣ�Ҫ�����ĺ��ӷ����
	//					if (parent->_left == cur)
	//					{
	//						parent->_left = cur->_right;
	//						
	//					}
	//					//���ڸ��׵��ұ�Ҫ�����ĺ��ӷ��ұ�
	//					else
	//					{
	//						parent->_right = cur->_right;
	//						
	//					}
	//				}
	//				delete cur;
	//			}
	//			//ɾ���ڵ��ұ�Ϊ��(ֻ����ڵ�)
	//			else if (cur->_right==nullptr)
	//			{
	//				if (cur == _root)
	//				{
	//					cur->_left = _root;
	//				}
	//				else
	//				{
	//					if (parent->_left == cur)
	//					{
	//						parent->_left = cur->_left;
	//					}
	//					else
	//					{
	//						parent->_right = cur->_left;
	//					}
	//				}
	//				delete cur;
	//			}
	//			//���߶��нڵ�
	//			//��������Сֵ(����)Ϊ��
	//			else
	//			{
	//				Node* cur = _root;
	//				Node* subMin = cur->_right;
	//				Node* smParent = cur;
	//				while (subMin->_left)
	//				{
	//					smParent = subMin;
	//					subMin = subMin->_left;
	//				}
	//				//����
	//				cur->_key = subMin->_key;
	//				//����������ڵ�,���׸���subMin����һ�ߣ�����������
	//				if (subMin == smParent->_left)
	//				{
	//					//subMin���Կ�����Ϊ��
	//					//����������
	//					smParent->_left = subMin->_right;
	//				}
	//				else
	//				{
	//					smParent->_right = subMin->_right;
	//				}
	//				delete subMin;
	//			}
	//			return true;
	//		}
	//	}
	//	return false;
	//	
	//}
private:
	Node* _root = nullptr;
};

//#include<iostream>
//using namespace std;
//
//template <class K>
//struct BSTreeNode
//{
//	K _k;
//	struct BSTreeNode<K>* _left;
//	struct BSTreeNode<K>* _right;
//public:
//	BSTreeNode(const K& val)
//		:_k(val)
//		, _left(nullptr)
//		, _right(nullptr)
//	{}
//};

//template<class K>
//class BSTree
//{
//	typedef BSTreeNode<K> Node;
//public:
//	bool Insert(const K& val)
//	{
//		if (_root == nullptr)
//		{
//			Node* newNode = new Node(val);
//			_root = newNode;
//			return true;
//		}
//		Node* parent = nullptr;
//		Node* cur = _root;
//		while (cur)
//		{
//			if (val > cur->_k)
//			{
//				parent = cur;
//				cur = cur->_right;
//			}
//			else if (val < cur->_k)
//			{
//				parent = cur;
//				cur = cur->_left;
//			}
//			else
//			{
//				return false;
//			}
//		}
//		Node* newNode = new Node(val);
//		if (val>parent->_k)
//		{
//			parent->_right = newNode;
//		}
//		else
//		{
//			parent->_left = newNode;
//		}
//		return true;
//	}
//	const Node* Find(const K& val)
//	{
//		Node* cur = root;
//		while (cur)
//		{
//			if (val > cur->_k)
//			{
//				cur = cur->_right;
//			}
//			else if (val<cur->_k)
//			{
//				cur = cur->_left;
//			}
//			else
//			{
//				return cur;
//			}
//		}
//		return nullptr;
//	}
//	void _Inorder(Node* root)
//	{
//		if (root == nullptr)
//			return;
//		_Inorder(root->_left);
//		cout << root->_k << " ";
//		_Inorder(root->_right);
//	}
//	void Inorder()
//	{
//		_Inorder(_root);
//		cout << endl;
//	}
//private:
//	Node* _root = nullptr;
//	
//};