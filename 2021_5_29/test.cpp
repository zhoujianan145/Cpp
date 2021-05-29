#include<iostream>
#include<set>
#include<string>
#include<map>
using namespace std;

void test_set()
{
	////set<int> s1;
	//multiset<int> s1;
	//s1.insert(3);
	//s1.insert(2);
	//s1.insert(5);
	//s1.insert(10);
	//s1.insert(10);
	//s1.insert(10);
	//
	//set<int>::iterator it1 = s1.begin();

	//while (it1 != s1.end())
	//{
	//	cout << *it1<< " ";
	//	it1++;
	//	
	//}
	//cout << endl;
	string str[] = { "string", "string", "hello", "nihao", "nihao" };

	set<string> unique;
	for (auto& e : str)
	{
		unique.insert(e);
	}

	auto ret1 = find(unique.begin(), unique.end(), "hello");
	for (auto& e : unique)
	{
		if (e == *ret1)
		{
			cout << "ret1:" <<e<< endl;
		}
	}
	/*
	*ret1 = "neng";*/
	ret1=unique.erase(ret1);

	
	
	for (auto& e : unique)
	{
		if (e == *ret1)
			cout << "ret1:"<<e << "";
	}
	
	
	//for (auto& e : unique)
	//{
	//	cout << e << " ";
	//}
	//cout << endl;
}
void test_map()
{
	//map<string, string> dict;
	//dict.insert(pair<string, string>("nihao", "你好"));
	//pair<string, string> pp("breakfast", "早餐");
	//dict.insert(pp);
	//map<string, string>::iterator it = dict.begin();
	//
	//while (it != dict.end())
	//{
	//	//cout << (*it).first << ":" << (*it).second<<endl;
	//	cout << it->first << ":" << it->second << endl;
	//	it++;
	//}
	//cout << endl;
	//for (auto& e : dict)
	//{
	//	cout << e.first << ":" << e.second << endl;
	//}


	
	//for (auto& e : str)
	//{
	//	auto it = countMap.find(e);
	//	//find找到返回指向该节点的迭代器
	//	if (it != countMap.end())
	//	{
	//		(it->second)++;
	//	}
	//	else
	//	{
	//		// find找不到，会返回countMap.end()指针
	//		countMap.insert(make_pair(e, 1));
	//	}
	//}



	string str[] = { "string", "string", "hello", "nihao", "nihao" };
	map<string, int> countMap;
	for (auto& e : str)
	{
		countMap[e]++;
	}
	map<string, int>::iterator it = countMap.find("hello");

	countMap.erase(it);

	for (auto& e : countMap)
	{
		cout << e.first << ":" << e.second << "" << endl;

	}


	//需要注意迭代器失效
	/*countMap.erase(it);*/
	//if (it != countMap.end())
	//{
	//	cout << "我变了，现在是: " << it->first;
	//	
	//}




}
int main()
{
	test_map();
	return 0;
}
