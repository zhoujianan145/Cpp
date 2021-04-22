#include"priority.hpp"
////#include<iostream>
////#include<stdio.h>
////int main()
////{
////	printf("%s,%5.3s", "computer", "computer");
////	return 0;
////}
//#include<iostream>
//#include<queue>
//
//using namespace std;
//
//int main()
//{
//	priority_queue<int> pq;
//	pq.push(1);
//	pq.push(5);
//	pq.push(3);
//	pq.push(6);
//	pq.push(4);
//	while (!pq.empty())
//	{
//		cout << pq.top() <<" ";
//		pq.pop();
//
//	}
//	return 0;
//}
//void test2()
//{
//		std::priority_queue<int> pq;
//		pq.push(1);
//		pq.push(5);
//		pq.push(7);
//		pq.push(4);
//		pq.push(6);
//		pq.push(8);
//		while (!pq.empty())
//		{
//			cout << pq.top() <<" ";
//			pq.pop();
//	
//		}
//}

void test()
{
	zjn::priority_queue<int,vector<int>,zjn::greater<int>> pq;
			pq.push(2);
			pq.push(5);
			pq.push(7);
			pq.push(4);
			pq.push(6);
			pq.push(8);
					while (!pq.empty())
					{
						cout << pq.top() <<" ";
						pq.pop();
				
					}
					
}
int main()
{
	zjn::test();
	test();
	
	return 0;
}