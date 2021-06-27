/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
class Solution {
public:
	int maxDepth(TreeNode* root) {
		//  if(root==NULL)
		//       return 0;
		//  int leftDepth=maxDepth(root->left);
		//  int rightDepth=maxDepth(root->right);

		//  return leftDepth>rightDepth?leftDepth+1:rightDepth+1;
		if (root == NULL)
			return 0;
		queue<TreeNode*> q;
		q.push(root);
		int count = 0;
		while (!q.empty())
		{
			int size = q.size();
			while (size--)
			{
				TreeNode* tq = q.front();
				q.pop();
				if (tq->left)
					q.push(tq->left);
				if (tq->right)
					q.push(tq->right);
			}
			count++;
		}
		return count;
	}
};
class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int n = prices.size();
		if (n == 0)
			return 0;

		int minPrice = prices[0];
		int maxProfit = 0;
		for (int i = 1; i<n; ++i)
		{
			minPrice = min(minPrice, prices[i]);
			maxProfit = max(maxProfit, prices[i] - minPrice);
		}
		return maxProfit;
	}
};
class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int n = prices.size();
		if (n == 0)
			return 0;
		int minPrice = prices[0];
		vector<int> dp(n, 0);
		for (int i = 1; i<n; ++i)
		{
			minPrice = min(prices[i], minPrice);
			dp[i] = max(dp[i - 1], prices[i] - minPrice);
		}
		return dp[n - 1];
	}
};