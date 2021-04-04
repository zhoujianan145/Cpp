#include<iostream>
#include<vector>
#include<list>
#include<algorithm>
using namespace std;

void print(const vector<int>& v)
{
	vector<int>::const_iterator it3 = v.begin();
	while (it3 != v.end())
	{
		cout << *it3<<" ";
		it3++;
	}
	cout<<endl;
}
int main()
{
	////无参构造
	//vector<int> v1;
	////构造10个空间初始化10个3
	//vector<int> v2(10,3);
	////拷贝构造
	//vector<int> v3(v2);
	////迭代器初始化构造
	//vector<int> v4(v2.begin(), v2.end());
	//list<int> l1(5,4);
	//vector<int> v5(l1.begin(), l1.end());
	///*for (size_t i = 0; i < v2.size(); i++)
	//{
	//	cout << v2[i] <<" ";
	//}
	//vector<int>::iterator it3 = v3.begin();
	//while (it3 != v3.end())
	//{
	//	cout << *it3;
	//	it3++;
	//}*/
	//cout << endl;
	//cout << v3.size() << endl;
	//cout << v3.capacity() << endl;
	////v3.resize(5,100);
	//v3.resize(12,5);
	//cout << v3.size() << endl;
	//cout << v3.capacity() << endl;
	//print(v3);
	vector<int> v1;
	//int sz = v1.capacity();
	//for (size_t i = 0; i < 100; i++)
	//{
	//	v1.push_back(i);
	//	if (sz != v1.capacity())
	//	{
	//		sz = v1.capacity();
	//		cout << "发生增容，现在vector的capacity为:"<<sz<< endl;
	//	}
	//}
	//string s1;
	//cout<<sizeof(s1)<<endl;
	v1.reserve(100);
	cout << v1.capacity() << endl;
	v1.push_back(5);
	v1.push_back(6);
	v1.push_back(7);
	v1.push_back(8);
	v1.push_back(9);
	//也可以直接用auto pos=find(v1.begin(), v1.end(), 5);
	vector<int>::iterator pos = find(v1.begin(), v1.end(), 5);
	//返回v1.end()就说明没找到
	if(pos != v1.end())
	{
		cout << "找到了" << endl;
		/*v1.insert(pos, 4);*/
	}
	v1.erase(pos);
	for (auto& e : v1)
	{
		cout << e << " ";
	}
	cout << endl;

	//print(v1);
	//v1.pop_back();
	//print(v1);

	return 0;
}