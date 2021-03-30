#include<iostream>
#include<assert.h>

namespace zjn{
	class string
	{
	public:
	/*	typedef char* iterator;
		typedef const char* const_iterator;

		iterator begin()
		{
			return _str;
		}

		iterator end()
		{
			return _str + _size;
		}

		const_iterator begin() const
		{
			return _str;
		}

		const_iterator end() const
		{
			return _str + _size;
		}*/
		//ÏÖ´úÐ´·¨
		string(const char* str="")
		{
		/*	_str = new char[strlen(str)+1];
			strcpy(_str,str);
			_size = strlen(str);
			_capacity = _size;*/
			_size = strlen(str);
			_capacity = _size;
			_str = new char[_size + 1];
			strcpy(_str, str);


		}
		
		// s1.swap(s2)
		void swap(string& s)
		{
			std::swap(_str, s._str);
			std::swap(_size, s._size);
			std::swap(_capacity, s._capacity);
		}

		// s2(s1)
		string(const string& s)
			:_str(nullptr)
			, _capacity(0)
			, _size(0)
		{
			string tmp(s._str);
			//this->swap(tmp);
			swap(tmp);
		}

	    
		~string()
		{
			delete[] _str;
			_str = nullptr;
			_capacity = _size=0;
		}

	private:
		char* _str;
		size_t _size;
		size_t _capacity;

	};


}