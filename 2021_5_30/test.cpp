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
	//dict.insert(pair<string, string>("nihao", "���"));
	//pair<string, string> pp("breakfast", "���");
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
	//	//find�ҵ�����ָ��ýڵ�ĵ�����
	//	if (it != countMap.end())
	//	{
	//		(it->second)++;
	//	}
	//	else
	//	{
	//		// find�Ҳ������᷵��countMap.end()ָ��
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


	//��Ҫע�������ʧЧ
	/*countMap.erase(it);*/
	//if (it != countMap.end())
	//{
	//	cout << "�ұ��ˣ�������: " << it->first;
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
		//��k������С��
		if (x->second != y->second)
		{
			
			return x->second > y->second;
		}
		else
		{   //������ͬ����asii�Ƚϣ�Ҫ����asiiС�ķ�ǰ�棬Ҫ����ѷţ��Ȱ�С�ķź��棬�Ȼ���ת��ȥǰ���ˡ�
			return x->first < y->first;
		}
	}
};
void testFriut1(const vector<string>& str,int k)
{

	map<string, int> countMap;
	//asii�������źã�ȥ�ز�ͳ�Ƴ�����
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
//lessĬ�϶����ã�greater��Ҫ��ͷ�ļ�
void testFriut2(const vector<string>& str, int k)
{
	//asii��Ĭ��������ȥ��
	map<string, int> count_map;
	for (auto& e : str)
	{
		count_map[e]++;
	}

	

	//����������
	multimap<int,string,greater<int>> multimapCount;
	
	//������÷�Χfor���룬�����
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
	vector<string> v = { "����", "��֦","����", "����","�㽶", "�㽶","�㽶","����","��","����" };

	testFriut1(v,3);
	cout << endl;
	testFriut2(v, 3);
	return 0;
}
