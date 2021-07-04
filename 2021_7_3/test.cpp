class Solution {
private:
	bool recur(int left, int root, vector<int>& postorder)
	{
		//一个节点，就返回true
		if (left >= root) return true;

		int index = left;
		//最前面是左树，肯定是小于根的，一直走
		while (postorder[index]<postorder[root]) index++;

		//停下，说明到了右树
		//但得先保存index等会用它去遍历左树和右树[0,index-1][index,right-1]
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

		//错误集合总和
		int nums_sum = 0;
		for (auto& e : nums)
		{
			nums_sum += e;
		}
		//set总和
		int set_sum = 0;
		for (auto& e : tal)
		{
			set_sum += e;
		}
		//正常的集合总和
		int sum = 0;
		for (int i = 1; i <= nums.size(); ++i)
		{
			sum += i;
		}
		//重复的
		int ret1 = nums_sum - set_sum;
		//缺失的
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