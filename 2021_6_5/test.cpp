x/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		if (l1 == NULL&&l2 == NULL)
			return NULL;

		ListNode* dummy = new ListNode;
		ListNode* prev = dummy;
		while (l1&&l2)
		{
			if (l1->val <= l2->val)
			{
				prev->next = l1;
				prev = l1;
				l1 = l1->next;

			}
			else
			{
				prev->next = l2;
				prev = l2;
				l2 = l2->next;

			}
		}
		if (l1)
		{
			prev->next = l1;
		}
		if (l2)
		{
			prev->next = l2;
		}
		ListNode* head = dummy->next;
		delete dummy;
		return head;

	}
}; class Solution {
public:
	//状态定义: dp[i][j]代表第i和j的格子可以到达
	//转移方程: dp[i][j]=(dp[i-1][j] || dp[i][j-1]) && sum<=k
	//          i>0,j>0时，左边，上边有一个为true，且sum<=k,就说明能过来了
	//          i<=0时说明没有上面，只能从左边过来。j<=0时说明没有左边，只能从上面下来。
	//初始化:   dp[0][0]=true，任意都可以到达[0,0]的格子
	//返回值:   dp[m-1][n-1]代表第m-1，n-1格子可以到达。定义一个计数器，为true++，返回count就好了。          
	int movingCount(int m, int n, int k) {
		vector<vector<bool>> vv(m, vector<bool>(n, false));

		vv[0][0] = true;
		//[0,0]算一个
		int count = 1;
		for (int i = 0; i<m; i++)
		{
			for (int j = 0; j<n; j++)
			{
				int sum = i / 10 + i % 10 + j / 10 + j % 10;
				//从上面或左边来都可以。
				//i为0，就判断能不能从左边来。j为0就判断能不能从上面来
				//其余情况只要能从一边来就说明可以来,同时他们整体还要 && sum<=k
				if (((i>0 && vv[i - 1][j]) || (j>0 && vv[i][j - 1])) && sum <= k)
				{
					vv[i][j] = true;
					count++;
				}

			}
		}
		return count;


	}
};