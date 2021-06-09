

class Solution {
public:
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
		int m = obstacleGrid.size();
		int n = obstacleGrid[0].size();
		vector<vector<int>> dp(m, vector<int>(n, 0));

		//一个有障碍，整条路径都只能为0，即停止赋1操作
		for (int i = 0; i<m && obstacleGrid[i][0] == 0; ++i)
		{
			dp[i][0] = 1;
		}
		for (int i = 0; i<n && obstacleGrid[0][i] == 0; ++i)
		{
			dp[0][i] = 1;
		}
		//没有障碍时，才能计算dp[i][j]
		for (int i = 1; i<m; ++i)
		{
			for (int j = 1; j<n; j++)
			{
				if (obstacleGrid[i][j] == 0)
				{
					dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
				}
			}
		}
		return dp[m - 1][n - 1];
	}
};
class Solution {
public:
	int cuttingRope(int n) {
		if (n == 2)
			return 1;
		if (n == 3)
			return 2;
		//任何一个数大于1，都可以由2和3组成，要想乘积最大，那么3就得多
		int ret = 1;
		//为什么是小于5退出呢，因为4，分解成1，3，相乘为3。
		while (n >= 5)
		{
			ret *= 3;
			n -= 3;
		}
		//小于5出来，再乘一下
		return n*ret;
	}
};
class Solution {
public:
	int integerBreak(int n) {
		vector<int> dp(n + 1, 0);
		dp[2] = 1;
		for (int i = 2; i <= n; ++i)
		{
			//dp[i]可以由(i-j)*j,或者dp[i-j]*j推导而来，取最大的一个
			//而再循环过程中dp[i]随时可能变化，则需要取更大
			//所以是两层max
			for (int j = 1; j<i; ++j)
			{
				dp[i] = max(dp[i], max((i - j)*j, dp[i - j] * j));
			}

		}
		return dp[n];

	}
};

class Solution {
public:
	bool wordBreak(string s, vector<string>& wordDict) {
		auto wordDictSet = unordered_set <string>();
		for (auto word : wordDict) {
			wordDictSet.insert(word);
		}

		auto dp = vector <bool>(s.size() + 1);
		dp[0] = true;
		for (int i = 1; i <= s.size(); ++i) {
			for (int j = 0; j < i; ++j) {
				if (dp[j] && wordDictSet.find(s.substr(j, i - j)) != wordDictSet.end()) {
					dp[i] = true;
					break;
				}
			}
		}

		return dp[s.size()];
	}
};

