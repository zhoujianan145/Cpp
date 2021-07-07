//#include<iostream>
//#include<string>
//#include<algorithm>
//using namespace std;
//class Solution {
//public:
//	int lengthOfLongestSubstring(string s) {
//		int map[128] = { 0 }, len = 0, start = 0;  //map统计字符在当前子串出现次数,字符的ascii码值小于128
//		for (int i = 0; i < s.size(); ++i)
//		{
//			++map[s[i]];
//			while (map[s[i]] == 2)   //出现重复
//				--map[s[start++]];  //不断滑动右移的同时恢复map中的状态，当map[s[i]]=1时，确定新的start
//			len = max(len, i - start + 1);
//		}
//		return len;
//	}
//};
//
//int main()
//{
//	Solution().lengthOfLongestSubstring("abcabcbb");
//
//	return 0;
//}

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {

		int left = 0;
		int right = nums.size() - 1;
		vector<int> v;
		//对撞双指针
		while (left<right)
		{
			if (target - nums[right]>nums[left])
			{
				left++;
			}
			else if (target - nums[right]<nums[left])
			{
				right--;
			}
			else
			{
				v.push_back(nums[left]);
				v.push_back(nums[right]);
				return v;
			}
		}
		return v;
	}
};

class Solution {
public:
	int findRepeatNumber(vector<int>& nums) {
		int n = nums.size();
		int i = 0;
		while (i<n)
		{
			if (nums[i] != i)
			{
				if (nums[i] == nums[nums[i]])
				{
					//假如该放的位置上存在之前已将放了正确的元素
					//那你肯定就是重复了
					return nums[i];
				}
				//把nums[i]放在他该放的位置去
				swap(nums[i], nums[nums[i]]);
			}
			//相等就说明这个位置数字正确
			i++;
		}
		return -1;
	}
};
class Solution {
public:
	int minSubArrayLen(int target, vector<int>& nums) {
		int n = nums.size();
		//滑动窗口起始值
		int i = 0;
		int sum = 0;
		int result = INT_MAX;
		//j就是滑动窗口的终止值
		for (int j = 0; j<n; ++j)
		{
			sum += nums[j];
			while (sum >= target)
			{
				int subLenth = j - i + 1;
				result = min(subLenth, result);
				sum -= nums[i];
				//更新他的起始值
				i++;
			}
		}
		return result == INT_MAX ? 0 : result;
	}
};

/*
// Definition for a Node.
class Node {
public:
int val;
Node* left;
Node* right;

Node() {}

Node(int _val) {
val = _val;
left = NULL;
right = NULL;
}

Node(int _val, Node* _left, Node* _right) {
val = _val;
left = _left;
right = _right;
}
};
*/
class Solution {
private:
	void _treeToDoublyList(Node* cur, Node*&  prev)
	{
		if (cur == NULL)
			return;
		_treeToDoublyList(cur->left, prev);

		//左边prev为当前节点下方的节点
		//右边prev为当前节点上方的节点
		cur->left = prev;
		if (prev)
			prev->right = cur;
		prev = cur;

		_treeToDoublyList(cur->right, prev);

	}
public:
	Node* treeToDoublyList(Node* root) {
		if (root == NULL)
			return root;
		//root是根，根是4,并不是我们想要的头
		// Node* head=root;
		Node* head = root;
		Node* prev = NULL;

		_treeToDoublyList(root, prev);
		//prev走完就变成了5,也就是最后一个节点

		//头在最左
		while (head->left)
		{
			head = head->left;
		}
		head->left = prev;
		prev->right = head;

		return head;
	}
};