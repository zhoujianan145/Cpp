#include<iostream>
#include<stack>
#include<algorithm>

using namespace std;
//class Parenthesis {
//public:
//	bool chkParenthesis(string A, int n) {
//		stack<char> st;
//		for (int i = 0; i<n; i++)
//		{
//			if (A[i] == '(')
//			{ 
//				st.push();
//			}
//			else if (A[i] == ')')
//			{
//				if (st.empty())
//				{
//					return false;
//				}
//				else
//				{
//					st.pop();
//				}
//			}
//		}
//		if (st.empty())
//		{
//			return true;
//		}
//		else
//		{
//			return false;
//		}
//
//	}
//};
int main()
{
	int n = 0;
	cin >> n;
	int x0 = 0;
	int x1 = 1;
	int xi = 0;
	for (int i = 0; xi < n; i++)
	{
		xi = x0 + x1;
		x0 = x1;
		x1 = xi;
	}
	return min(n-x0,x1-n);

}