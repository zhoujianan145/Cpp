#include<iostream>
#include<list>
#include<vector>

using namespace std;

int main()
{
	vector<int> ar = { 1, 2, 3, 4, 0, 5, 6, 7, 8, 9 };

	list<int> l1(ar.begin(), ar.end());

	list<int>::iterator it = l1.begin();

	while (it != l1.end())

	{

		if (*it != 0)
			cout << *it;
		else
            l1.erase(it);
		it++;
}
	return 0;
}