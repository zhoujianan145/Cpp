////#include<iostream>
////#include<string>
////using namespace std;
////
//////class person
//////{
//////public:
//////	person(string str="Tom")
//////		:_name( str)
//////	{}
//////	void pprint()
//////	{
//////		cout << _name << endl;
//////	}
//////
//////public:
//////	string _name;
//////};
//////
//////class student :public person
//////{
//////public:
//////	student(int num=123)
//////		:_number(num)		
//////	{}
//////	void sprint()
//////	{
//////		/*cout << _name << endl;*/
//////		cout << _number << endl;
//////	}
//////private:
//////	int _number;
//////};
//////void print(person& p)
//////{
//////	cout << p._name << endl;
//////}
//////int main()
//////{
//////	//person p;
//////	//student s;
//////	//s._name = "jerry";
//////
//////	//p.pprint();
//////	//s.pprint();
//////
//////	//p = s;
//////	//print(p);
//////	//print(s);
//////	//
//////	person p;
//////	student s;
//////	
//////	person* ptr1 = &p;
//////	person& ref1 = p;
//////
//////	person* ptr2 = &s;
//////	person& ref2 = s;
//////
//////	student* ptr3 = (student*)ptr2;
//////	student& ref3 = (student&)ref2;
//////
//////	//不允许，越界风险
//////	//student* ptr4 = (student*)ptr1;
//////	//student& ref4 = (student&)ref1;
//////
//////	return 0;
//////}
////class person
////{
////public:
////	person(const string& s = "Tom")
////		:_name(s)
////	{}
////	person(const person& p)
////		:_name(p._name)
////	{}
////	person& operator=(const person& p)
////	{
////		if (this != &p)
////		{
////			_name = p._name;
////		}
////		return *this;
////	}
////	~person()
////	{
////		cout << "~person" << endl;
////	}
////protected:
////	string _name;
////
////};
////
////class student:public person
////{
////public:
////	student(const string& str="jerry",int num=123)
////		:person(str)
////		, _num(num)
////	{}
////	student(const student& s)
////		:person(s)//切片
////		, _num(s._num)
////	{}
////	student& operator=(const student& s)
////	{
////		if (this != &s)
////		{
////			//构成隐藏，显示的调用父类的不然就递归了
////			person::operator=(s);
////			_num = s._num;
////		}
////		return *this;
////	}
////	~student()
////	{
////		person::~person();
////	}
////protected:
////	int _num;
////
////};
////
////int main()
////{
////	student* s=new student();
////
////	delete s;
////	int a = 5;
////	const int* b = &a;
////	vector& operator
////
////	return 0;
////}
//#include<iostream>
//using namespace std;
//
//int main()
//{
//	int byte = 0;
//	cin >> byte；
//		int max = 0;
//	int count = 0;
//	while (byte)
//	{
//		//从第一个1开始按位与，求出多少个连续的1,赋值给max
//		while ((byte & 1) == 1)
//		{
//			count++;
//			byte = byte >> 1;
//		}
//		//出来就代表求出来本次有多少个连续的1，下一次继续
//		//cout为每次出现的次数，找最大的那一个
//		max = count>max ? count : max;
//	}
//	cout << max << endl;
//
//}

#include<iostream>
#include<string>
using namespace std;
//
//class Person{
//public:
//
//public:
//	string _name;
//};
//
//class Student: virtual public Person
//{
//public:
//
//protected:
//};
//class Teacher:virtual public Person
//{
//public:
//protected:
//	
//};
//class Assisant:public Student,public Teacher
//{
//
//protected:
//	
//	
//};
//
//int main()
//{
//	Assisant A;
//	A._name;
//	return 0;
//}
//class A{
//public:
//	int a;
//};
//class B: virtual public A
//{
//public:
//	int b;
//};
//class C :virtual public A
//{
//public:
//	int c;
//};
//class D :public B,public C
//{
//public:
//	int d;
//};
//
//int main()
//{
//	D d;
//	d.a = 1;
//	d.b = 2;
//	d.c=3;
//	d.d=4;
//	
//	cout<<sizeof(d)<<endl;
//
//	return 0;
//}

class A
{

};

class B:public A
{

};

class A
{

};

class B
{
	A a;
};