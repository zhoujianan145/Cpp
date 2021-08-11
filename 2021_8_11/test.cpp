#include<iostream>
#include<vector	>
#include<string>
using namespace std;
class Solution {
public:
	void dfs(int n, int idx, string path, vector<int>& res)
	{
		if (idx == n)                           //����nλʱ��¼��ǰֵ
		{
			int num = stoi(path);               //stoi���Զ�ȥ��ǰ��0
			if (num) res.push_back(num);
			return;
		}

		for (int i = 0; i < 10; i++)          //ÿһλ��ʮ��ֵ��ѡ
		{
			path[idx] = i + '0';
			dfs(n, idx + 1, path, res);
		}
	}

	vector<int> printNumbers(int n) {
		vector<int> res;

		string path(n, 0);                      //��ʼ��һ���ַ�����n��0
		dfs(n, 0, path, res);
		return res;
	}
};
/*
// Definition for a Node.
class Node {
public:
int val;
vector<Node*> children;

Node() {}

Node(int _val) {
val = _val;
}

Node(int _val, vector<Node*> _children) {
val = _val;
children = _children;
}
};
*/

class Solution {
public:
	vector<int> preorder(Node* root) {
		stack<int>
	}
};
/*
// Definition for a Node.
class Node {
public:
int val;
vector<Node*> children;

Node() {}

Node(int _val) {
val = _val;
}

Node(int _val, vector<Node*> _children) {
val = _val;
children = _children;
}
};
*/

class Solution {
public:
	vector<vector<int>> levelOrder(Node* root) {
		vector<vector<int>> vv;
		if (root == nullptr)
		{
			return vv;
		}
		queue<Node*> q;
		q.push(root);
		while (!q.empty())
		{
			int s = q.size();
			vector<int> temp;
			while (s--)
			{
				Node* qtop = q.front();
				q.pop();

				temp.push_back(qtop->val);
				for (auto& e : qtop->children)
				{
					if (e)
					{
						q.push(e);
					}
				}
			}
			vv.push_back(temp);
		}

		return vv;
	}
};
int main()
{
	Solution().printNumbers(2);
	return 0;
}