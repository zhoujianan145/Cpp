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
		{//ֻ�к��ַ�����С���ʱ�ż������鵱��,Ȼ�������ǰ����
			Allret.push_back(curStr);
			return;
		}
		//ȡ����ǰ�ַ���Ӧ���ַ���
		string curMap = Map[digits[idx]];
		for (char e : curMap)
		{
			//curStr+e����Ϊһ�����ݵĹ���
			//��DFS���������ֳ�Ϊ��curStr
			//curStr+e�Ǹ���ʱ�����������ββ���������
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
		//�߽�
		if (hour >= 12 || minutes >= 60)
		{
			return;
		}
		//ÿ�μ�һ������0��˵��������㣬ʱ����������
		//����turned=2�������������
		if (turnedOn == 0)
		{
			//m��h:�������μ��㣬��ת�����ַ���
			string m = to_string(minutes);
			//�ַ���С����λ��ǰ�油��0
			m = m.size() >= 2 ? m : '0' + m;
			string h = to_string(hour);
			ret.push_back(h + ":" + m);
			return;
		}

		for (int i = prev; i<10; i++)
		{
			//С��6���Ⱥͷ������
			if (i<6)
			{                //��i=0��ʼ,turnedOnΪ2-1��
				//��һ��������1Ϊ��׼��i<6�����,ȥƥ�� 1+2 1+4 1+8 1+16 1+32(��0:03,0:05,....)
				//  i>6��Сʱ,ȥƥ�� 1:01 2:01 4:01 8:01
				//���ݻ�����2Ϊ��׼,   i<6�����,ȥƥ�� 2+4 2+8 2+16 2+32(��0:06,0:10,...)
				//  i>6��Сʱ,ȥƥ�� 1:02 2:02 4:02 8:02
				//������2���ݻ�����3
				//i+1��ʾ��һ�β��㱾��������1Ϊ��׼��ϣ���2��ʼ����2Ϊ��׼��ϣ���4��ʼ
				DFS(ret, hour, minutes + v[i], i + 1, turnedOn - 1);
			}//����6����Сʱ���
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
		//Сʱ�ͷ��ӵ�ǰ�ĸ�һ������ôд��һ�����Ȼ��������־Ϳ���
		//������vectorҲ��
		v = { 1, 2, 4, 8, 16, 32 };
		DFS(ret, 0, 0, 0, turnedOn);

		return ret;

	}
};
class Solution {
private:
	void DFS(vector<int>& candidates, int target, vector<vector<int>>& ret, vector<int>& temp, int sum, int prev)
	{
		//���ڷ��أ����ڣ�����ӽ���������ٷ��ء�
		if (sum >= target)
		{
			if (sum == target)
			{
				ret.push_back(temp);
			}
			return;
		}

		//����һ����ʼ������2 2 3������֮��Ϊ2 2,���Դ�2 2��ʼ������̽
		//���ܴӵ�һ�����¿�ʼ����Ϊ�п������ 2 2 3 �� 3 2 2����������ͳ�Ϊ���ظ������
		for (int i = prev; i<candidates.size(); i++)
		{
			temp.push_back(candidates[i]);
			//����
			//1. ��ǰDfs����sum+candidates[i],�ͻ���sum
			//2. temp����ҲҪɾ
			//prev������i��ʾ����һ����ӵ�λ�����ظ�ʹ��
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