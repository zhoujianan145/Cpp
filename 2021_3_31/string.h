#include<iostream>
#include<assert.h>

#pragma warning(disable:4996)


namespace zjn
{
	class string
	{
	public:
		//传统写法
		////构造
		//string(const char* str = "")
		//{
		//	_size = strlen(str);
		//	_capacity = _size;
		//	_str = new char[_capacity + 1];
		//	strcpy(_str, str);
		//}
		////析构
		//~string()
		//{
		//	delete[] _str;
		//	_str = nullptr;
		//	_capacity = _size = 0;
		//}
		////拷贝构造
		//string(const string& s)
		//{
		//	_str = new char[strlen(s._str) + 1];
		//	strcpy(_str, s._str);
		//	_capacity = s._capacity;
		//	_size = s._size;
		//}
		////赋值重载
		//string& operator=(const string& s)
		//{
		//	if (this != &s)
		//	{
		//		delete[] _str;
		//		_str = new char[strlen(s._str) + 1];
		//		strcpy(_str, s._str);
		//		_size = s._size;
		//		_capacity = s._capacity;
		//	}
		//	return *this;
		//}
		//构造
		string(const char* str = "")
		{
			_size = strlen(str);
			_capacity = _size;
			_str = new char[_size + 1];
			strcpy(_str, str);
		}

		 //std中的swap并不好
		void swap(string& s)
		{
			std::swap(_str, s._str);
			std::swap(_size, s._size);
			std::swap(_capacity, s._capacity);
		}

		//拷贝构造
		//string s1(s2);
		string(const string& s)
			:_str(nullptr)
			, _capacity(0)
			, _size(0)
		{
			string temp(s._str);
			swap(temp);

		}
		//析构
		~string()
		{
			delete[] _str;
			_str = nullptr;
			_capacity = _size = 0;
		}
		//赋值
		string& operator=(string s)
		{
			swap(s);
			return *this;
		}
		size_t size()const
		{
			return _size;
		}
		//重载[]
		//返回值忘记引用了
		
		char& operator[](size_t i)
		{
			assert(i < _size);
			return _str[i];
		}
		const char& operator[](size_t i)const
		{
			assert(i < _size);
			return _str[i];
		}
		typedef char* iterator;
		iterator begin()
		{
			return _str;
		}
		iterator end()
		{
			return _str + _size;
		}
		typedef const char* const_iterator;
		const_iterator begin()const
		{
			return _str;
		}
		const_iterator end()const
		{
			return _str + _size;
		}
		//增
		//扩容+初始化。
		//当前n<capacity的话，不改变capacity，只改变size。n>capacity，改变size改变capacity。
			void resize(size_t n, char ch='\0')
			{
			
				//_size变小，capacity不变，直接在n处放'\0'
			if (n<_size)
			{
			_str[n] ='\0';
			_size = n;
			}
			else
			{
				if (n>_capacity)
				{
					reserve(n);
				}
				//1 2 3 4 
				for (size_t i = _size; i < n; i++)
				{
					_str[i] = ch;
					
				}
				_str[n] = '\0';
				_size = n;
				
			}
			}
		//扩容
		void reserve(size_t  n)
		{
			if (n > _capacity)
			{
				//需要temp不然直接delete的话字符串的内容会丢失
				char* temp = new char[n + 1];
				strcpy(temp, _str);
				delete[] _str;
				_str = temp;
				_capacity = n;
			}
		}
		//字符尾插
		void push_back(char ch)
		{
			/*if (_size == _capacity)
			{
			reserve(2 * _capacity);
			}
			_str[_size] = ch;
			_size++;
			_str[_size] = '\0';*/
			insert(_size, ch);

		}
		void append(const char* str)
		{
			//int len = strlen(str);
			//if (len + _size> _capacity)
			//{
			//	reserve(len + _size);
			//}
			////忘记strcpy,参数忘记+_size
			//strcpy(_str+_size, str);
			//_size += len;
			insert(_size, str);

		}
		//字符+=
		string& operator+=(char ch)
		{
			push_back(ch);
			return *this;
		}
		//字符串+=,参数忘记const
		string& operator+=(const char* str)
		{
			append(str);
			return *this;

		}
		//string对象+=
	    string& operator+=(const string& s)
		{
			append(s._str);
			return *this;
		}
		//插入字符
		void insert(size_t pos, char ch)
		{
			assert(pos <= _size);
			if (_size == _capacity)
			{
				size_t newcapacity = _capacity == 0 ? 8 : 2 * _capacity;
				reserve(newcapacity);
			}
			/*	逻辑没有问题，但是当pos等于0时，要把第一位往前挪，end--就会变成-1，才能由于类型为size_t他就会变为整形最大值。
				假如把end变为int类型也避免不了，因为pos为size_t,身为int类型的end会类型提升为size_t,依旧是整形最大值。
				那把end变成int类型，再把pos显示的转为int(pos不要直接改成int与库不相符)，这样是可以的。
				size_t end = _size;
				while(end>=pos)
				{
				_str[end + 1] = _str[end];
				end--;
				}*/
			//虽然_size是'\0',但是_size+1不会越界因为假如空间不够前面会扩容，数组是有这么大空间的，只不过没有存字符。
			//这样当pos等于0时，end为1字符已经全部挪走，end--为0，此时不会再进入循环，也就不会变成-1了。
			size_t end = _size + 1;
			while (end > pos)
			{
				_str[end] = _str[end - 1];
				end--;
			}
			_str[pos] = ch;
			_size++;
			

		}
		//插入字符串
		void insert(size_t pos, const char* str)
		{
			assert(pos <= _size);
			int len = strlen(str);
			if (_size + strlen(str) > _capacity)
			{
				reserve(_size + len);
			}
			int end = _size + len;
			//画图分析
			//避免整形提升
			while (end >= (int)pos + len)
			{
				_str[end] = _str[end - len];
				end--;
			}
			strncpy(_str + pos, str, len);
			_size += len;
			

		}
		//删除，和库类似，我们给一个npos缺省值
		void erase(size_t pos, size_t len = npos)
		{
			//从pos起，删除len个字符。
			assert(pos < _size);
			//len为npos的时候会溢出
			//if (pos+len>_size)
			//
			//假如要求删的超过字符串，a b c d,要求从c删除100个，就把d置成'\0'就行了。
			if (len == npos || pos + len >= _size)
			{
				_str[pos] = '\0';
				_size = pos;
			}
			else
			{
				//直接拷过去，然后覆盖，'\0'也会拷贝过去
				strcpy(_str + pos, _str + pos + len);
				_size -= len;
			}

		}
		//查找字符，缺省默认从第一个位置开始
		size_t find(char ch, size_t pos = 0)
		{
			for (size_t i = 0; i < _size; i++)
			{
				if (ch == _str[i])
				{
					return i;
				}
			}
			return npos;
		}
		//查找子串
		size_t find(const char* sub, size_t pos = 0)
		{
			//在_str+pos这个字符串里找sub
			const char* ret = strstr(_str + pos, sub);
			if (nullptr == ret)
			{
				return npos;
			}
			else
			{
				return ret - _str;
			}
		}


	private:
		char* _str;
		size_t _capacity;
		size_t _size;
		//声明
		static const size_t npos;
	};
	//定义初始化
	const size_t string::npos = -1;
	//大于重载
	bool operator>(const string& s1, const string& s2)
	{
		size_t l1=0, l2 = 0;
		while (l1 < s1.size() && l2 < s2.size())
		{
			if (s1[l1] == s1[l2])
			{
				l1++;
				l2++;
			}
			else
			{
				if (s1[l1]>s2[l2])
				{
					return true;
				}
				else
				{
					return false;
				}
			}
		}
		//假如有一个长一个短
		if (l1 < s1.size())
		{
			return true;
		}
		else if (l2 < s2.size())
		{
			return false;
		}
		else
		{
			return false;
		}
	}
	//==重载
	bool operator==(const string& s1, const string& s2)
	{
		size_t l1 = 0, l2 = 0;
		while (l1 < s1.size() && l2 < s2.size())
		{
			if (s1[l1] == s1[l2])
			{
				l1++;
				l2++;
			}
			else
			{
				return false;
			}
		}
		//假如有一个长一个短
		if (l1 < s1.size())
		{
			return false;
		}
		else if (l2 < s2.size())
		{
			return false;
		}
		else
		{
			return true;
		}

	}
	//输出
	std::ostream& operator<<(std::ostream& out, const string& s)
	{
		for (size_t i = 0; i < s.size(); i++)
		{
			out << s[i] ;
		}
		return out;

	}
	//输入
	std::istream& operator>>(std::istream& in,  string& s)
	{
		s.resize(0);
		char ch;
		while (1)
		{
			//这样不行，默认空格为下一个，不能123这样输，只能1 2 3
			//in >> ch;
			in.get(ch);
			if ( ch==' '||ch=='\n')
			{
				break;
			}
			else
			{
				s += ch;
			}
		}
		return in;
	}
	
}