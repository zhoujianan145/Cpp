
#include<string>
using namespace std;

int c = 1;
template<class T>

void Swap(T& a, T& b)
{
	swap(a, b);
}
template<>
void Swap<int>(int& a, int& b)
{
	a = b;
}
static void Printf(int& a, int& b)
{
	a = b;
}
void test()
{
	/*int a = 1, b = 2;*/
	string a = "213";
	string b = "122";
	Swap(a, b);
}
