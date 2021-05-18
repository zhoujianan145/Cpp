//class Solution {
//public:
//	vector<int> printNumbers(int n) {
//		int m = n;
//		m = pow(10, n) - 1;
//		vector<int> v(m, 0);
//		for (int i = 0; i<m; i++)
//		{
//			v[i] = i + 1;
//		}
//		return v;
//	}
//};
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
public:
	string tree2str(TreeNode* root) {
		//每次返回都会深拷贝str对象，
		string s;

		if (root == nullptr)
			return s;

		s += to_string(root->val);

		//左右子树都为空，不需要加括号
		if (root->left == nullptr&&root->right == nullptr)
			return s;

		//无论左是不是空，都加左括号，递归左，加右括号
		s += '(';
		s += tree2str(root->left);
		s += ')';


		if (root->right != nullptr)
		{
			//右不为空,才，加左括号，递归右，加右括号
			s += '(';
			s += tree2str(root->right);
			s += ')';
		}

		return s;

	}
};