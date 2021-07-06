#include<iostream>
#include<string>
#include<vector>
using namespace std;
//int main()
//{
//	string str;
//	while (getline(cin, str))
//	{
//		int n = str.size();
//		vector<string> v;
//		string temp;
//		for (int i = 0; i<n; ++i)
//		{
//			if (i<n && str[i] == '_')
//			{
//				str[i + 1] -= 32;
//			}
//		}
//		for (int i = 0; i<n; ++i)
//		{
//			if (str[i] != '_')
//			{
//				temp += str[i];
//			}
//			else
//			{
//				if (temp.size()>0)
//				{
//					v.push_back(temp);
//					temp = "";
//				}
//			}
//		}
//		if (temp.size()>0)
//		{
//			v.push_back(temp);
//		}
//		for (int i = 0; i<v.size(); ++i)
//		{
//			cout << v[i];
//		}
//		cout << endl;
//	}
//	return 0;
//}
class Solution {
private:
	void reverse(int left, int right, string& s)
	{
		while (left<right)
		{
			swap(s[left], s[right]);
			left++;
			right--;
		}
	}
public:
	string reverseWords(string s) {
		int start = 0;
		int end = 0;
		int n = s.size();
		string temp = s;
		reverse(start, n-1, temp);
		cout << temp << endl;
		while (end<n)
		{
			while (end<n && temp[end] != ' ')
			{
				end++;
			}
			if (end == n)
			{
				reverse(start, end, temp);
			}
			reverse(start, end - 1, temp);

			start = end + 1;				break;

			end++;
		}
		return temp;
	}
};
int main()
{
	Solution().reverseWords("the sky is blue");
	return 0;
}