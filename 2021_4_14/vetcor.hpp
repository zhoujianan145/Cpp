#pragma once
#include<iostream>

namespace zjn
{
	template <class T>
	class vector
	{
		
	public:
		typedef T* iterator;
		vector()
			:_start(nullptr)
			: _finish(nullptr)
			: _end_of_stage(nullptr)
		{}
		~vector()
		{
			delete[] _start;
			_strat = _finish = _end_of_stage=nullptr;
		}
		const size_t size()const
		{
			return _finish - _start;
		}
		const size_t capacity()const
		{
			return _end_of_stage - _start;
		}
		void reserve(size_t n)
		{
			if (n > capacity())
			{
				T* temp = new T[n];
				memcpy(temp,_start,sizeof(T)*size());
				for (int i = 0; i < size(); i++)
				{
					temp[i] = _strat[i];
				}
				delete[] _start;
				
				_start = temp;

				//_finish = _start + size();此时不能调用size()，finsh还在指向那块释放的空间
				
			}
		}
		void check_capacity()
		{
			if (_end_of_stage == _finsh)
			{
				size_t newcapacity = capacity() == 0 ? 4 : capacity() * 2;
				reserve(newcapacity);
			}
		}
		void push_back(const T& x)
		{
			check_capacity();
			*_finsh = x;
			_finish++;
		}
	private:
		iterator _start;
		iterator _finsh;
		iterator _end_of_stage;

	};

}
