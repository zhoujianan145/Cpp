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
	AVLTreeNode<K, V>* _left;//����
	AVLTreeNode<K, V>* _right;//�Һ���

	AVLTreeNode<K, V>* _parent;//����
	pair<K, V> _kv;

	int _bf;//ƽ������
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
		if (subLR)//����Ϊ��
		subLR->_parent = parent;

		//��������һ������������Ҫ����ڵ㣬������һ����
		Node* parentParent = parent->_parent;

		subL->_right = parent;
		parent->_parent = subL;
		
		//��������
		if (parent == _root)
		{
			_root = subL;
			_root->_parent = nullptr;
		}
		else//һ������
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
		//λ�õ��ú���ƽ������

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
		int bf = subLR->_bf;//��ת���޸ģ�����һ��
		rotateL(parent->_left);
		rotateR(parent);

		//��ʱ���ڲ���λ�ò�ͬ������subLR��ƽ�����������ͬ��1,-1,0���Ӷ�������ת��ƽ�����������ͬ
		
		if (bf == -1)//�����ڵ���subLR����
		{
			subLR->_bf = subL->_bf= 0;
			parent ->_bf= 1;
		}
		else if (bf == 1)//�����ڵ���subLR����
		{
			parent->_bf = subLR->_bf = 0;
			 subL->_bf = -1;
			
		}
		else if(bf==0)//subLR����Ϊ�����ڵ�
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
	//����
	//STL������iteator,������Node*���� 
	pair<Node*, bool> insert(const pair<K,V>& kv)
	{
		// 0. ������ڵ�Ϊ��
		if (_root == nullptr)
		{
			_root = new Node(kv);
			return make_pair(_root, true);
		}
		Node* cur = _root;
		Node* parent = nullptr;
		//1. �Ӹ��ڵ㿪ʼ��curѰ�Һ��ʵĵط�,׼������
		while (cur)
		{
			//С�������
			if (cur->_kv.first > kv.first)
			{
				parent = cur;
				cur = cur->_left;

			}
			//�������ұ�
			else if (cur->_kv.first < kv.first)
			{
				parent = cur;
				cur = cur->_right;
			}
			//���ڵĻ�,���ص�ǰ�ڵ�ָ����false
			else
			{
				return make_pair(cur, false);
			}
		}


		//2. �ҵ�λ�ã�׼������
		cur = new Node(kv);
		//parentΪ����λ�õĸ��ף��жϲ��뵽������
		//�����������󣬲��뵽�ұ�
		if (parent->_kv.first < kv.first)
		{
			parent->_right = cur;
			cur->_parent = parent;
		}
		else//С�����뵽���
		{
			parent->_left = cur;
			cur->_parent = parent;
		}

		Node* newNode = cur;//cur��仯���Ȱ�����������
		//3. ����ƽ������
		while(parent)
		{
			//�������ұߣ�ƽ������++
			if (cur == parent->_right)
			{
				parent->_bf++;
			}
			else//���������,ƽ������--
			{
				parent->_bf--;
			}
			
			if (parent->_bf == 0)//ƽ������Ϊ0��˵������Ľڵ�Ѹ��׵�һ����ˣ���ô����Ӱ��������
			{
				break;
			}
			else if (abs(parent->_bf )==1)//��ƽ������Ϊ1,����-1��˵����Ӱ��������,������ȥ�޸�
			{
				//������ȥ���ı�ƽ������
				cur = parent;
				parent = parent->_parent;
			}
			else if (abs(parent->_bf)==2)//��ƽ������Ϊ2����-2��˵����ʱ���Ѿ���ƽ�⣬��Ҫ������ת
			{
				//����Ϊ-2ʱ
				if (parent->_bf == -2)
				{
					//���糤��һ�������,�������ڵ�������ģ��һ������ҵ���
					if (cur->_bf == -1)
					{
						rotateR(parent);
					}
					else//�Ҳ࣬����������˫��
					{
						rotateLR(parent);
					}
				}
				else//����Ϊ2ʱ
				{
					//���糤��һ�����Ҳ࣬�������ڵ������ҵģ��һ���������
					if (cur->_bf == 1)
					{
						rotateL(parent);
					}
					else//��࣬��������˫��
					{
						rotateRL(parent);
					}
				}
				break;//��ת���break
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
	//���������֤�Ƿ�ƽ��
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
	//��������Ƿ�Ϊ����������
	void _Inorder(Node* root)
	{
		if (root == nullptr)
			return;
		_Inorder(root->_left);
		cout <<root->_kv.first << " : " << root->_kv.second << endl;;
		_Inorder(root->_right);
	}
	public:
	//��������Ƿ�ƽ��
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


