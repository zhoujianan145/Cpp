class Solution {
public:
	//O(N)
	int trap(vector<int>& height) {
		int n = height.size();
		if (n == 0)
			return 0;
		//记录左边最高
		vector<int> leftDp(n, 0);
		leftDp[0] = height[0];
		for (int i = 1; i<n; i++)
		{
			leftDp[i] = leftDp[i - 1]>height[i] ? leftDp[i - 1] : height[i];
		}
		//记录右边最高

		vector<int> rightDp(n, 0);
		rightDp[n - 1] = height[n - 1];
		for (int i = n - 2; i >= 0; i--)
		{
			rightDp[i] = rightDp[i + 1]>height[i] ? rightDp[i + 1] : height[i];
		}
		int sum = 0;
		for (int i = 0; i<n; ++i)
		{
			int ret = min(leftDp[i], rightDp[i]) - height[i];
			if (ret>0)
				sum += ret;
		}
		return sum;
	}
};
class Solution {
public:
	int rob(vector<int>& nums) {
		int n = nums.size();
		if (n == 0)
			return 0;
		if (n == 1)
			return nums[0];

		int dp1 = nums[0];
		int dp2 = max(nums[0], nums[1]);
		for (int i = 2; i<n; i++)
		{
			int dp3 = max(dp1 + nums[i], dp2);
			dp1 = dp2;
			dp2 = dp3;
		}
		return dp2;
	}
};