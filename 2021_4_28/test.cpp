#include<iostream>
#include<vector>
using namespace std;
//int main()
//{
//	int m = 0;
//	int n = 0;
//	while (cin >> m >> n)
//	{
//		vector<vector<int>> vv;
//		vv.resize(n);
//		for (int i = 0; i < n; i++)
//		{
//			vv[i].resize(m, 0);
//		}
//
//		for (int i = 0; i<=n; ++i)
//		{
//			for (int j = 0; j<=m; ++j)
//			{
//				if (i == 0 && j == 0)
//				{
//					vv[0][0] = 1;
//					continue;
//				}
//				if (i == 0)
//				{
//					vv[i][j] = vv[i][j - 1];
//				}
//				else if (j == 0)
//				{
//					vv[i][j] = vv[i - 1][j];
//				}
//				else
//				{
//					vv[i][j] = vv[i - 1][j] + vv[i][j - 1];
//				}
//			}
//		}
//		cout << vv[n - 1][m - 1] << endl;
//	}
//	return 0;
//}
class A{
public:
	void test(float a){ cout << "1"; }
};
class B :public A{
public:
	void test(int b){ cout << "2"; }
};
int  main()
{
	A* a = new A;
	B* b = new B;
	a = b;
	a->test(1.1);
	cout << endl;
	A a1;
	B b1;
	a1 = b1;
	a1.test(1);
	//看一下录屏中，为啥杭哥说的指向什么类型就是啥的，4.27号
	return 0;
}