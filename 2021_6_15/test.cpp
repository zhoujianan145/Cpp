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
	TreeNode* pruneTree(TreeNode* root) {

		if (root == nullptr)
			return nullptr;
		//为什么不能写在这，可以想想先序遍历了
		//  if(root->left==nullptr&&root->right==nullptr&&root->val==0)
		//  return nullptr;


		root->left = pruneTree(root->left);
		root->right = pruneTree(root->right);

		//必须先去判断左右子树，在判断当前节点
		if (root->left == nullptr&&root->right == nullptr&&root->val == 0)
			return nullptr;

		return root;
	}
};