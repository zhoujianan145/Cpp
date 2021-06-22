#include<string>
#include<vector>
#include<iostream>
#include<unordered_set>
using namespace std;
class Solution {
private:
	void DFS(string s, vector<string>& ret, vector<bool>& vis, string curStr, int index)
	{
		if (index == s.size())
		{
			ret.push_back(curStr);
			return;
		}
		for (int i = 0; i<s.size(); i++)
		{
			if (vis[i])
			{
				vis[i] = false;
				DFS(s, ret, vis, curStr + s[i], index + 1);
				vis[i] = true;
			}
		}
	}
public:
	vector<string> permutation(string s) {

		unordered_set<char> dict(s.begin(), s.end());
		string temp(dict.begin(), dict.end());
		vector<string> ret;
		vector<bool> vis(s.size(), true);
		DFS(temp, ret, vis, "", 0);
		
		
		return ret;

	}
};

int main()
{
	Solution().permutation("aab");
		return 0;
}
class Solution {
private:
	unordered_map<char, string> Map;
	void DFS(const string& digits, vector<string>& Allret, string curStr, int idx)
	{
		if (idx == digits.size())
		{//只有和字符串大小相等时才加入数组当中,然后结束当前深搜
			Allret.push_back(curStr);
			return;
		}
		//取出当前字符对应的字符串
		string curMap = Map[digits[idx]];
		for (char e : curMap)
		{
			//curStr+e，即为一个回溯的过程
			//从DFS返回他就又成为了curStr
			//curStr+e是个临时变量，所以形参不能是引用
			DFS(digits, Allret, curStr + e, idx + 1);
		}
	}
public:
	vector<string> letterCombinations(string digits) {
		vector<string> Allret;
		if (digits.size() == 0)
			return Allret;
		Map = { { '2', "abc" }, { '3', "def" }, { '4', "ghi" }, { '5', "jkl" }, { '6', "mno" }, { '7', "pqrs" }, { '8', "tuv" }, { '9', "wxyz" } };


		DFS(digits, Allret, "", 0);


		return Allret;

	}
};
class Solution {
private:
	vector<int>  v;
	// v={1,2,4,8,16,32};
	void DFS(vector<string>& ret, int hour, int minutes, int prev, int turnedOn)
	{
		//边界
		if (hour >= 12 || minutes >= 60)
		{
			return;
		}
		//每次减一，等于0，说明组合满足，时放入结果数组
		//例如turned=2，就是两两组合
		if (turnedOn == 0)
		{
			//m和h:先用整形计算，后转换成字符串
			string m = to_string(minutes);
			//字符串小于两位，前面补个0
			m = m.size() >= 2 ? m : '0' + m;
			string h = to_string(hour);
			ret.push_back(h + ":" + m);
			return;
		}

		for (int i = prev; i<10; i++)
		{
			//小于6，先和分钟组合
			if (i<6)
			{                //从i=0开始,turnedOn为2-1。
				//第一次搜索以1为基准，i<6算分钟,去匹配 1+2 1+4 1+8 1+16 1+32(即0:03,0:05,....)
				//  i>6算小时,去匹配 1:01 2:01 4:01 8:01
				//回溯回来以2为基准,   i<6算分钟,去匹配 2+4 2+8 2+16 2+32(即0:06,0:10,...)
				//  i>6算小时,去匹配 1:02 2:02 4:02 8:02
				//处理完2回溯回来到3
				//i+1表示下一次不算本身，例如以1为基准组合，从2开始。以2为基准组合，从4开始
				DFS(ret, hour, minutes + v[i], i + 1, turnedOn - 1);
			}//大于6，和小时组合
			else
			{
				DFS(ret, hour + v[i - 6], minutes, i + 1, turnedOn - 1);
			}
		}

	}
public:
	vector<string> readBinaryWatch(int turnedOn) {
		vector<string> ret;
		if (turnedOn >= 9)
			return ret;
		//小时和分钟的前四个一样，那么写成一个，等会做个区分就可以
		//用两个vector也可
		v = { 1, 2, 4, 8, 16, 32 };
		DFS(ret, 0, 0, 0, turnedOn);

		return ret;

	}
};
class Solution {
private:
	void DFS(vector<int>& candidates, int target, vector<vector<int>>& ret, vector<int>& temp, int sum, int prev)
	{
		//大于返回，等于，先添加进结果数组再返回。
		if (sum >= target)
		{
			if (sum == target)
			{
				ret.push_back(temp);
			}
			return;
		}

		//从上一个开始，例如2 2 3，回溯之后为2 2,可以从2 2开始继续试探
		//不能从第一个重新开始，因为有可能造成 2 2 3 和 3 2 2这种情况，就成为了重复的组合
		for (int i = prev; i<candidates.size(); i++)
		{
			temp.push_back(candidates[i]);
			//回溯
			//1. 当前Dfs结束sum+candidates[i],就会变成sum
			//2. temp里面也要删
			//prev继续传i表示，上一个相加的位可以重复使用
			DFS(candidates, target, ret, temp, sum + candidates[i], i);
			temp.pop_back();
		}
	}
public:
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		vector<vector<int>> ret;
		if (candidates.empty())
			return ret;
		vector<int> temp;
		DFS(candidates, target, ret, temp, 0, 0);

		return ret;
	}
};
class Solution {
private:
	void DFS(string tiles, unordered_set<string>& ret, vector<bool>& vis, string curStr)
	{

		if (curStr != "")
		{
			ret.insert(curStr);
		}

		for (int i = 0; i<tiles.size(); i++)
		{
			if (vis[i])
			{
				vis[i] = false;
				DFS(tiles, ret, vis, curStr + tiles[i]);
				vis[i] = true;
			}
		}


	}

public:
	int numTilePossibilities(string tiles) {
		unordered_set<string> ret;
		vector<bool> vis(tiles.size(), true);

		DFS(tiles, ret, vis, "");

		return ret.size();
	}
};