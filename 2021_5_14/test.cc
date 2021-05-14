
#include"BSTree.hpp"


int main()
{
	BSTree<int> Tree;
	Tree.Insert(5);
	Tree.Insert(4);
	Tree.Insert(1);
	Tree.Insert(8);
	Tree.Insert(6);
	Tree.Inorder();
	
	return 0;
}