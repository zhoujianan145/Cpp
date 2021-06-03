#include<iostream>
#include<vector>
#include<string>
using namespace std;

void hasSpaceorPoint(string& s)
{
	for (auto& e : s)
	{
		if (e == ' ' || e == ',')
		{
			s = '"' + s + '"';
			break;
		}
	}

}
int main()
{
	int n = 0;
	while (cin >> n)
	{
		getchar();
		vector<string> v(n, "");
		for (int i = 0; i < n; i++)
		{
			getline(cin, v[i]);
		}
		int n = v.size();
		for (int i = 0; i<n; i++)
		{
			hasSpaceorPoint(v[i]);
		}
		for (int i = 0; i<n - 1; i++)
		{
			cout << v[i] << ",";
		}
		cout << v[n - 1] << endl;


	}
	return 0;
}