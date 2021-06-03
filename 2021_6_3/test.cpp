#include"AVLTree.hpp"
#include<vector>
#include<string>

void test1(vector<int>& v)
{
	AVLTree<int, int> avl;

	for (auto& e : v)
	{
		avl[e]++;
	}
	cout << "-------中序遍历查看是否有序------------" << endl;
	cout << endl;
	cout << "K代表元素，V代表出现次数" << endl;
	cout << endl;
	avl.Inorder();
	cout << endl;
	cout << "-------后序遍历判断是否平衡------------" << endl;
	cout << endl;
	cout << "每个节点对应的平衡因子"<< endl;
	cout << endl;
	avl.IsBalance();
}
int main()
{
	
	//vector<int> v1 = { 16,16, 3, 7, 11, 9, 26,9,11, 18, 14, 15 };
	//vector<int> v2 = { 4, 2, 6, 1, 3, 5, 15, 7, 16, 14 };
	//test1(v1);
	/*test1(v2);*/
	string s="1213";
	s = '"' + s + '"';
	cout << s << endl;
	return 0;
}