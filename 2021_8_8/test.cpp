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

		//右移，所以k是旋转后面k个数，在旋转前面n-k个数。整体翻转
		//ps:左移就是旋转前面K个数
		// 12345->局部翻转32154->整体翻转45123 
		//但由于是链表，所以找出第n-k个节点当让他当尾。
		//但是链接关系怎么办呢,一种很巧妙的方法就是把他们最开始连成一个环，尾节点的next是头，保存下 来最后把尾节点的next置空
		int n = 0;
		ListNode* cur = head;
		ListNode* prev = nullptr;
		while (cur)
		{
			prev = cur;
			cur = cur->next;
			++n;
		}

		//N为长度，左旋的时候，K==N就相当于不旋转，那么右旋就是N-K==N
		int times = n - k%n;
		if (times == n)
		{
			return head;
		}
		prev->next = head;
		while (times--)
		{
			//prev为最后一个节点，让他走times步找到新的尾节点
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
		//优化，不用set就可以去重
		int n = nums.size();
		vector<vector<int>> vv;
		sort(nums.begin(), nums.end());
		for (int i = 0; i<n; ++i)
		{
			//固定一个数，去找和他相反的数，之和就是0
			// -4   去找和为4的两个数


			if (i>0 && nums[i] == nums[i - 1])
			{
				//和上一个元素一样，就不进行本轮的查找
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