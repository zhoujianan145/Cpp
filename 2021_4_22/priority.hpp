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
		//д��������ģ�����Ĭ�������ˣ�����Ҫ��дһ���޲ε�
		priority_queue()
		{};
		//�������е�һ��������й������ȼ�����,���ַ���
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
		//�������ϣ��͸��׿�ʼ�Ƚ�
		void AdjustUp(int child)
		{
			//������ģ�壬�Ӷ�ʵ�֣�ʵ��������ʱ���벻ͬ�ıȽ��࣬ʵ�ִ��С�ѡ�
			//greater com,less com
			Compare com;
			//�ҳ�����
			int parent = (child - 1) / 2;
			//����Ӧ���ǵ�����С�ڵ���0ʱ������С��0ֹͣ���������ڸ����ǳ���������Ĳ���С��0���Ǿ��ú���С�ڵ���0ʱֹͣ(���Ӵ���0����)
			while (child>0)
			{
				//������ӱȸ��״���ô�ͽ���
				//if(_Con[child]>_Con[parent])
				if (com(_Con[child],_Con[parent]))
				{
					swap(_Con[child], _Con[parent]);
					//���ϼ�������
					child = parent;
					parent = (child - 1) / 2;
				}
				//����С�ڸ���˵����������ݸպ����㣬�˳�
				else
				{
					break;
				}

			}
		}
		void push(const T& x)
		{
			//��β����x
			_Con.push_back(x);
			//���±꣬�Ѻ��ӵ�����ȥ
			AdjustUp(_Con.size() - 1);
		}
		//�������£����׺ʹ����һ�����ӱȽ�
		void AdjustDown(int parent)
		{
			Compare com;
			//Ĭ��������
			size_t child = parent * 2 + 1;

			while (child<_Con.size())
			{
				//���Һ��Ӵ����һ���͸��ױȽ�,ע�⵱��βֻ��һ������ʱ����Ȼchild<size����ѭ����������û���Һ��ӻᵼ��Խ��

				if (child + 1<_Con.size() && com(_Con[child + 1], _Con[child]))
				{
					child++;
				}
				if (com(_Con[child], _Con[parent]))
				{
					swap(_Con[child], _Con[parent]);
					//���¼�������
					parent = child;
					child = parent * 2 + 1;

				}
				else
				{
					break;
				}
			}
		}
		//ɾ���Ѷ�
		void pop()
		{
			assert(size() > 0);
			//�Ѷ��Ͷ�β����
			swap(_Con[0], _Con[_Con.size() - 1]);
			//βɾ
			_Con.pop_back();
			//�Ѷ���ԭ�ȶ�β�����ݣ������������ṹ��δ�仯������ʹ�����µ���
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
