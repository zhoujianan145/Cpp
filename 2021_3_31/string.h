#include<iostream>
#include<assert.h>

#pragma warning(disable:4996)


namespace zjn
{
	class string
	{
	public:
		//��ͳд��
		////����
		//string(const char* str = "")
		//{
		//	_size = strlen(str);
		//	_capacity = _size;
		//	_str = new char[_capacity + 1];
		//	strcpy(_str, str);
		//}
		////����
		//~string()
		//{
		//	delete[] _str;
		//	_str = nullptr;
		//	_capacity = _size = 0;
		//}
		////��������
		//string(const string& s)
		//{
		//	_str = new char[strlen(s._str) + 1];
		//	strcpy(_str, s._str);
		//	_capacity = s._capacity;
		//	_size = s._size;
		//}
		////��ֵ����
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
		//����
		string(const char* str = "")
		{
			_size = strlen(str);
			_capacity = _size;
			_str = new char[_size + 1];
			strcpy(_str, str);
		}

		 //std�е�swap������
		void swap(string& s)
		{
			std::swap(_str, s._str);
			std::swap(_size, s._size);
			std::swap(_capacity, s._capacity);
		}

		//��������
		//string s1(s2);
		string(const string& s)
			:_str(nullptr)
			, _capacity(0)
			, _size(0)
		{
			string temp(s._str);
			swap(temp);

		}
		//����
		~string()
		{
			delete[] _str;
			_str = nullptr;
			_capacity = _size = 0;
		}
		//��ֵ
		string& operator=(string s)
		{
			swap(s);
			return *this;
		}
		size_t size()const
		{
			return _size;
		}
		//����[]
		//����ֵ����������
		
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
		//��
		//����+��ʼ����
		//��ǰn<capacity�Ļ������ı�capacity��ֻ�ı�size��n>capacity���ı�size�ı�capacity��
			void resize(size_t n, char ch='\0')
			{
			
				//_size��С��capacity���䣬ֱ����n����'\0'
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
		//����
		void reserve(size_t  n)
		{
			if (n > _capacity)
			{
				//��Ҫtemp��Ȼֱ��delete�Ļ��ַ��������ݻᶪʧ
				char* temp = new char[n + 1];
				strcpy(temp, _str);
				delete[] _str;
				_str = temp;
				_capacity = n;
			}
		}
		//�ַ�β��
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
			////����strcpy,��������+_size
			//strcpy(_str+_size, str);
			//_size += len;
			insert(_size, str);

		}
		//�ַ�+=
		string& operator+=(char ch)
		{
			push_back(ch);
			return *this;
		}
		//�ַ���+=,��������const
		string& operator+=(const char* str)
		{
			append(str);
			return *this;

		}
		//string����+=
	    string& operator+=(const string& s)
		{
			append(s._str);
			return *this;
		}
		//�����ַ�
		void insert(size_t pos, char ch)
		{
			assert(pos <= _size);
			if (_size == _capacity)
			{
				size_t newcapacity = _capacity == 0 ? 8 : 2 * _capacity;
				reserve(newcapacity);
			}
			/*	�߼�û�����⣬���ǵ�pos����0ʱ��Ҫ�ѵ�һλ��ǰŲ��end--�ͻ���-1��������������Ϊsize_t���ͻ��Ϊ�������ֵ��
				�����end��Ϊint����Ҳ���ⲻ�ˣ���ΪposΪsize_t,��Ϊint���͵�end����������Ϊsize_t,�������������ֵ��
				�ǰ�end���int���ͣ��ٰ�pos��ʾ��תΪint(pos��Ҫֱ�Ӹĳ�int��ⲻ���)�������ǿ��Եġ�
				size_t end = _size;
				while(end>=pos)
				{
				_str[end + 1] = _str[end];
				end--;
				}*/
			//��Ȼ_size��'\0',����_size+1����Խ����Ϊ����ռ䲻��ǰ������ݣ�����������ô��ռ�ģ�ֻ����û�д��ַ���
			//������pos����0ʱ��endΪ1�ַ��Ѿ�ȫ��Ų�ߣ�end--Ϊ0����ʱ�����ٽ���ѭ����Ҳ�Ͳ�����-1�ˡ�
			size_t end = _size + 1;
			while (end > pos)
			{
				_str[end] = _str[end - 1];
				end--;
			}
			_str[pos] = ch;
			_size++;
			

		}
		//�����ַ���
		void insert(size_t pos, const char* str)
		{
			assert(pos <= _size);
			int len = strlen(str);
			if (_size + strlen(str) > _capacity)
			{
				reserve(_size + len);
			}
			int end = _size + len;
			//��ͼ����
			//������������
			while (end >= (int)pos + len)
			{
				_str[end] = _str[end - len];
				end--;
			}
			strncpy(_str + pos, str, len);
			_size += len;
			

		}
		//ɾ�����Ϳ����ƣ����Ǹ�һ��nposȱʡֵ
		void erase(size_t pos, size_t len = npos)
		{
			//��pos��ɾ��len���ַ���
			assert(pos < _size);
			//lenΪnpos��ʱ������
			//if (pos+len>_size)
			//
			//����Ҫ��ɾ�ĳ����ַ�����a b c d,Ҫ���cɾ��100�����Ͱ�d�ó�'\0'�����ˡ�
			if (len == npos || pos + len >= _size)
			{
				_str[pos] = '\0';
				_size = pos;
			}
			else
			{
				//ֱ�ӿ���ȥ��Ȼ�󸲸ǣ�'\0'Ҳ�´����ȥ
				strcpy(_str + pos, _str + pos + len);
				_size -= len;
			}

		}
		//�����ַ���ȱʡĬ�ϴӵ�һ��λ�ÿ�ʼ
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
		//�����Ӵ�
		size_t find(const char* sub, size_t pos = 0)
		{
			//��_str+pos����ַ�������sub
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
		//����
		static const size_t npos;
	};
	//�����ʼ��
	const size_t string::npos = -1;
	//��������
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
		//������һ����һ����
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
	//==����
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
		//������һ����һ����
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
	//���
	std::ostream& operator<<(std::ostream& out, const string& s)
	{
		for (size_t i = 0; i < s.size(); i++)
		{
			out << s[i] ;
		}
		return out;

	}
	//����
	std::istream& operator>>(std::istream& in,  string& s)
	{
		s.resize(0);
		char ch;
		while (1)
		{
			//�������У�Ĭ�Ͽո�Ϊ��һ��������123�����䣬ֻ��1 2 3
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