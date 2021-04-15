#pragma once
#include<iostream>
#include<assert.h>
#include<algorithm>
namespace zjn
{
	template <class T>
	class vector
	{
		
	public:
		typedef T* iterator;
		typedef const T* const_iterator;
		iterator begin()
		{
			return _start;
		}
		iterator end()
		{
			return _finish;
		}
		const_iterator begin()const
		{
			return _start;
		}
		const_iterator end()const
		{
			return _finish;
		}
		void swap(vector<T>& v)
		{
			std::swap(_start, v._start);
			std::swap(_finish, v._finish);
			std::swap(_end_of_stage, v._end_of_stage);
		}
		vector()
			:_start(nullptr)
			,_finish(nullptr)
			, _end_of_stage(nullptr)
		{}

		template <class Inputiterator>
		vector(Inputiterator first,Inputiterator last)
			: _start(nullptr)
			, _finish(nullptr)
			, _end_of_stage(nullptr)
		{
			reserve(last - first);
			while (first != last)
			{
				push_back(*first);
				first++;
			}
		}
		//�������죬�ִ�д��
		vector(const vector<T>& v)
			:_start(nullptr)
			, _finish(nullptr)
			, _end_of_stage(nullptr)
		{
			vector<T> temp(v.begin(), v.end());
			swap(temp);
		}
		//��ֵ���أ��ִ�д��
		vector<T>& operator=(vector<T> v)
		{
			swap(v);
			return *this;
		}
		~vector()
		{
			delete[] _start;
			_start = _finish = _end_of_stage=nullptr;
		}
	
		
		const size_t size()const
		{
			return _finish - _start;
		}
		const size_t capacity()const
		{
			return _end_of_stage - _start;
		}
		T& operator[](size_t pos)
		{
			assert(pos < size());
			return _start[pos];
		}
		const T& operator[](size_t ops)const
		{
			assert(pos < size());
			return _start[pos];
		}
		//����
		void reserve(size_t n)
		{
			if (n > capacity())
			{
				T* temp = new T[n];

				//memcpy(temp,_start,sizeof(T)*size());memcpyΪǳ������vector<int>û�����⣬vector<string>������ʱ��ᱨ��
				for (size_t i = 0; i < size(); i++)
				{
					temp[i] = _start[i];
				}
				size_t oldsize = size();
				delete[] _start;
				
				_start = temp;
				_finish = _start + oldsize;
				//_finish = _start + size();��ʱ���ܵ���size()��finsh����ָ���ǿ��ͷŵĿռ�
				_end_of_stage = _start + n;
			}
		}
		//����+��ʼ������Сsize
		//resize���˸�ȱʡֵ����Ϊ��������������Ҫ��const
		void resize(size_t n, const T& x=T())
		{
			//���粻���ͻ�����
			if (n > capacity())
			{
				reserve(n);
			}
			//����n<size()������С�ռ�
			if (n < size())
			{
				_finish = _start + n;
			}
			else{

			   //����n>size()�Ͱ�x��ֵ��ȥ
				while (_finish != _start + n)
				{
					*_finish = x;
					_finish++;
				}
			}
			
		}
		void check_capacity()
		{
			if (_end_of_stage == _finish)
			{
				size_t newcapacity = capacity() == 0 ? 4 : capacity() * 2;
				reserve(newcapacity);
			}
		}
		void push_back(const T& x)
		{
			//check_capacity();
			//*_finish= x;
			//_finish++;
			insert(_finish,x);
		}
		void pop_back()
		{
			--_finish;
			return 0;
		}
		//�����ǵ����������findʹ��
		iterator insert(iterator pos, const T& x)
		{
			assert(pos<=_finish && pos>=_start);
			//�������ݻ����������ʧЧ�������ؿ�һ�οռ䣬����pos����ָ���ͷŵĿռ�
			//��ǰ��¼posi��ֵ�����ݵĻ���_start+posi�����ҵ���pos��λ��
			size_t posi = pos - _start;
			check_capacity();
			
			pos = _start + posi;
			iterator end = _finish - 1;
			while (end >= pos)
			{
				*(end + 1) = *end;
				end--;
			}
			*pos = x;
			++_finish;
			return pos;
		}
		//���ص�pos����һ��λ��(Ųǰ����)
		iterator erase(iterator pos)
		{
			assert(pos < _finish && pos >= _start);
			iterator it=pos+1;
			while (it != finish)
			{
				*(it - 1) = *it;
				it++;
			}
			--finish;
			return pos;
		}
	private:
		iterator _start;
		iterator _finish;
		iterator _end_of_stage;

	};

}
