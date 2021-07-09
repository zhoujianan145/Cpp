class Solution {
private:
	int leftPos(vector<int>& nums, int target)
	{
		int left = 0;
		int right = nums.size() - 1;

		while (left<right)
		{
			int mid = left + (right - left) / 2;

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
		{
			return left;
		}
		else
		{
			return -1;//不能return 0表示没找到，我们这里返回的是位置。假如0下标是有效值呢？
		}
	}
	int rightPos(vector<int>& nums, int target)
	{
		int left = 0;
		int right = nums.size() - 1;

		while (left<right)
		{


			//int mid=left+(right-left)/2;
			//如果按nums[mid]<target来判断的话,当nums[mid]==target就会是right=mid;找到的是左边的位置
			//如果按nums[mid]>target来判断的话,当nums[mid]==target就会使left=mid;就会跳过左边的元素,但是此时如果仍然用mid=left+(right-left)/2,的话两个元素会有死循环。例如[8,10],mid等于0，下次left=mid还是0

			int mid = left + (right - left + 1) / 2;//向上取整,两个元素的时候,mid=1,然后right=mid-1,就停止循环了
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
	int search(vector<int>& nums, int target) {

		if (nums.size() == 0)
			return 0;

		//有一个他们俩都会搜索到，有多个leftPos会搜索出最左边的，rightPos会搜索出最右边的 
		int left = leftPos(nums, target);
		int right = rightPos(nums, target);

		if (left == -1)
		{
			return 0;
		}
		else
		{
			return right - left + 1;
		}

	}
};

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
class Solution {
public:
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		ListNode* l1 = headA;
		ListNode* l2 = headB;

		int LenA = 0;
		while (l1)
		{
			LenA++;
			l1 = l1->next;
		}

		int LenB = 0;
		while (l2)
		{
			LenB++;
			l2 = l2->next;
		}
		//计算完长度，更新回来
		l1 = headA;
		l2 = headB;
		//让LenA始终是长的那个
		if (LenB>LenA)
		{
			swap(l1, l2);
			swap(LenA, LenB);
		}
		int dic = LenA - LenB;
		while (dic--)
		{
			l1 = l1->next;
		}

		while (l1)
		{
			if (l1 == l2)
				return l1;
			l1 = l1->next;
			l2 = l2->next;
		}
		return NULL;


	}
};
class Solution {
public:
	int missingNumber(vector<int>& nums) {
		int left = 0;
		int right = nums.size() - 1;

		while (left<right)
		{
			int mid = left + (right - left + 1) / 2;

			if (nums[mid]>mid)
			{
				right = mid - 1;
			}
			else // else if(nums[mid]>mid)
			{
				left = mid;
			}
			//不可能有小于的情况
			// else if(nums[mid]<mid)
			// {
			//     cout<<"sakjda"<<endl;
			// }
		}
		//这样返回，还有一个元素没有查，在检查一下
		if (nums[left] != left)
		{
			return left;
		}
		//其他元素查过了,是这个元素的下一个位置
		return left + 1;
	}
};
class Solution {
public:
	int translateNum(int num) {
		string str = to_string(num);
		int n = str.size();
		int a = 1;
		int b = 1;
		for (int i = 2; i <= n; ++i)
		{
			int c = 0;
			string temp = str.substr(i - 2, 2);
			if (temp >= "10"&&temp <= "25")
			{
				c = a + b;
			}
			else
			{
				c = b;
			}
			a = b;
			b = c;
		}

		return b;


	}
};
class Solution {
public:
	int translateNum(int num) {
		string str = to_string(num);
		int n = str.size();
		vector<int> dp(n + 1, 0);
		dp[0] = 1;
		dp[1] = 1;
		for (int i = 2; i <= n; ++i)
		{
			string temp = str.substr(i - 2, 2);
			if (temp >= "10"&&temp <= "25")
			{
				dp[i] = dp[i - 2] + dp[i - 1];
			}
			else
			{
				dp[i] = dp[i - 1];
			}
		}

		return dp[n];


	}
};

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

private:
	int ret = 0;
	void ReInorder(TreeNode* root, int& k)
	{
		if (root == NULL)
			return;
		ReInorder(root->right, k);
		k--;
		if (k == 0)
		{
			ret = root->val;
			return;//找出结果就退出，别递归了
		}

		ReInorder(root->left, k);
	}

public:
	int kthLargest(TreeNode* root, int k) {
		//中序遍历为升序。但人家要第K大，所以应该是降序
		//反着中序遍历就可以
		ReInorder(root, k);
		return ret;
	}
};