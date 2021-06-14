class Solution {
private:
	//找左边的target
	int leftPos(vector<int>& nums, int target)
	{
		int left = 0;
		int right = nums.size() - 1;
		while (left<right)
		{
			int mid = left + (right - left) / 2;
			//小于一定不再左区间
			if (nums[mid]<target)
			{
				left = mid + 1;
			}
			else
			{
				right = mid;
			}
		}
		if (nums[left] == target)
			return left;
		else
			return -1;

	}
	//找右边的target
	int rightPos(vector<int>& nums, int target)
	{
		int left = 0;
		int right = nums.size() - 1;
		while (left<right)
		{
			//向上取整，防止两个元素出现死循环
			int mid = left + (right - left + 1) / 2;

			//大于一定不在右区间
			if (nums[mid]>target)
			{
				right = mid - 1;
			}
			else
			{
				left = mid;
			}
		}
		return left;
	}
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		if (nums.size() == 0)
			return{ -1, -1 };
		int left = leftPos(nums, target);
		if (left == -1)
			return{ -1, -1 };
		int right = rightPos(nums, target);
		return{ left, right };
	}
};

class Solution {
public:
	int mySqrt(int x) {
		int left = 0;
		int right = x - 1;

		if (x == 0)
			return 0;
		if (x == 1)
			return 1;

		while (left<right)
		{
			//由于left=mid,所以会引起死循环，所以需要对mid调整

			int mid = left + (right - left + 1) / 2;

			//mid*mid>x这样写可能溢出
			//一个数大于x，那么他一定不是解
			if (mid>x / mid)
			{
				right = mid - 1;
			}
			else
			{
				left = mid;
			}
		}
		return left;
	}
};

class Solution {
public:
	double myPow(double x, int n) {
		long temp = n;
		if (temp<0)
		{
			temp = -temp;
			x = 1 / x;
		}


		double num = x;
		double target = 1;

		while (temp)
		{
			if (temp & 1)
			{
				target *= num;
			}
			num *= num;
			temp >>= 1;
		}
		return target;
	}
};