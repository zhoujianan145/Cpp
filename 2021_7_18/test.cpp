/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode() : val(0), next(nullptr) {}
*     ListNode(int x) : val(x), next(nullptr) {}
*     ListNode(int x, ListNode *next) : val(x), next(next) {}
* };
*/
class Solution {
public:
	ListNode* insertionSortList(ListNode* head) {
		ListNode* dummy = new ListNode;
		dummy->next = head;
		ListNode* prev = dummy;
		ListNode* cur = head;
		while (cur&&cur->next)
		{
			if (cur->val <= cur->next->val)
			{
				cur = cur->next;
			}
			else
			{
				ListNode* _next = cur->next;
				ListNode* N_next = cur->next->next;
				cur->next = N_next;

				ListNode* prev = dummy;
				while (prev->next->val <= _next->val)
				{
					prev = prev->next;
				}
				_next->next = prev->next;
				prev->next = _next;

			}
		}
		return dummy->next;
	}
};
class Solution {
public:
	int minSubArrayLen(int target, vector<int>& nums) {
		int n = nums.size();
		int j = 0;
		int sum = 0;
		int minRet = INT_MAX;
		for (int i = 0; i<n; ++i)
		{
			sum += nums[i];
			while (sum >= target)
			{
				int temp = i - j + 1;
				minRet = min(minRet, temp);
				sum -= nums[j];
				j++;
			}
		}
		return minRet == INT_MAX ? 0 : minRet;
	}
};
class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		int n = nums.size();

		int ret = nums[0];
		int maxN = nums[0];
		for (int i = 1; i<n; ++i)
		{
			maxN = max(maxN + nums[i], nums[i]);
			ret = max(maxN, ret);
		}


		return ret;
	}
};