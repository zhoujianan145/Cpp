
#include<iostream>
#include<deque>
#include<vector>
#include<list>
using namespace std;


#include"queue.hpp"
#include"stack.hpp"

//��������֧�ֵ���������ΪҪ��֤�Լ�������
void test1()
{
	zjn::stack<int> d1;
	zjn::stack<int, vector<int>> v1;
	zjn::stack<int, list<int>>  l1;

	zjn::queue<int> d2;
	
	//û��ͷɾ
	/*zjn::queue<int, vector<int>> v3;*/
	zjn::queue<int, list<int>> l2;
}

int main()
{
	return 0;
}
