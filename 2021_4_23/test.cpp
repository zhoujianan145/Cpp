#include<iostream>

using namespace std;
//
////#define N 100
//template<class T,size_t N=100>
//class Array{
//public:
//
//private:
//	T arr[N];
//};
//template<class T>
//bool IsEqual(const T& a, const T& b)
//{
//	return a == b;
//}
//
////形参p1是外面p1的引用，不能修改外面的数组名，所以p1前面也要加const
//template<>
//bool IsEqual<const char*& const>(const char*& const p1,const char*& const p2)
//{
//	 if (strcmp(p1, p2) > 0)
//	{
//		 return true;
//	}
//	 return false;
//}
////bool IsEqual(const char* p1, const char* p2)
////{
////	if (strcmp(p1, p2) > 0)
////	{
////		return true;
////	}
////	return false;
////}
//int main()
//{
////Array<int,100> a1;
////Array<double,1000> a1;
//	
//	cout << IsEqual(1, 2) << endl;
//    char p1[5] = "abcd";
//    char p2[5]= "abcd";
//    cout << IsEqual(p1, p2) << endl;
//	return 0;
//}
template<class T1,class T2>
class Date{
public:
	Date()
	{
		cout << "Date(T1,T2)" << endl;
	}
private:
	T1 _year;
	T2 _day;
};
template<>
class Date<double,double>{
public:
	Date()
	{
		cout << " Date(double, double)" << endl;
	}
private:
	double d1;
	double d2;
};
template<class T>
class Date<T, double>{
public:
	Date()
	{
		cout << " Date(T, double)" << endl;
	}
private:
	double d1;
	double d2;
};

template<class T1,class T2>
class Date<T1*, T2*>{
public:
	Date()
	{
		cout << " Date(T1*, T2*)" << endl;
	}
private:
	double d1;
	double d2;
};

int main()
{
	/*Date<int,double> d1;
	Date<double, double> d2;*/
	/*Date<int, double> d3;*/
	Date<int*, double*> d4;
}