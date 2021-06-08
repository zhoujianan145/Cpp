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
		//dp[0]=0，前0天最大利润为0
		for (int i = 1; i<n; i++)
		{
			//保存最小的价格
			minPrices = minPrices<prices[i] ? minPrices : prices[i];
			//上一次最大利润，本次最大利润，取大的那一个
			dp[i] = max(dp[i - 1], prices[i] - minPrices);
		}
		return dp[n - 1];
	}
};