//ֻ����һ�ε�����
class Solution {
public:
	int singleNumber(vector<int>& nums) {
		int n = 0;
		for (auto& e : nums)
		{
			n ^= e;
		}
		return n;
	}
};
//�������
class Solution {
public:
	vector<vector<int>> generate(int numRows) {
		vector<vector<int>> vv;
		//֮ǰѧ��һά��̬��������ǽ����ã���ά��̬��������ã���ά��̬����ת��Ϊ1ά���顣
		//vector��[]�Ǻ�������
		vv.resize(numRows, vector<int>());
		for (size_t i = 0; i<numRows; i++)
		{
			//��һ�п�1�����ڶ��п�2��
			//ÿһ����β�ó�1
			vv[i].resize(i + 1, 0);
			vv[i][0] = vv[i][vv[i].size() - 1] = 1;
		}

		for (size_t i = 0; i<numRows; i++)
		{
			for (size_t j = 0; j<vv[i].size(); j++)
			{
				if (vv[i][j] == 0)
				{
					vv[i][j] = vv[i - 1][j] + vv[i - 1][j - 1];
				}
			}
		}
		return vv;
	}
};
//ɾ�������ظ���
class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		int slow = 0;
		if (nums.size() == 0)
		{
			return 0;
		}
		for (int fast = 1; fast<nums.size(); fast++)
		{
			if (nums[fast] != nums[slow])
			{
				slow++;
				nums[slow] = nums[fast];
			}
		}
		return  slow + 1;
	}
};
//֮����һ�ε�����3��
class Solution {
public:
	int singleNumber(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		for (int i = 0; i<nums.size(); i += 3)
		{
			if (i + 1<nums.size() && nums[i] != nums[i + 1])
			{
				return nums[i];
			}
		}
		return nums[nums.size() - 1];
	}
};
//֮����һ�ε�����2��
class Solution {
public:
	int GetOneLocation(int n)
	{
		int location = 0;
		//1 1 0
		//0 0 1  ��1��λ�룬���ܴӵ�һλ���ж�������һλ�Ƿ���ͬ��
		//��ͬ������һλ�����ڶ�λ�಻��ͬ��location����ͬ++������˳�location�Ǽ����ǵڼ�λ��ͬ
		while (((n & 1) == 0) && (location<32))
		{
			n = n >> 1;
			location++;
		}
		return location;
	}
	vector<int> singleNumber(vector<int>& nums) {
		if (nums.size() == 2)
		{
			return nums;
		}
		int n = 0;
		for (auto& e : nums)
		{
			n ^= e;
		}
		//nΪ���������������ֵ��������1Ϊ���ޣ��������������ֿ���������һλ���Ϊ1��˵������һλ����һ����һ����
		int a = 0;
		int b = 0;
		int location = GetOneLocation(n);

		//������ÿ�����ֱ�����location��1��λ�룬�������0������a�顣
		//�������1����b�顣
		//ֱ�������Ϊ��������ͬ������λ�϶���ͬ�����ᱻ�ֵ������顣


		for (int i = 0; i<nums.size(); i++)
		{

			if (((nums[i] >> location) & 1) == 0)
			{
				a ^= nums[i];
			}
			else{
				b ^= nums[i];
			}
		}
		return vector<int> {a, b};


	}
};