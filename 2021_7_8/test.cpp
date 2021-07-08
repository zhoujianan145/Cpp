//#include<iostream>
//#include<string>
//#include<list>
//#include<vector>
//#include<algorithm>
//#include<unordered_map>
//using namespace std;
//
//int main()
//{
//	/*string s1="asasa";*/
//	/*unordered_map<char, int> h1(s1.begin(), s1.end());*/
//	//unordered_map<char, int> h2(s2.begin(), s2.end());
//	/*while (cin >> s1&&cin >> s2)
//	{
//	unordered_map<char, int> h1(s1.begin(),s1.end());
//	unordered_map<char, int> h2(s2.begin(), s2.end());
//	bool t = true;
//	for (auto& e : h2)
//	{
//	if (h1[e.first]<e.second)
//	{
//	t = false;
//	break;
//	}
//	}
//
//	if (t)
//	{
//	cout << "Yes" << endl;
//	}
//	else
//	{
//	cout << "No" << endl;
//	}
//
//
//	}*/
//	list<int> l1({1,2,2,4,5});
//
//	//find输出迭代器
//	std::find(l1.begin(), l1.end(),2);
//	//sort随机迭代器
//	/*sort(l1.begin(), l1.end());*/
//	return 0;
//}
//
class Solution {
public:
	int findNthDigit(int n) {
		int digit = 1;
		long start = 1;
		long count = 9;

		while (n>count)
		{
			n -= count;
			start *= 10;
			digit++;
			count = start*digit * 9;
		}
		int nums = start + (n - 1) / digit;

		string s = to_string(nums);

		int ret = s[(n - 1) % digit] - '0';


		return ret;

	}
};
struct Less{
public:
	bool operator()(const string& s1, const string s2)
	{
		return s1 + s2<s2 + s1;
	}
};

class Solution {

public:
	string minNumber(vector<int>& nums) {
		string s;
		int n = nums.size();
		vector<string> v;

		for (int& e : nums)
		{
			v.push_back(to_string(e));
		}
		//等看了lamba表达式在来写一遍这种写法
		sort(v.begin(), v.end(), Less());

		for (auto& e : v)
		{
			s += e;
		}
		return s;


	}
};