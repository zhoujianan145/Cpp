#include<iostream>
#include<vector>
#include<string>
using namespace std;

//class Solution {
//public:
//	string multiply(string num1, string num2) {
//		vector<int> a(num1.size(), 0);
//		vector<int> b(num2.size(), 0);
//		vector<int> c(num1.size() + num2.size()-1, 0);
//		
//
//		for (int i = 0; i<num1.size(); i++)
//		{
//			a[i] = num1[i] - '0';
//		}
//		for (int i = 0; i<num2.size(); i++)
//		{
//			b[i] = num2[i] - '0';
//		}
//		for (int i = a.size() - 1; i >= 0; i--)
//		{
//			for (int j = b.size() - 1; j >= 0; j--)
//			{
//				c[i + j] += a[i] * b[j];
//			}
//		}
//		int flag = 0;
//		string ans;
//		for (int i = c.size() - 1; i >= 0; i--)
//		{
//			c[i] = c[i] + flag;
//			char a = c[i] % 10 + '0';
//			ans = a + ans;
//			flag = c[i] / 10;
//
//		}
//		return 0;
//	}
//	
//};
class Solution {
public:
	string multiply(string num1, string num2) {
		vector<int> a(num1.size(), 0);
		vector<int> b(num2.size(), 0);
		vector<int> c(num1.size() + num2.size() - 1, 0);

		for (int i = 0; i<num1.size(); i++)
		{
			a[i] = num1[i] - '0';
		}
		for (int i = 0; i<num2.size(); i++)
		{
			b[i] = num2[i] - '0';
		}
		for (int i = a.size() - 1; i >= 0; i--)
		{
			for (int j = b.size() - 1; j >= 0; j--)
			{
				c[i + j] += a[i] * b[j];
			}
		}
		int flag = 0;
		string ans;
		for (int i = c.size() - 1; i >= 0; i--)
		{
			c[i] = c[i] + flag;
			char a = c[i] % 10 + '0';
			ans = a + ans;
			flag = c[i] / 10;
		}
		while (flag)
		{
			char a = flag + '0';
			ans = a + ans;
			flag /= 10;
		}
		while (ans.size()>1 && ans[0] == '0')
		{
			ans.erase(ans.begin());
		}

		return ans;
	}
};

int main()
{
	Solution().multiply("123", "456");
	return 0;
}
