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
	ListNode* rotateRight(ListNode* head, int k) {
		if (head == nullptr || head->next == nullptr || k == 0)
			return head;

		//���ƣ�����k����ת����k����������תǰ��n-k���������巭ת
		//ps:���ƾ�����תǰ��K����
		// 12345->�ֲ���ת32154->���巭ת45123 
		//�����������������ҳ���n-k���ڵ㵱������β��
		//�������ӹ�ϵ��ô����,һ�ֺ�����ķ������ǰ������ʼ����һ������β�ڵ��next��ͷ�������� ������β�ڵ��next�ÿ�
		int n = 0;
		ListNode* cur = head;
		ListNode* prev = nullptr;
		while (cur)
		{
			prev = cur;
			cur = cur->next;
			++n;
		}

		//NΪ���ȣ�������ʱ��K==N���൱�ڲ���ת����ô��������N-K==N
		int times = n - k%n;
		if (times == n)
		{
			return head;
		}
		prev->next = head;
		while (times--)
		{
			//prevΪ���һ���ڵ㣬������times���ҵ��µ�β�ڵ�
			prev = prev->next;
		}
		head = prev->next;
		prev->next = nullptr;

		return head;


	}
};

class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		//�Ż�������set�Ϳ���ȥ��
		int n = nums.size();
		vector<vector<int>> vv;
		sort(nums.begin(), nums.end());
		for (int i = 0; i<n; ++i)
		{
			//�̶�һ������ȥ�Һ����෴������֮�;���0
			// -4   ȥ�Һ�Ϊ4��������


			if (i>0 && nums[i] == nums[i - 1])
			{
				//����һ��Ԫ��һ�����Ͳ����б��ֵĲ���
				continue;
			}

			int left = i + 1;
			int right = n - 1;
			int target = -nums[i];
			while (left<right)
			{
				int sum = nums[left] + nums[right];
				if (sum == target){
					vector<int> v(3, 0);
					v[0] = nums[i];
					v[1] = nums[left];
					v[2] = nums[right];
					vv.push_back(v);
					while (left<right && nums[left] == nums[++left]);

					while (left<right && nums[right] == nums[--right]);
				}
				else if (sum < target){
					left++;
				}
				else
				{
					right--;
				}
			}


		}
		return vv;
	}
};
class Solution {
public:
	int compareVersion(string version1, string version2) {
		int i = 0;
		int j = 0;
		int n = version1.size();
		int m = version2.size();
		while (i<n || j<m)
		{
			int a = 0;
			int b = 0;
			while (i<n && version1[i] != '.')
			{
				a = a * 10 + version1[i] - '0';
				++i;
			}
			while (j<m && version2[j] != '.')
			{
				b = b * 10 + version2[j] - '0';
				++j;
			}
			if (a>b)
			{
				return 1;
			}
			else if (a<b)
			{
				return -1;
			}
			++i;
			++j;
		}
		return 0;
	}
};