

#include<iostream>
#include<assert.h>
#include<algorithm>

namespace zjn
{
	//list�ڵ�Ľṹ
	template<class T>
	struct __list_node
	{
		//�β�����д��ԭ���ǣ���һT���Զ������ͣ�list<string>
		__list_node(const T& x = T())
		:_prev(nullptr)
		, _next(nullptr)
		, _data(x)
		{}
		__list_node<T>* _prev;
		__list_node<T>* _next;
		T _data;
	};
	//list�������Ľṹ
	//ԭ��ָ�����㲻������������Ҫ�Լ�дһ��������
	template<class T,class Ref,class Ptr>
	//��list�������ʱ��Ҫ����node��ȷ��λ�õ�ǰ��ڵ㣬���Գ�Ա�������ǹ��е�
	struct __list_iterator
	{
		typedef __list_iterator<T,Ref,Ptr> self;
		typedef __list_node<T> node;
         
		//�ڵ㹹��
		__list_iterator(node* node)
			:_node(node)
		{}
		//����ʵ�ָ�ֵ���������죬Ĭ�ϵ�ǳ�������ɡ�����ʵ��������Ĭ�ϵľͿ��ԣ��ܲ��ܰ��˼ҽڵ������˰ɣ�
		//���ڵ�����,�ڵ�ָ��ͬһ��λ�þ����,��ַ���
		bool operator!=(const self& s)const
		{
			return _node != s._node;
		}
		bool operator==(const self& s)const
		{
			return !(_node != s._node);
		}
		Ref operator*()const
		{
			return _node->_data;
		}
		//ptrΪT*,  _node->dataΪT����
		Ptr operator->()const
		{
			return &(_node->_data)
		}
		//ǰ��++
		self& operator++()
		{
			//ǰ��++��_node�Ѿ��ı�
			 _node=_node->_next;
			 return *this;
		}
		//����++
		self operator++(int)
		{
			
			self s(*this);
			_node = _node->_next;
			return s;

		}
		//ǰ��--
		self operator--()
		{
			_node = _node->_prev;
			return *this;
		}
		//����--
		self operator--(int)
		{
			self s(*this);
			_node = _node->_prev;
			return s;
		}
		
		node* _node;
	};
	//list����Ľṹ
	template<class T>
	class list
	{
		typedef __list_node<T> node;
	public:
		typedef __list_iterator<T,T&,T*> iterator;
		typedef __list_iterator<T, const T&, const T*> const_iterator;
//�������ӿ�
		iterator begin()
		{
			//��ʽ����ת���ɵ�������
			return _head->_next;
			//return iterator(_head->_next);
			//iterator it(_head->next)  return it;
		}
		
		iterator end()
		{
			//���һ���ڵ����һ��λ�ã���_head.
			return _head;
		}
		const_iterator begin()const
		{
			return _head->_next;
		}
		const_iterator end()const
		{
			return _head;
		}
//����ӿ�
		list()
		{
			//����ýڵ�Ĺ��캯����ʼ��
			_head = new node;
			_head->_next = _head;
			_head->_prev = _head;
			
		}
		//��������������
     template<class inputiterator>
	 list(inputiterator first, inputiterator last)
	 {
		 _head = new node;
		 _head->_next = _head;
		 _head->_prev = _head;

		 while (first != last)
		 {
			 push_back(*first);
			 ++first;
		 }
		 
	 }
		//�������죨�����
	    //�����ˣ���Ȼ������д��ֵ���������β�д�ɴ�ֵ���ã���д��ֵ����������ݹ���
		list(const list<T>& l)
		{
			//����ʼ��ͷ�ڵ㣬ֱ�Ӻͱ��˽������ͻᵼ��ִ��temp����������(���������ֵ)ʱ����
			_head = new node;
			_head->_next = _head;
			_head->_prev = _head;

			list<T> temp(l.begin(),l.end());
			std::swap(_head, temp._head);
		}

		//��ֵ����
		list<T>& operator=(list<T> l)
		{
		std::swap(_head,l.head);
		return *this;
		}
		
		~list()
		{
			clear();
			delete _head;
		}
		void clear()
		{
			iterator it = begin();
			while (it != end())
			{
				it=erase(it);
			}
		}
		//β��
		void push_back(const T& x)
		{
			//node* newnode = new node(x);
			//node* tail = _head->_prev;
			//tail->_next = newnode;
			//newnode->_prev = tail;

			//newnode->_next = _head;
			//_head->_prev = newnode;
			insert(end(),x);
		}
		void push_front(const T& x)
		{
			insert(begin(), x);
		}
		 // 1 2 3 4 
		void pop_back()
		{
			erase(--end());
		}
		void pop_front()
		{
			erase(begin());
		}
		//��pos֮ǰ����
		iterator insert(iterator pos,const T& x)
		{
			node* newnode = new node(x);
			node* cur = pos._node;
			node* prev = cur->_prev;
		
			prev->_next = newnode;
			newnode->_prev = prev;

			newnode->_next = cur;
			cur->_prev = newnode;

			//�����²����λ��
			return newnode;
			
		}
		//ɾ��
		iterator erase(iterator pos)
		{
			//����ɾͷ
			assert(pos != end());
			node* cur = pos._node;
			node* prev = cur->_prev;
			node* next = cur->_next;
			prev->_next = next;
			next->_prev = prev;
			delete cur;

			return next;
		}
	private:
		node* _head;
	};
}