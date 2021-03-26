#include<iostream>
#include<assert.h>
#pragma warning(disable:4996)
using namespace std;

namespace zjn
{
	class string
	{
	public:
		//参数列表最好不要写有依赖关系的，因为实际初始化的顺序只和声明的顺序有关
		/*string(char* str)
			:_str(new char[strlen(str)+1])
			,_size(strlen( str))
			, _capacity(_size)
		{}*/
		string(char* str="")
		{
			_str=new char[strlen(str)+1];
			_size = strlen(str);
			_capacity = _size;
			strcpy(_str, str);
		}
		string(const string& s)
		{
			_size = s._size;
			_capacity = s._capacity;
			_str = new char[strlen(s._str) + 1];
			strcpy(_str, s._str);
		}
		~string()
		{
			delete[] _str;
			_str = nullptr;
		}
		
		char& operator[](size_t i)
		{
			assert(i < _size);
			return _str[i];
		}
		string& operator=(const string& s)
		{

			if (this != &s){
				delete[] _str;
              _str = new char[strlen(s._str) + 1];
			  strcpy(_str, s._str);
			  _capacity = s._capacity;
			  _size = s._size;
			}
			return *this;
		}
		size_t size()
		{
			return _size;
		}
		typedef char* iterator;
		typedef const char* const_iterator;
		iterator begin()
		{
			return _str;
		}
		//  1 2 3 4 5 \0
		iterator end()
		{
			//到\0停止
			return _str + _size;
		}
		const_iterator begin()const
		{
			return _str;
		}
		const_iterator end()const
		{
			//到\0停止
			return _str + _size;
		}
		void reserve(size_t n)
		{
			if (n > _capacity)
			{
				char* p = new char[n];
				strcpy(p, _str);
				delete[] _str;
				_str = p;
				_capacity = n;
			}
		}
		void Push_back(char ch)
		{
			if (_size == _capacity)
			{
				reserve(2 * _capacity);
				_str[_size] = ch;
				_size++;
				_str[_size] = '\0';
			}
		}
		void append(char ch)
		{
			Push_back(ch);
		}
		void append(const char* s)
		{
			size_t len=strlen(s);
			if (len + _size > _capacity)
			{
				reserve(len + _size);
			}
			strcpy(_str+_size, s);
			_size+= len ;
			_str[_size] = '\0';

		}
		void append(const string& s)
		{
			size_t len=strlen(s._str);
			if (len + _size > _capacity)
			{
				reserve(len + _size);
			}
			strcpy(_str + len, s._str);
			_size += len;
			_str[_size] = '\0';
		}
		string& operator+=(char ch)
		{
			Push_back(ch);
			return *this;
		}
		string& operator+=(const char* s)
		{
			append(s);
			return *this;
		}
		string& operator+=(const string& s)
		{
			append(s);
			return *this;
		}
	private:
		char* _str;
		size_t _size;
		size_t _capacity;
	};


}
