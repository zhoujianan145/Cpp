#include<iostream>
#include<unordered_set>
#include<vector>
#include<string>
#include<queue>
using namespace std;

//class Solution {
//public:
//	int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
//		//�ֵ�
//		unordered_set<string> dict;
//		for (auto& e : wordList)
//		{
//			dict.insert(e);
//		}
//		//���
//		unordered_set<string> vist;
//		vist.insert(beginWord);
//		queue<string> q;
//		q.push(beginWord);
//		int count = 1;
//		while (!q.empty())
//		{
//			int size = q.size();
//			//�Զ����еĵ��ʽ���ת��
//			while (size--)
//			{
//				string Tstr = q.front();
//				q.pop();
//				//�ҳ���ǰ��̣��Ҳ�����ǰ�ҹ���
//				for (int i = 0; i<Tstr.size(); i++)
//				{
//					//д����������Ϊÿ�ζԵ�һλ26����̽���������±��ԭ���Եڶ�λ������̽
//					//�����һ�� hit�� ait,bit,citһֱ��̽��
//					string Nstr = Tstr;
//					for (char j = 'a'; j <= 'z'; j++)
//					{
//						Nstr[i] = j;
//						if (Nstr == endWord)
//							return count;
//						if (dict.count(Nstr) && !vist.count(Nstr))
//						{
//							q.push(Nstr);
//							vist.insert(Nstr);
//						}
//					}
//				}
//			}
//			count++;
//		}
//		return 0;
//
//	}
//};
/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	
};

class Solution {
public:
	vector<vector<int>> levelOrder(TreeNode* root) {

		vector<vector<int>> vv;
		if (root == NULL)
			return vv;
		queue<TreeNode*> q;
		q.push(root);
		int count = 0;
		while (!q.empty())
		{
			int size = q.size();
			vector<int> temp;
			
			while (size--)
			{
				TreeNode* newNode = q.front();
				q.pop();
				temp.push_back(newNode->val);
				if (newNode->left)
					q.push(newNode->left);
				if (newNode->right)
					q.push(newNode->right);
			}
			if (count % 2 == 1)
			{
				reverse(temp.begin(), temp.end());
			}
			count++;
			vv.push_back(temp);
		}
		return vv;
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
		if (root == NULL)
			return vv;
		queue<Node*> q;
		q.push(root);

		while (!q.empty())
		{
			int size = q.size();
			vector<int> temp;
			while (size--)
			{
				Node* Tnode = q.front();
				q.pop();
				temp.push_back(Tnode->val);
				for (auto& e : Tnode->children)
				{
					if (e)
						q.push(e);
				}
			}
			vv.push_back(temp);
		}
		return vv;
	}
};
class Solution {
public:
	int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
		//�ֵ�
		unordered_set<string> dict;
		for (auto& e : wordList)
		{
			dict.insert(e);
		}
		//���
		unordered_set<string> vist;
		vist.insert(beginWord);
		queue<string> q;
		q.push(beginWord);
		int count = 1;
		while (!q.empty())
		{
			int size = q.size();
			//�Զ����е�һ�����ʽ���ת��
			while (size--)
			{
				string Tstr = q.front();
				q.pop();
				if (Tstr == endWord)//���ﷵ��Ҳ����
					return count;
				for (int i = 0; i<Tstr.size(); i++)
				{
					//д����������Ϊÿ�ζԵ�һλ26����̽���������±��ԭ���Եڶ�λ������̽
					//�����һ�� hit�� ait,bit,citһֱ��̽��
					string Nstr = Tstr;
					for (char j = 'a'; j <= 'z'; j++)
					{
						Nstr[i] = j;

						//�����ֵ��У���û�б�������
						if (dict.count(Nstr) && !vist.count(Nstr))
						{
							//���
							q.push(Nstr);
							//Ȼ����ϱ��
							vist.insert(Nstr);
						}
						//�����������ж�Ҳ����
						//  if(dict.count(Nstr)&&Nstr==endWord)
						//    return count+1;                
					}
				}
			}
			count++;
		}
		return 0;

	}
};
class Solution {
public:
	int minMutation(string start, string end, vector<string>& bank) {
		//�ʵ�
		unordered_set<string> dict;
		for (auto& e : bank)
		{
			dict.insert(e);
		}
		//���
		unordered_set<string> vist;
		vist.insert(start);
		//����
		queue<string> q;
		q.push(start);

		int count = 0;
		string str = "ACGT";
		while (!q.empty())
		{
			int size = q.size();
			while (size--)
			{
				string Tstr = q.front();
				q.pop();
				if (Tstr == end)
					return count;
				for (int i = 0; i<start.size(); i++)
				{
					string Nstr = Tstr;
					for (char j = 0; j<str.size(); j++)
					{
						Nstr[i] = str[j];
						//�ʵ�����������У���û���ֹ������
						if (dict.count(Nstr) && !vist.count(Nstr))
						{
							q.push(Nstr);
							vist.insert(Nstr);
						}
					}
				}
			}
			count++;
		}
		return -1;
	}
};
int main()
{
	TreeNode* node1 = new TreeNode(3);
	TreeNode* node2 = new TreeNode(9);
	TreeNode* node3 = new TreeNode(20);
	TreeNode* node4 = new TreeNode(15);
	TreeNode* node5 = new TreeNode(17);
	node1->left = node2;
	node1->right = node3;
	node3->left = node4;
	node4->right = node5;

	Solution().levelOrder(node1);
	return 0;
}