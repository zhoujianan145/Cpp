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
			return -1;//����return 0��ʾû�ҵ����������ﷵ�ص���λ�á�����0�±�����Чֵ�أ�
		}
	}
	int rightPos(vector<int>& nums, int target)
	{
		int left = 0;
		int right = nums.size() - 1;

		while (left<right)
		{


			//int mid=left+(right-left)/2;
			//�����nums[mid]<target���жϵĻ�,��nums[mid]==target�ͻ���right=mid;�ҵ�������ߵ�λ��
			//�����nums[mid]>target���жϵĻ�,��nums[mid]==target�ͻ�ʹleft=mid;�ͻ�������ߵ�Ԫ��,���Ǵ�ʱ�����Ȼ��mid=left+(right-left)/2,�Ļ�����Ԫ�ػ�����ѭ��������[8,10],mid����0���´�left=mid����0

			int mid = left + (right - left + 1) / 2;//����ȡ��,����Ԫ�ص�ʱ��,mid=1,Ȼ��right=mid-1,��ֹͣѭ����
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

		//��һ���������������������ж��leftPos������������ߵģ�rightPos�����������ұߵ� 
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
		//�����곤�ȣ����»���
		l1 = headA;
		l2 = headB;
		//��LenAʼ���ǳ����Ǹ�
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
			//��������С�ڵ����
			// else if(nums[mid]<mid)
			// {
			//     cout<<"sakjda"<<endl;
			// }
		}
		//�������أ�����һ��Ԫ��û�в飬�ڼ��һ��
		if (nums[left] != left)
		{
			return left;
		}
		//����Ԫ�ز����,�����Ԫ�ص���һ��λ��
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
			return;//�ҳ�������˳�����ݹ���
		}

		ReInorder(root->left, k);
	}

public:
	int kthLargest(TreeNode* root, int k) {
		//�������Ϊ���򡣵��˼�Ҫ��K������Ӧ���ǽ���
		//������������Ϳ���
		ReInorder(root, k);
		return ret;
	}
};