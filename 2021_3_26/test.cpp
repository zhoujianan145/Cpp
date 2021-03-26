//#include<iostream>
//#include<assert.h>
//#pragma warning(disable:4996)
//using namespace std;
//
//namespace zjn
//{
//	class string
//	{
//	public:
//		
//		string(char* str="")
//			:_str(new char[strlen( str)+1])
//		{
//			strcpy(_str, str);
//		}
//		~string()
//		{
//			delete[] _str;
//			_str = nullptr;
//		}
//		const char* c_str()
//		{
//			return _str;
//		}
//		string(const string& s)
//			:_str(new char[strlen(s._str)+1])
//		{
//			strcpy(_str,s._str);
//		}
//		char&  operator[](size_t i)
//		{
//			assert(i < _size);
//			return _str[i];
//		}
//		string& operator=(const string& s)
//		{
//			if (this!=&s)
//			{
//				delete[] _str;
//				//不能直接strcpy因为空间可能不够
//				_str = new char[strlen(s._str) + 1];
//				strcpy(_str, s._str);
//			}
//			return *this;
//		}
//	private:
//		char* _str;
//	};
//}
//int main()
//{
//	zjn::string s1("1234");
//	zjn::string s2;
//	zjn::string s3(s1);
//	s3[1] = 'x';
//	cout << s1.c_str() << endl;
//	cout << s2.c_str ()<< endl;
//	return 0;
//}
#include"string.h"
void print(const zjn::string& s)
{
	zjn::string::const_iterator it = s.begin();
	while (it != s.end())
	{
		
		/**it = 'x';*/
		cout << *it;
		it++;
	}
	cout << endl;
}

int main()
{
	const char* a = "212";
	
	zjn::string s = ("1234");
	
	zjn::string s1(s);

	s1[2] = 's';
	s = s1;
	cout<<s1.size()<<endl;
	print(s);
	////原理就是迭代器
	//for (auto& e : s)
	//{
	//	e += 1;
	//}
	s += 'x';
	s += "hello world";
	
	print(s);
	
	return 0;
}