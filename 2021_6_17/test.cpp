/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
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
public:
	bool _isSymmetric(TreeNode* A, TreeNode* B)
	{
		//都为空true
		if (A == NULL&&B == NULL)
			return true;
		//有一个为空false
		if (A == NULL || B == NULL)
			return false;
		//不相等false
		if (A->val != B->val)
			return false;

		return _isSymmetric(A->left, B->right) && _isSymmetric(A->right, B->left);


	}
	bool isSymmetric(TreeNode* root) {

		return _isSymmetric(root, root);
	}
};
class Solution {
public:
	//以当前节点为根，是否为子结构(用来判断的方法)
	bool recur(TreeNode* A, TreeNode* B)
	{
		//先判断B，因为有可能A,B都是空，这种情况仍然是true。
		if (B == NULL)
			return true;
		//B不为空时，A已经是空了,肯定false
		if (A == NULL || A->val != B->val)
			return false;

		return recur(A->left, B->left) && recur(A->right, B->right);
	}
	//用A的每个节点，都去判断是否有B这个子结构
	bool isSubStructure(TreeNode* A, TreeNode* B) {
		if (A == NULL || B == NULL)
			return false;

		//A节点有没有B这个子结构||A节点左有没有B这个子结构||A节点右有没有这个子结构
		return recur(A, B) || isSubStructure(A->left, B) || isSubStructure(A->right, B);
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
public:
	TreeNode* mirrorTree(TreeNode* root) {
		if (root == NULL)
			return NULL;

		TreeNode* temp = root->left;
		root->left = mirrorTree(root->right);
		root->right = mirrorTree(temp);

		return root;
	}
};
