
#include"BSTree.hpp"
#include<string>

int main()
{
	//BSTree<int> Tree;
	//Tree.Insert(5);
	//Tree.Insert(4);
	//Tree.Insert(1);
	//Tree.Insert(8);
	//Tree.Insert(6);
	//Tree.Inorder();
	//
	//Tree.Erase(4);
	//Tree.Inorder();
	//Tree.Erase(5);
	//Tree.Inorder();
	//Tree.Erase(8);

	
	/*BSTree<string, string> dict;
	dict.Insert("apple", "苹果");
	dict.Insert("orange", "橘子");
	dict.Insert("people", "人");
	dict.Insert("student", "学生");
	dict.Insert("milk", "牛奶");
	dict.Insert("paper", "卫生纸");
	dict.Insert("paper", "啦啦啦");
	dict.Insert("Big apple", "苹果");
	dict.Inorder();*/
	//string str;
	//while (cin >> str)
	//{
	//	BSTreeNode<string, string>* ret = dict.Find(str);
	//	if (ret)
	//	{
	//		cout << ret->_val << endl;
	//	}
	//	else
	//	{
	//		cout << "字典中不存在"<< endl;
	//	}
	//	
	//}
	string strArry[] = { "苹果", "香蕉", "西瓜", "西瓜", "香蕉" };
	//前面存名字，后面存次数
	BSTree<string, int> countTree;
	for (auto& str : strArry)
	{
		auto ret = countTree.Find(str);
		if (ret == nullptr)
		{
			//没有就插入,第一次插入str和1
		  	countTree.Insert(str, 1);
		}
		else
		{
			//第二次往上，就++次数
			ret->_val++;
		}
	}
	countTree.Inorder();

	return 0;
}

