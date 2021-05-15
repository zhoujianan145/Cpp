#include<iostream>

using namespace std;
#pragma once

//K,键值
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
		//走到这，说明cur为空，parent为他的上一个节点。
		//确定了他的位置，开始和父亲比较，看放左边还是右边
		Node* newNode = new Node(key,val);
		if (key > parent->_key)
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


	//用来递归的子结构
	void _Inorder(Node* root)
	{
		if (root == nullptr)
			return;

			_Inorder(root->_left);
		    cout << root->_key<<" : "<<root->_val;
			cout << endl;
			_Inorder(root->_right);
	}
    //封装起来让外面可以调用
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
	//		else//找到了，准备删除逻辑
	//		{
	//			
	//			//删除节点左边为空（只有右孩子）
	//			if (cur->_left == nullptr)
	//			{
	//				//假如要删头，而且头的左边为空（上面的条件），就成右单支了
	//				if (cur == _root)
	//				{
	//					_root = cur->_right;
	//				}
	//				else
	//				{
	//					//先看他自己在哪，父亲的左还是右

	//					//他在父亲的左边，要把他的孩子放左边
	//					if (parent->_left == cur)
	//					{
	//						parent->_left = cur->_right;
	//						
	//					}
	//					//他在父亲的右边要把他的孩子放右边
	//					else
	//					{
	//						parent->_right = cur->_right;
	//						
	//					}
	//				}
	//				delete cur;
	//			}
	//			//删除节点右边为空(只有左节点)
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
	//			//两边都有节点
	//			//右子树最小值(最左)为例
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
	//				//覆盖
	//				cur->_key = subMin->_key;
	//				//子树的最左节点,父亲根据subMin在哪一边，连接他的右
	//				if (subMin == smParent->_left)
	//				{
	//					//subMin可以看做左为空
	//					//连上他的右
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