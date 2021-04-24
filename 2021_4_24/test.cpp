#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
	int StrToInt(string str) {
		if (str.empty())
		{
			return 0;
		}
		int flag = 1;

		if (str[0] == '-')
		{
			flag = -1;
			str[0] = '0';
		}
		else if (str[0] == '+')
		{
			flag = 1;
			str[0] = '0';
		}
		long long nums = 0;
		for (int i = 0; i<str.size(); i++)
		{
			if (str[i]<'0' || str[i]>'9')
			{
				return 0;
			}
			nums = nums * 10 + (str[i] - '0');
			if (flag>0 && nums>0x7fffffff || flag<0 && nums<0x80000000)
			{
				return 0;
			}

		}

		return flag*(int)nums;
	}
};

int main()
{
	Solution().StrToInt("-123");
	return 0;
}
//链接：https://www.nowcoder.com/questionTerminal/1183548cd48446b38da501e58d5944eb
//来源：牛客网
//
//#include<iostream>
//using namespace std;
//int a[1000][1000] = { 0 };
//int main()
//{
//	int w, h, res = 0;
//	cin >> w >> h;
//
//	for (int i = 0; i<w; i++)
//	{
//		for (int j = 0; j<h; j++)
//		{
//			if (a[i][j] == 0)
//			{
//				res++;
//				if ((i + 2)<w) a[i + 2][j] = -1;
//				if ((j + 2)<h) a[i][j + 2] = -1;
//			}
//		}
//	}
//	cout << res;
//	return 0;
//}