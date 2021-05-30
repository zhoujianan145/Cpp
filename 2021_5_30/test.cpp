#include<iostream>
#include<set>
#include<string>
#include<map>
#include<vector>
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

#include<queue>
typedef map<string, int>::iterator count_it;
class Greater
{
public:
	bool operator()(const count_it& x, const count_it y)
	{
		//建k个数的小堆
		if (x->second != y->second)
		{
			
			return x->second > y->second;
		}
		else
		{   //次数相同，按asii比较，要想让asii小的放前面，要按大堆放，先把小的放后面，等会逆转就去前面了。
			return x->first < y->first;
		}
	}
};
void testFriut1(const vector<string>& str,int k)
{

	map<string, int> countMap;
	//asii按升序排好，去重并统计出次数
	for (auto& e : str)
	{
		countMap[e]++;
	}
	priority_queue<count_it, vector<count_it>, Greater> LitteHeap;

	count_it it = countMap.begin();
	while (k--)
	{
		LitteHeap.push(it);
		it++;
	}

	while(it!=countMap.end())
	{
		if (it->second > LitteHeap.top()->second)
		{
			LitteHeap.pop();
			LitteHeap.push(it);	
		}
		it++;
	}
	vector<string> v;
	while (!LitteHeap.empty())
	{
		v.push_back(LitteHeap.top()->first);
		LitteHeap.pop();
	}
	reverse(v.begin(), v.end());
	for (auto& e : v)
	{
		cout << e << " ";
	}
}

#include <functional>
//less默认都能用，greater就要包头文件
void testFriut2(const vector<string>& str, int k)
{
	//asii码默认升序，且去重
	map<string, int> count_map;
	for (auto& e : str)
	{
		count_map[e]++;
	}

	

	//次数按降序
	multimap<int,string,greater<int>> multimapCount;
	
	//这可以用范围for插入，都差不多
	count_it it = count_map.begin();
	while (it != count_map.end())
	{
		multimapCount.insert(make_pair(it->second,it->first));
		it++;
	}
	vector<string> v;
	auto it1 = multimapCount.begin();
	while (k--)
	{
		v.push_back(it1->second);
		it1++;
	}
	for (auto& e : v)
	{
		cout << e << " ";
	}
}
int main()
{
	vector<string> v = { "西瓜", "荔枝","橘子", "西瓜","香蕉", "香蕉","香蕉","橙子","梨","柚子" };

	testFriut1(v,3);
	cout << endl;
	testFriut2(v, 3);
	return 0;
}
