

class Solution {
public:
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
		int m = obstacleGrid.size();
		int n = obstacleGrid[0].size();
		vector<vector<int>> dp(m, vector<int>(n, 0));

		//һ�����ϰ�������·����ֻ��Ϊ0����ֹͣ��1����
		for (int i = 0; i<m && obstacleGrid[i][0] == 0; ++i)
		{
			dp[i][0] = 1;
		}
		for (int i = 0; i<n && obstacleGrid[0][i] == 0; ++i)
		{
			dp[0][i] = 1;
		}
		//û���ϰ�ʱ�����ܼ���dp[i][j]
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
		//�κ�һ��������1����������2��3��ɣ�Ҫ��˻������ô3�͵ö�
		int ret = 1;
		//Ϊʲô��С��5�˳��أ���Ϊ4���ֽ��1��3�����Ϊ3��
		while (n >= 5)
		{
			ret *= 3;
			n -= 3;
		}
		//С��5�������ٳ�һ��
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
			//dp[i]������(i-j)*j,����dp[i-j]*j�Ƶ�������ȡ����һ��
			//����ѭ��������dp[i]��ʱ���ܱ仯������Ҫȡ����
			//����������max
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

