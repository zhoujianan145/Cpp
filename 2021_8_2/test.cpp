
#include<iostream>
using namespace std;
//static int i = 2;
//int check()
//{
//	int i = 1;
//
//	return (*(char*)&i);
//}

//class MyArray
//{
//public:
//	typedef int LengthType;
//
//};
//
//template<class T>
//void MyMethod(T myarr)
//{
//	typedef class T::LengthType LengthType;
//	LengthType length = myarr.GetLength;
//}

class A
{
public:
	int a;
};

int main()
{
	extern int c;
	c = 3;
	cout << c;
	//int *p = (int*)&a;
	//*p = 2;
	//
	//cout << sizeof(A) << endl;
	//int ret = check();
	//if (ret == 1)
	//{
	//	cout << "´ó¶Ë" << endl;
	//}
	//else
	//{
	//	cout << "Ð¡¶Ë" << endl;
	//}
	//extern int i;
	//cout << i << endl;
	//char a[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
	//int *b = &a;
	//printf("%x\n", *b);
	
	return 0;
}