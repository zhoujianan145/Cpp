//#include<iostream>
//#include<string>
//#include<algorithm>
//using namespace std;
//class Solution {
//public:
//	int lengthOfLongestSubstring(string s) {
//		int map[128] = { 0 }, len = 0, start = 0;  //mapͳ���ַ��ڵ�ǰ�Ӵ����ִ���,�ַ���ascii��ֵС��128
//		for (int i = 0; i < s.size(); ++i)
//		{
//			++map[s[i]];
//			while (map[s[i]] == 2)   //�����ظ�
//				--map[s[start++]];  //���ϻ������Ƶ�ͬʱ�ָ�map�е�״̬����map[s[i]]=1ʱ��ȷ���µ�start
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
		//��ײ˫ָ��
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
					//����÷ŵ�λ���ϴ���֮ǰ�ѽ�������ȷ��Ԫ��
					//����϶������ظ���
					return nums[i];
				}
				//��nums[i]�������÷ŵ�λ��ȥ
				swap(nums[i], nums[nums[i]]);
			}
			//��Ⱦ�˵�����λ��������ȷ
			i++;
		}
		return -1;
	}
};
class Solution {
public:
	int minSubArrayLen(int target, vector<int>& nums) {
		int n = nums.size();
		//����������ʼֵ
		int i = 0;
		int sum = 0;
		int result = INT_MAX;
		//j���ǻ������ڵ���ֵֹ
		for (int j = 0; j<n; ++j)
		{
			sum += nums[j];
			while (sum >= target)
			{
				int subLenth = j - i + 1;
				result = min(subLenth, result);
				sum -= nums[i];
				//����������ʼֵ
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

		//���prevΪ��ǰ�ڵ��·��Ľڵ�
		//�ұ�prevΪ��ǰ�ڵ��Ϸ��Ľڵ�
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
		//root�Ǹ�������4,������������Ҫ��ͷ
		// Node* head=root;
		Node* head = root;
		Node* prev = NULL;

		_treeToDoublyList(root, prev);
		//prev����ͱ����5,Ҳ�������һ���ڵ�

		//ͷ������
		while (head->left)
		{
			head = head->left;
		}
		head->left = prev;
		prev->right = head;

		return head;
	}
};