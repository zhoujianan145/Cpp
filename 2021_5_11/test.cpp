#include<iostream>
using namespace std;

class Base
{
public:
	virtual void Func1()
	{
		cout << "Func1()" << endl;
	}
	virtual void Func2()
	{
		cout << "Func2()" << endl;
	}
	virtual void Func3()
	{
		cout << "Func3()" << endl;
	}
	void Func4()
	{
		cout << "Func4()" << endl;
	}
	
private:
	int _b = 1;

};

class Derive :public Base
{
public:
	virtual void Func1()
	{
		cout << "D_Func1()" << endl;
	}
	virtual void Func2()
	{
		cout << "D_Func2()" << endl;
	}
private:
	int _d = 1;

};
int main()
{
	Base b;

	Derive d;

	b.Func2();
	Base* b1 = new Base;
	b1->Func2();

	Base* b2 = new Derive;
	b2->Func2();
	return 0;
}
//
//
//#include <cstdio>
//#include <cmath>
//#include <iostream>
//using namespace std;
//
//bool isPrime(int i)
//{
//	for (int j = 2; j <= sqrt(i * 1.0); j++) {
//		if (i % j == 0)
//			return false;
//	}
//	return true;
//}
//
//int main() {
//	int n;
//	int Prime1, Prime2;
//	while (cin >> n) {
//		if (n < 2)
//			return 1;
//		else {
//			for (int i = 1; i <= n / 2; i++) {
//				if (isPrime(i) && isPrime(n - i)) {
//					Prime1 = i;
//					Prime2 = n - i;
//				}
//			}
//			cout << Prime1 << endl;
//			cout << Prime2 << endl;
//		}
//	}
//	return 0;
//}

//class BinInsert {
//public:
//	int binInsert(int n, int m, int j, int i) {
//		// m×óÒÆjÎ»
//		m <<= j;
//		return n | m;
//	}
//};