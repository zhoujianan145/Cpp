class Solution {
private:
	bool recur(int left, int root, vector<int>& postorder)
	{
		//һ���ڵ㣬�ͷ���true
		if (left >= root) return true;

		int index = left;
		//��ǰ�����������϶���С�ڸ��ģ�һֱ��
		while (postorder[index]<postorder[root]) index++;

		//ͣ�£�˵����������
		//�����ȱ���index�Ȼ�����ȥ��������������[0,index-1][index,right-1]
		int index1 = index;
		while (postorder[index]>postorder[root]) index++;
		return index == root && recur(left, index - 1, postorder) && recur(index, root - 1, postorder);


	}
public:
	bool verifyPostorder(vector<int>& postorder) {

		return recur(0, postorder.size() - 1, postorder);
	}
};
class Solution {
public:
	vector<int> findErrorNums(vector<int>& nums) {
		unordered_set<int> tal(nums.begin(), nums.end());

		//���󼯺��ܺ�
		int nums_sum = 0;
		for (auto& e : nums)
		{
			nums_sum += e;
		}
		//set�ܺ�
		int set_sum = 0;
		for (auto& e : tal)
		{
			set_sum += e;
		}
		//�����ļ����ܺ�
		int sum = 0;
		for (int i = 1; i <= nums.size(); ++i)
		{
			sum += i;
		}
		//�ظ���
		int ret1 = nums_sum - set_sum;
		//ȱʧ��
		int ret2 = sum - set_sum;
		vector<int> ret(2, 0);
		ret[0] = ret1;
		ret[1] = ret2;

		return ret;

	}
};
/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode() : val(0), left(nullptr), right(nullptr) {}
*     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
*     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
* };
*/
class Solution {
private:
	bool inorder(TreeNode* root, long& prev)
	{
		if (root == nullptr)
			return true;

		bool left = inorder(root->left, prev);

		if (root->val <= prev)
			return false;
		prev = root->val;

		bool right = inorder(root->right, prev);

		return left&&right;

	}
public:
	bool isValidBST(TreeNode* root) {
		if (root == nullptr)
			return true;
		long prev = LONG_MIN;
		return inorder(root, prev);



	}
};