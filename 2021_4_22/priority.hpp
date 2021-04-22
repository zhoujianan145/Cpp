#pragma once
#include<iostream>
#include<vector>
#include<assert.h>
#include<queue>
using namespace std;
namespace zjn{
	template<class T>
	class less{
	public:
		bool operator()(const T& x,const T& y)
		{
			return x > y;
		}
	};
	template<class T>
	class greater{
	public:
		bool operator()(const T& x, const T& y)
		{
			return x < y;
		}
	};
	template<class T, class Container = vector<T>,class Compare=less<T>>
	class priority_queue
	{
	public:
		//写了有区间的，不会默认生成了，所以要再写一个无参的
		priority_queue()
		{};
		//对于已有的一段区间进行构造优先级队列,两种方法
		template<class iterator>
		priority_queue(iterator first, iterator last)
			:_Con(first,last)
		{
			for (int i = ((_Con.size() - 1-1)/2); i >=0; i--)
			{
				AdjustDown(i);
			}
			//for (int i = 1; i < _Con.size(); i++)
			//{
			//	AdjustUp(i);
			//}
		}
		//从下往上，和父亲开始比较
		void AdjustUp(int child)
		{
			//传的是模板，从而实现，实例化对象时传入不同的比较类，实现大堆小堆。
			//greater com,less com
			Compare com;
			//找出父亲
			int parent = (child - 1) / 2;
			//本来应该是当孩子小于等于0时，父亲小于0停止，但是由于父亲是除法算出来的不会小于0，那就让孩子小于等于0时停止(孩子大于0继续)
			while (child>0)
			{
				//如果孩子比父亲大，那么就交换
				//if(_Con[child]>_Con[parent])
				if (com(_Con[child],_Con[parent]))
				{
					swap(_Con[child], _Con[parent]);
					//向上继续迭代
					child = parent;
					parent = (child - 1) / 2;
				}
				//孩子小于父亲说明插入的数据刚好满足，退出
				else
				{
					break;
				}

			}
		}
		void push(const T& x)
		{
			//堆尾插入x
			_Con.push_back(x);
			//传下标，把孩子调整上去
			AdjustUp(_Con.size() - 1);
		}
		//从上往下，父亲和大的那一个孩子比较
		void AdjustDown(int parent)
		{
			Compare com;
			//默认是左孩子
			size_t child = parent * 2 + 1;

			while (child<_Con.size())
			{
				//左右孩子大的那一个和父亲比较,注意当堆尾只有一个左孩子时，虽然child<size进入循环，但是他没有右孩子会导致越界

				if (child + 1<_Con.size() && com(_Con[child + 1], _Con[child]))
				{
					child++;
				}
				if (com(_Con[child], _Con[parent]))
				{
					swap(_Con[child], _Con[parent]);
					//向下继续迭代
					parent = child;
					child = parent * 2 + 1;

				}
				else
				{
					break;
				}
			}
		}
		//删除堆顶
		void pop()
		{
			assert(size() > 0);
			//堆顶和堆尾交换
			swap(_Con[0], _Con[_Con.size() - 1]);
			//尾删
			_Con.pop_back();
			//堆顶是原先堆尾的数据，除了他其他结构并未变化，可以使用向下调整
			AdjustDown(0);
		}
		const T& top()const
		{
			/*return _Con.top();*/
			return _Con[0];
		}
		size_t size()const
		{
			return _Con.size();
		}
		bool empty()const
		{
			return _Con.empty();
		}


	private:
		Container _Con;

	};
	void test()
	{
		zjn::priority_queue<int> pq;
		pq.push(2);
		pq.push(5);
		pq.push(7);
		pq.push(4);
		pq.push(6);
		pq.push(8);
		while (!pq.empty())
		{
			int val = pq.top();
			cout << val << " ";
			pq.pop();
		}
		cout << endl;
	}
}
