#include"List.hpp"

namespace zjn
{
	void test1()
	{
		list<int> l1;
		l1.push_back(1);
		l1.push_back(2);
		l1.push_back(3);

		list<int>::iterator it = l1.begin();
		while (it != l1.end())
		{
			std::cout << *it << " ";
			++it;
		}
		std::cout << " " <<std::endl;
	
		l1.pop_back();
		l1.pop_front();
		for (const auto& e : l1)
		{
			std::cout << e << " ";
		}

	}
	void test2()
	{
		list<int> l1;
		l1.push_back(1);
		l1.push_back(3);
		l1.push_back(1);
		l1.push_back(4);
		l1.push_back(5);

		list<int> l2(l1);
		
	}
	void print(const list<int>& l1)
	{
		list<int>::const_iterator it = l1.begin();
		while (it != l1.end())
		{
			//*it = 1;
			std::cout << *it << " ";
			it++;
		}
		
	}
}
int main()
{
	//zjn::list<int> l1;
	//l1.push_back(1);
	//l1.push_back(2);
	//l1.push_back(3);

	zjn::test1();
	
	return 0;
}