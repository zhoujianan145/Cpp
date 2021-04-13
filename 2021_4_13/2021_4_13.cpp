//只出现一次的数字
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
//杨辉三角
class Solution {
public:
	vector<vector<int>> generate(int numRows) {
		vector<vector<int>> vv;
		//之前学的一维静态数组访问是解引用，二维动态数组解引用，二维静态数组转换为1维数组。
		//vector的[]是函数调用
		vv.resize(numRows, vector<int>());
		for (size_t i = 0; i<numRows; i++)
		{
			//第一行开1个，第二行开2个
			//每一行首尾置成1
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
//删除数组重复项
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
//之出现一次的数（3）
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
//之出现一次的数（2）
class Solution {
public:
	int GetOneLocation(int n)
	{
		int location = 0;
		//1 1 0
		//0 0 1  和1按位与，就能从第一位，判断他俩这一位是否相同。
		//不同，右移一位，看第二位相不相同，location，不同++，最后退出location是几就是第几位相同
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
		//n为那两个数字异或后的值，我们以1为界限，把他们两个划分开来。（那一位异或为1，说明在那一位他俩一定不一样）
		int a = 0;
		int b = 0;
		int location = GetOneLocation(n);

		//数组中每个数分别右移location和1按位与，假如等于0，进入a组。
		//假如等于1进入b组。
		//直接异或，因为两个数相同，比特位肯定相同，不会被分到两个组。


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