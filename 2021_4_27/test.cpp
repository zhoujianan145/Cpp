//#include<iostream>
//using namespace std;
//class cla
//{
//	static int n ;
//public:
//	cla()
//	{
//		n++;
//	}
//	~cla()
//	{
//		n--;
//	}
//	static int get_n()
//	{
//		return n;
//	}
//
//
//};
//int cla::n = 0;
//
//int main()
//{
//	/*cla *p = new cla;
//	delete p;
//	cout << cla::get_n() << endl;
//	return 0;*/
//	//int i = 10;
//	//int j = 1;
//	//
//	//int const *p2 = &i;
//	//p2 = &j;
//	//int *const p3 = &i;
//	//*p3 = 20;
//	//int a = 1;
//	//int b = a;
//	//int *p5 = &b;
//	//char arr[] = "abcde";
//	//*arr = '3';
//	//int* p1 = &i;
//	//*p1 = 2;
//	int a[4] = { 1, 2, 3, 4 };
//	int *ptr = (int*)(&a + 1);
//	printf("%d", *(ptr - 1));
//	return 0;
//}
//#include<iostream>
//#include<vector>
//#include<string>
//
//using  namespace std;
//
//bool Judgeletter(const vector<string>& v)
//{
//	for (int i = 0; i<v.size() - 1; i++)
//	{
//		if (v[i + 1]<v[i])
//		{
//			return false;
//		}
//	}
//	return true;
//}
//bool Judgelength(const vector<string>& v)
//{
//	for (int i = 0; i<v.size() - 1; i++)
//	{
//		if (v[i + 1].size()<v[i].size())
//		{
//			return false;
//		}
//	}
//	return true;
//}
//
//int main()
//{
//	int n = 0;
//	cin >> n;
//	vector<string> v(n, " ");
//	for (int i = 0; i<n; i++)
//	{
//		cin >> v[i];
//	}
//	int i = Judgeletter(v);
//	int j = Judgelength(v);
//	if (i == 1 && j == 0)
//	{
//		cout << "lexicographically" << endl;
//	}
//	else if (i == 0 && j == 1)
//	{
//		cout << "lengths" << endl;
//	}
//	else if (i == 1 && j == 1)
//	{
//		cout << "both" << endl;
//	}
//	else
//	{
//		cout << "none" << endl;
//	}
//
//	return 0;
//}
#include<iostream>
using namespace std;

int gcd(int a, int b)
{
	int temp = 0;
	while (b)
	{
		temp = a%b;
		a = b;
		b = temp;
	}
	return a;
}
int main()
{

	int a = 0;
	int b = 0;
	cin >> a >> b;
	//a*b/gcd(a,b)会有溢出风险
	cout << a / gcd(a, b)*b << endl;
	return 0;
}