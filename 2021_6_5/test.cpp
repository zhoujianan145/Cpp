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
	//״̬����: dp[i][j]�����i��j�ĸ��ӿ��Ե���
	//ת�Ʒ���: dp[i][j]=(dp[i-1][j] || dp[i][j-1]) && sum<=k
	//          i>0,j>0ʱ����ߣ��ϱ���һ��Ϊtrue����sum<=k,��˵���ܹ�����
	//          i<=0ʱ˵��û�����棬ֻ�ܴ���߹�����j<=0ʱ˵��û����ߣ�ֻ�ܴ�����������
	//��ʼ��:   dp[0][0]=true�����ⶼ���Ե���[0,0]�ĸ���
	//����ֵ:   dp[m-1][n-1]�����m-1��n-1���ӿ��Ե������һ����������Ϊtrue++������count�ͺ��ˡ�          
	int movingCount(int m, int n, int k) {
		vector<vector<bool>> vv(m, vector<bool>(n, false));

		vv[0][0] = true;
		//[0,0]��һ��
		int count = 1;
		for (int i = 0; i<m; i++)
		{
			for (int j = 0; j<n; j++)
			{
				int sum = i / 10 + i % 10 + j / 10 + j % 10;
				//�����������������ԡ�
				//iΪ0�����ж��ܲ��ܴ��������jΪ0���ж��ܲ��ܴ�������
				//�������ֻҪ�ܴ�һ������˵��������,ͬʱ�������廹Ҫ && sum<=k
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