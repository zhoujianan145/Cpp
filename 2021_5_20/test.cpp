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
	vector<vector<int>> levelOrder(TreeNode* root) {


		vector<vector<int>> vv;

		if (root == nullptr)
			return vv;
		queue<TreeNode*> q;
		q.push(root);

		while (!q.empty())
		{
			int levelsize = q.size();
			vector<int> v;
			while (size--)
			{
				TreeNode* front = q.front();
				q.pop();
				v.push_back(front->val);

				if (front->left)
					q.push(front->left);
				if (front->right)
					q.push(front->right);
			}
			vv.push_back(v);
		}
		return vv;
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
	bool FindNode(TreeNode* root, TreeNode* x)
	{
		if (root == NULL)
			return false;

		if (root == x)
			return true;

		return FindNode(root->left, x) || FindNode(root->right, x);
	}
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (root == NULL)
			return NULL;
		//假如祖先是自己，返回
		if (p == root || q == root)
			return root;

		bool pInleft, pInright, qInleft, qInright;

		pInleft = FindNode(root->left, p);
		pInright = !pInleft;

		qInleft = FindNode(root->left, q);
		qInright = !qInleft;

		//一左一右直接返回根
		if ((pInleft&&qInright) || (qInleft&&pInright))
			return root;
		//都在左，递归判断左树
		else if (pInleft&&qInleft)
			return lowestCommonAncestor(root->left, p, q);
		//递归判断右树
		else
			return lowestCommonAncestor(root->right, p, q);

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
	vector<int> levelOrder(TreeNode* root) {
		vector<int> v;
		if (root == NULL)
			return v;
		queue<TreeNode*> q;
		q.push(root);
		while (!q.empty())
		{
			TreeNode* node = q.front();
			q.pop();
			v.push_back(node->val);

			if (node->left)
				q.push(node->left);
			if (node->right)
				q.push(node->right);
		}

		return v;

	}
};