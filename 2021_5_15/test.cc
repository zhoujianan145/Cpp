
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
	dict.Insert("apple", "ƻ��");
	dict.Insert("orange", "����");
	dict.Insert("people", "��");
	dict.Insert("student", "ѧ��");
	dict.Insert("milk", "ţ��");
	dict.Insert("paper", "����ֽ");
	dict.Insert("paper", "������");
	dict.Insert("Big apple", "ƻ��");
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
	//		cout << "�ֵ��в�����"<< endl;
	//	}
	//	
	//}
	string strArry[] = { "ƻ��", "�㽶", "����", "����", "�㽶" };
	//ǰ������֣���������
	BSTree<string, int> countTree;
	for (auto& str : strArry)
	{
		auto ret = countTree.Find(str);
		if (ret == nullptr)
		{
			//û�оͲ���,��һ�β���str��1
		  	countTree.Insert(str, 1);
		}
		else
		{
			//�ڶ������ϣ���++����
			ret->_val++;
		}
	}
	countTree.Inorder();

	return 0;
}

