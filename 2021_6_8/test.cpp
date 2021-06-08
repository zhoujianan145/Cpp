class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int n = prices.size();
		int minprices = prices[0];
		int maxprofit = 0;
		for (int i = 1; i<n; i++)
		{
			minprices = min(minprices, prices[i]);
			maxprofit = max(maxprofit, prices[i] - minprices);
		}
		return maxprofit;
	}
};
class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int n = prices.size();
		vector<int> dp(n, 0);
		int minPrices = prices[0];
		//dp[0]=0��ǰ0���������Ϊ0
		for (int i = 1; i<n; i++)
		{
			//������С�ļ۸�
			minPrices = minPrices<prices[i] ? minPrices : prices[i];
			//��һ��������󣬱����������ȡ�����һ��
			dp[i] = max(dp[i - 1], prices[i] - minPrices);
		}
		return dp[n - 1];
	}
};