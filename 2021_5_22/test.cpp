

#include<iostream>
#include<stack>

using namespace std;
 struct TreeNode {
    int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
	bool FindPath(TreeNode* root, stack<TreeNode*>& st, TreeNode* x)
	{
		if (root == NULL)
			return false;

		st.push(root);

		if (root == x)
			return true;

		if (FindPath(root->left, st, x))
			return true;

		if (FindPath(root->right, st, x))
			return true;


		st.pop();
		return false;

	}
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		stack<TreeNode*> qPath;
		stack<TreeNode*> pPath;

		FindPath(root, pPath, p);
		FindPath(root, qPath, q);



		while (qPath.size()<pPath.size())
		{
			pPath.pop();
		}
		while (qPath.size()>pPath.size())
		{
			qPath.pop();
		}


		while (qPath.top() == qPath.top())
		{
			pPath.pop();
			qPath.pop();
		}
		return pPath.top();



	}
};

int main()
{
	TreeNode* root=new TreeNode(3);
	root->val = 3;
	TreeNode* root1=new TreeNode(5);
	root1->val = 5;
	TreeNode* root2=new TreeNode(1);
	root2->val = 1;
	TreeNode* root3 = new TreeNode(6);
	root3->val = 6;
	TreeNode* root4 = new TreeNode(2);
	root4->val = 2;
	TreeNode* root5 = new TreeNode(0);
	root5->val = 0;
	TreeNode* root6 = new TreeNode(8);
	root6->val = 8;

	root->left =  root1;
	root->right = root2;

	root1->left = root3;
	root1->right = root4;

	root2->left = root5;
	root2->right = root6;

	cout << Solution().lowestCommonAncestor(root, root1, root2)->val << endl;


	return 0;
}