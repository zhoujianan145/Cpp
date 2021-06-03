#include<iostream>
#include<cassert>
#include<algorithm>
using namespace std;

template<class K,class V>
class AVLTreeNode
{
public:
	AVLTreeNode(const pair<K, V>& kv)
		:_left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
		, _kv(kv)
		, _bf(0)
	{}
public:
	AVLTreeNode<K, V>* _left;//左孩子
	AVLTreeNode<K, V>* _right;//右孩子

	AVLTreeNode<K, V>* _parent;//父亲
	pair<K, V> _kv;

	int _bf;//平衡因子
};
#include<utility>
template<class K,class V>

class AVLTree
{
	typedef AVLTreeNode<K, V> Node;
private:
	void rotateR(Node* parent)
	{
		
		Node* subL = parent->_left;
		Node* subLR = subL->_right;

		
		parent->_left = subLR;
		if (subLR)//可能为空
		subLR->_parent = parent;

		//假如他是一颗子树，就需要这个节点，连接上一棵树
		Node* parentParent = parent->_parent;

		subL->_right = parent;
		parent->_parent = subL;
		
		//完整的树
		if (parent == _root)
		{
			_root = subL;
			_root->_parent = nullptr;
		}
		else//一颗子树
		{
			
			
			if (parentParent->_left == parent)
			{
				parentParent->_left = subL;
			}
			else
			{
				parentParent->_right = subL;
			}
			subL->_parent = parentParent;
		}
		//位置调好后处理平衡因子

		subL->_bf = parent->_bf = 0;

	}
	void rotateL(Node* parent)
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;

		
		parent->_right = subRL;
		if (subRL)
			subRL->_parent = parent;

		subR->_left = parent;

		Node* parentParent = parent->_parent;
		parent->_parent = subR;

		if (parent == _root)
		{
			_root = subR;
			subR->_parent = nullptr;
		}
		else
		{
			if (parentParent->_left == parent)
			{
				parentParent->_left = subR;
			}
			else
			{
				parentParent->_right = subR;
			}
			subR->_parent = parentParent;
		}
		subR->_bf = parent->_bf = 0;

	}
	void rotateLR(Node* parent)
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;
		int bf = subLR->_bf;//旋转会修改，保存一下
		rotateL(parent->_left);
		rotateR(parent);

		//此时由于插入位置不同，导致subLR的平衡因子情况不同，1,-1,0。从而导致旋转后平衡因子情况不同
		
		if (bf == -1)//新增节点在subLR的左
		{
			subLR->_bf = subL->_bf= 0;
			parent ->_bf= 1;
		}
		else if (bf == 1)//新增节点在subLR的右
		{
			parent->_bf = subLR->_bf = 0;
			 subL->_bf = -1;
			
		}
		else if(bf==0)//subLR本身为新增节点
		{
			subLR ->_bf= subL->_bf = parent->_bf=0;
		}
		else
		{
			assert(false);
		}
	}
	void rotateRL(Node* parent)
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;
		int bf = subRL->_bf;

		rotateR(parent->_right);
		rotateL(parent);

		if (bf == -1)
		{
			parent->_bf = subRL->_bf = 0;
			subR->_bf = 1;
		}
		else if (bf == 1)
		{
			subR->_bf = subRL->_bf = 0;
			parent->_bf = -1;

		}
		else if (bf==0)
		{
			subR->_bf = subRL->_bf = parent->_bf = 0;
		}
		else
		{
			assert(false);
		}
	}
	
public:
	//插入
	//STL库中是iteator,这里用Node*代替 
	pair<Node*, bool> insert(const pair<K,V>& kv)
	{
		// 0. 假如根节点为空
		if (_root == nullptr)
		{
			_root = new Node(kv);
			return make_pair(_root, true);
		}
		Node* cur = _root;
		Node* parent = nullptr;
		//1. 从根节点开始，cur寻找合适的地方,准备插入
		while (cur)
		{
			//小于走左边
			if (cur->_kv.first > kv.first)
			{
				parent = cur;
				cur = cur->_left;

			}
			//大于走右边
			else if (cur->_kv.first < kv.first)
			{
				parent = cur;
				cur = cur->_right;
			}
			//等于的话,返回当前节点指针与false
			else
			{
				return make_pair(cur, false);
			}
		}


		//2. 找到位置，准备插入
		cur = new Node(kv);
		//parent为插入位置的父亲，判断插入到左还是右
		//插入对象比他大，插入到右边
		if (parent->_kv.first < kv.first)
		{
			parent->_right = cur;
			cur->_parent = parent;
		}
		else//小，插入到左边
		{
			parent->_left = cur;
			cur->_parent = parent;
		}

		Node* newNode = cur;//cur会变化，先把它保存下来
		//3. 调节平衡因子
		while(parent)
		{
			//插入在右边，平衡因子++
			if (cur == parent->_right)
			{
				parent->_bf++;
			}
			else//插入在左边,平衡因子--
			{
				parent->_bf--;
			}
			
			if (parent->_bf == 0)//平衡因子为0，说明插入的节点把父亲的一侧填补了，那么不会影响其他树
			{
				break;
			}
			else if (abs(parent->_bf )==1)//当平衡因子为1,或者-1，说明会影响其他树,迭代上去修改
			{
				//迭代上去，改变平衡因子
				cur = parent;
				parent = parent->_parent;
			}
			else if (abs(parent->_bf)==2)//当平衡因子为2或者-2，说明此时，已经不平衡，需要进行旋转
			{
				//因子为-2时
				if (parent->_bf == -2)
				{
					//假如长的一侧在左侧,且新增节点在最左的，右或者左，右单旋
					if (cur->_bf == -1)
					{
						rotateR(parent);
					}
					else//右侧，会引发左右双旋
					{
						rotateLR(parent);
					}
				}
				else//因子为2时
				{
					//假如长的一侧在右侧，且新增节点在最右的，右或者左，左单旋
					if (cur->_bf == 1)
					{
						rotateL(parent);
					}
					else//左侧，引发右左双旋
					{
						rotateRL(parent);
					}
				}
				break;//旋转完成break
			}
			else
			{
				assert(false);
			}

		}
		return make_pair(newNode, true);

	}
	//Find
	Node* Find(const K& k)
	{
		Node* cur = _root;
		while (cur)
		{
			if (cur->_kv.first < k)
			{
				cur = cur->_right;
			}
			else if (cur->_kv.first>k)
			{
				cur = cur->_left;
			}
			else
			{
				return cur;
			}
		}
		
		return nullptr;
	}
	V& operator[](const K& k)
	{
		return (((insert(make_pair(k, V()))).first)->_kv).second;
	}

private:
	//后序遍历验证是否平衡
	int _IsBanlance(Node* root)
	{
		if (root == nullptr)
		{
			return 0;
		}

		int leftHeight = _IsBanlance(root->_left);
		int rightHeight = _IsBanlance(root->_right);
		cout << root->_bf<<endl ;
		if (leftHeight == -1 || rightHeight == -1 || abs(leftHeight - rightHeight) > 1)
		{
			return -1;
		}
		else
		{
			return  max(leftHeight, rightHeight) + 1;
		}
	}
	//中序遍历是否为二叉搜索树
	void _Inorder(Node* root)
	{
		if (root == nullptr)
			return;
		_Inorder(root->_left);
		cout <<root->_kv.first << " : " << root->_kv.second << endl;;
		_Inorder(root->_right);
	}
	public:
	//后序遍历是否平衡
	bool IsBalance()
	{
		return _IsBanlance(_root)>=0;
	}
	void Inorder()
	{
		_Inorder(_root);
	}
private:
	Node* _root=nullptr;
};


