#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

//class Bonus {
//public:
//	int getMost(vector<vector<int> >& board) {
//		vector<vector<int>> dp(board.size() + 1, vector<int>(board[0].size() + 1, 0));
//
//		dp[0][0] = board[0][0];
//		for (int i = 1; i<board.size(); i++)
//			dp[i][0] = dp[i - 1][0] + board[i][0];
//		for (int i = 1; i<board.size(); i++)
//			dp[0][i] = dp[0][i - 1] + board[0][i];
//
//		for (int i = 1; i<board.size(); i++)
//		{
//			for (int j = 1; j<board[0].size(); j++)
//			{
//				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + board[i][j];
//			}
//
//		}
//		return dp[5][5];
//
//
//	}
//};
//
//int main()
//{
//	int vv[6][6]={
//		    564, 448, 654, 186, 490, 699,
//			487, 444, 563, 228, 365, 261,
//			429, 505, 612, 564, 715, 726,
//			464, 617, 234, 647, 702, 263,
//			245, 249, 231, 462, 453, 646,
//			669, 510, 492, 512, 622, 135};
//	vector<vector<int>> vvv;
//	for (int i = 0; i < 6; i++)
//	{
//		vector<int> v;
//		for (int j = 0; j < 6; j++)
//		{
//			v.push_back(vv[i][j]);
//		}
//		vvv.push_back(v);
//	}
//
//	Bonus().getMost(vvv);
//	 
//	for (int i = 0; i < 6; i++)
//	 {
//		
//		 for (int j = 0; j < 6; j++)
//		 {
//			 cout << vvv[i][j] << "";
//		 }
//		 cout << endl;
//	 }
//	return 0;
//}

class Solution {
public:
	vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
		vector<int> v;
		if (k>input.size()||k<=0)
			return v;
		priority_queue<int, vector<int>, less<int>> pr;

		for (int i = 0; i<k; i++)
		{
			pr.push(input[i]);
		}
		for (int i = k; i<input.size(); i++)
		{
			if (input[i]<pr.top())
			{
				pr.push(input[i]);
				pr.pop();
			}
		}
		for (int i = 0; i < k; i++)
		{
			v[i] = pr.top();
			pr.pop();
		}
		return v;
	}
};

int main()
{
	int a[] = { 4, 5, 1, 6, 2, 7, 3, 8 };
	vector<int> v;
	for (int i = 0; i < sizeof(a) / a[0]; i++)
	{
		v.push_back(a[i]);
	}
	
	Solution().GetLeastNumbers_Solution(v,0);
	return 0;
}