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
		//��Ϊ��true
		if (A == NULL&&B == NULL)
			return true;
		//��һ��Ϊ��false
		if (A == NULL || B == NULL)
			return false;
		//�����false
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
	//�Ե�ǰ�ڵ�Ϊ�����Ƿ�Ϊ�ӽṹ(�����жϵķ���)
	bool recur(TreeNode* A, TreeNode* B)
	{
		//���ж�B����Ϊ�п���A,B���ǿգ����������Ȼ��true��
		if (B == NULL)
			return true;
		//B��Ϊ��ʱ��A�Ѿ��ǿ���,�϶�false
		if (A == NULL || A->val != B->val)
			return false;

		return recur(A->left, B->left) && recur(A->right, B->right);
	}
	//��A��ÿ���ڵ㣬��ȥ�ж��Ƿ���B����ӽṹ
	bool isSubStructure(TreeNode* A, TreeNode* B) {
		if (A == NULL || B == NULL)
			return false;

		//A�ڵ���û��B����ӽṹ||A�ڵ�����û��B����ӽṹ||A�ڵ�����û������ӽṹ
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
