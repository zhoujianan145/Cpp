

#include<iostream>
#include<assert.h>
#include<algorithm>

namespace zjn
{
	//list节点的结构
	template<class T>
	struct __list_node
	{
		//形参这样写的原因是，万一T是自定义类型，list<string>
		__list_node(const T& x = T())
		:_prev(nullptr)
		, _next(nullptr)
		, _data(x)
		{}
		__list_node<T>* _prev;
		__list_node<T>* _next;
		T _data;
	};
	//list迭代器的结构
	//原生指针满足不了需求，所以需要自己写一个迭代器
	template<class T,class Ref,class Ptr>
	//在list插入操作时需要访问node来确定位置的前后节点，所以成员变量得是公有的
	struct __list_iterator
	{
		typedef __list_iterator<T,Ref,Ptr> self;
		typedef __list_node<T> node;
         
		//节点构造
		__list_iterator(node* node)
			:_node(node)
		{}
		//不用实现赋值，拷贝构造，默认的浅拷贝即可。不用实现析构，默认的就可以（总不能把人家节点析构了吧）
		//对于迭代器,节点指向同一个位置就相等,地址相等
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
		//ptr为T*,  _node->data为T类型
		Ptr operator->()const
		{
			return &(_node->_data)
		}
		//前置++
		self& operator++()
		{
			//前置++，_node已经改变
			 _node=_node->_next;
			 return *this;
		}
		//后置++
		self operator++(int)
		{
			
			self s(*this);
			_node = _node->_next;
			return s;

		}
		//前置--
		self operator--()
		{
			_node = _node->_prev;
			return *this;
		}
		//后置--
		self operator--(int)
		{
			self s(*this);
			_node = _node->_prev;
			return s;
		}
		
		node* _node;
	};
	//list链表的结构
	template<class T>
	class list
	{
		typedef __list_node<T> node;
	public:
		typedef __list_iterator<T,T&,T*> iterator;
		typedef __list_iterator<T, const T&, const T*> const_iterator;
//迭代器接口
		iterator begin()
		{
			//隐式类型转化成迭代器。
			return _head->_next;
			//return iterator(_head->_next);
			//iterator it(_head->next)  return it;
		}
		
		iterator end()
		{
			//最后一个节点的下一个位置，即_head.
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
//构造接口
		list()
		{
			//会调用节点的构造函数初始化
			_head = new node;
			_head->_next = _head;
			_head->_prev = _head;
			
		}
		//迭代器拷贝构造
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
		//拷贝构造（深拷贝）
	    //忘记了，竟然还想想写赋值重载那样形参写成传值调用，你写传值就引发无穷递归了
		list(const list<T>& l)
		{
			//不初始化头节点，直接和别人交换，就会导致执行temp的析构函数(析构了随机值)时崩溃
			_head = new node;
			_head->_next = _head;
			_head->_prev = _head;

			list<T> temp(l.begin(),l.end());
			std::swap(_head, temp._head);
		}

		//赋值重载
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
		//尾插
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
		//在pos之前插入
		iterator insert(iterator pos,const T& x)
		{
			node* newnode = new node(x);
			node* cur = pos._node;
			node* prev = cur->_prev;
		
			prev->_next = newnode;
			newnode->_prev = prev;

			newnode->_next = cur;
			cur->_prev = newnode;

			//返回新插入的位置
			return newnode;
			
		}
		//删除
		iterator erase(iterator pos)
		{
			//不能删头
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