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
		//拷贝构造，现代写法
		vector(const vector<T>& v)
			:_start(nullptr)
			, _finish(nullptr)
			, _end_of_stage(nullptr)
		{
			vector<T> temp(v.begin(), v.end());
			swap(temp);
		}
		//赋值重载，现代写法
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
		//扩容
		void reserve(size_t n)
		{
			if (n > capacity())
			{
				T* temp = new T[n];

				//memcpy(temp,_start,sizeof(T)*size());memcpy为浅拷贝。vector<int>没有问题，vector<string>析构的时候会报错
				for (size_t i = 0; i < size(); i++)
				{
					temp[i] = _start[i];
				}
				size_t oldsize = size();
				delete[] _start;
				
				_start = temp;
				_finish = _start + oldsize;
				//_finish = _start + size();此时不能调用size()，finsh还在指向那块释放的空间
				_end_of_stage = _start + n;
			}
		}
		//扩容+初始化，缩小size
		//resize给了个缺省值，因为是匿名对象，所以要带const
		void resize(size_t n, const T& x=T())
		{
			//假如不够就会扩容
			if (n > capacity())
			{
				reserve(n);
			}
			//假如n<size()，就缩小空间
			if (n < size())
			{
				_finish = _start + n;
			}
			else{

			   //假如n>size()就把x赋值进去
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
		//参数是迭代器，配合find使用
		iterator insert(iterator pos, const T& x)
		{
			assert(pos<=_finish && pos>=_start);
			//假如扩容会引起迭代器失效，增容重开一段空间，导致pos还在指向释放的空间
			//提前记录posi的值，扩容的话让_start+posi就又找到了pos的位置
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
		//返回的pos的下一个位置(挪前来了)
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
