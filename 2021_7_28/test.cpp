class MaxQueue {
private:
	queue<int> q1;
	deque<int> q2;
public:
	MaxQueue() {

	}

	int max_value() {
		if (q1.empty())
			return -1;
		return q2.front();
	}

	void push_back(int value) {
		q1.push(value);

		while (!q2.empty() && value>q2.back())
		{
			q2.pop_back();
		}
		q2.push_back(value);
	}

	int pop_front() {
		if (q1.empty())
			return -1;
		int num = q1.front();
		q1.pop();
		if (q2.front() == num)
		{
			q2.pop_front();
		}
		return num;
	}
};

/**
* Your MaxQueue object will be instantiated and called as such:
* MaxQueue* obj = new MaxQueue();
* int param_1 = obj->max_value();
* obj->push_back(value);
* int param_3 = obj->pop_front();
*/

class Solution {
public:
	vector<vector<int>> findContinuousSequence(int target) {
		int i = 1;
		vector<vector<int>> ret;
		int sum = 0;
		//区间可以缩小，假设为15，那么最大为8.其他肯定不超过7
		for (int j = 1; j <= target / 2 + 1; j++)
		{
			sum += j;
			//假如刚好相等，直接入就可以了
			if (sum == target)
			{
				vector<int> temp;
				for (int k = i; k <= j; ++k)
				{
					temp.push_back(k);
				}
				ret.push_back(temp);
			}
			//大于目标，向左移滑动窗口起始位置，找目标
			while (sum>target)
			{
				sum -= i;
				i++;
				if (sum == target)
				{
					vector<int> temp;
					for (int k = i; k <= j; ++k)
					{
						temp.push_back(k);
					}
					ret.push_back(temp);
				}
			}
		}
		return ret;
	}
};
class Solution {
public:
	int singleNumber(vector<int>& nums) {
		int n = nums.size();

		int count[33] = { 0 };
		//遍历整个数组
		for (int i = 0; i<n; ++i)
		{
			//一个数求出他所有的二进制序列
			//求出来放在后面，因为我们习惯了从后往前数
			//比如3是 0 0 1 1
			//而不是  1 1 0 0
			for (int j = 32; j>0; --j)
			{
				count[j] += nums[i] & 1;
				nums[i] >>= 1;
			}
		}
		int ret = 0;
		for (int j = 1; j<33; ++j)
		{
			//不断去寻找数组中为1的那个数，同时也要左移
			ret <<= 1;
			//0就是0，1就会把ret那一位变成1
			ret |= count[j] % 3;
		}
		return ret;
	}
};