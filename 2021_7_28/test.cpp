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
		//���������С������Ϊ15����ô���Ϊ8.�����϶�������7
		for (int j = 1; j <= target / 2 + 1; j++)
		{
			sum += j;
			//����պ���ȣ�ֱ����Ϳ�����
			if (sum == target)
			{
				vector<int> temp;
				for (int k = i; k <= j; ++k)
				{
					temp.push_back(k);
				}
				ret.push_back(temp);
			}
			//����Ŀ�꣬�����ƻ���������ʼλ�ã���Ŀ��
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
		//������������
		for (int i = 0; i<n; ++i)
		{
			//һ������������еĶ���������
			//��������ں��棬��Ϊ����ϰ���˴Ӻ���ǰ��
			//����3�� 0 0 1 1
			//������  1 1 0 0
			for (int j = 32; j>0; --j)
			{
				count[j] += nums[i] & 1;
				nums[i] >>= 1;
			}
		}
		int ret = 0;
		for (int j = 1; j<33; ++j)
		{
			//����ȥѰ��������Ϊ1���Ǹ�����ͬʱҲҪ����
			ret <<= 1;
			//0����0��1�ͻ��ret��һλ���1
			ret |= count[j] % 3;
		}
		return ret;
	}
};