#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int from = 0;
	int to = 0;

	while (cin >> from >> to)
	{
		vector<long long> dp(81, 0);
		dp[1] = 1;
		dp[2] = 1;
		for (int i = 2; i<80; i++)
		{
			dp[i + 1] = dp[i] + dp[i - 1];
		}
		int count = 0;
		for (int i = from; i <= to; i++)
		{
			count += dp[i];
		}
		cout << count << endl;
	}

	return 0;
}
#include <iostream>
#include <string>

using namespace std;

int main(){
	string str, s;
	int count = 0;
	while (cin >> str >> s){
		count = 0;
		size_t pos = 0;
		//while((pos = str.find(s)) != string::npos){
		//    str.erase(pos, pos + s.size());
		//    ++count;
		//}
		while ((pos = str.find(s, pos)) != string::npos){
			pos += s.size();
			++count;
		}
		cout << count << endl;
	}
	return 0;
}
