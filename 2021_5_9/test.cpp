//#include<iostream>
//#include<string>
//#include<vector>
//using namespace std;
//
//int  main()
//{
//	string s;
//	while (getline(cin, s))
//	{
//
//		bool flag = false;
//		string str;
//		vector<string> vet;
//		for (int i = 0; i<s.size(); i++)
//		{
//			if (flag)
//			{
//				str += s[i];
//				if (s[i] == '\"')
//				{
//					vet.push_back(str);
//					str = "";
//					flag = false;
//				}
//			}
//			else
//			{
//				if (s[i] != ' ')
//				{
//					str += s[i];
//				}
//				else
//				{
//					vet.push_back(str);
//					str = "";
//				}
//				if (s[i] == '\"')
//				{
//					flag = true;
//				}
//			}
//		}
//		cout << str.size() << endl;
//		for (auto& e : vet)
//		{
//			cout << e << endl;
//		}
//	}
//	return 0;
//}

#include<iostream>
#include<string>
#include<vector>
using namespace std;

int  main()
{
	string s;
	while (getline(cin, s))
	{

		bool flag = false;
		string str;
		vector<string> vet;
		for (int i = 0; i<s.size(); i++)
		{
			if (flag)
			{
				if (s[i] == '\"')
				{
					if (str != "")
					{
						vet.push_back(str);
					//}
					str = "";
					flag = false;
				}
				str += s[i];
				

			}
			else
			{
				if (s[i] == '\"')
				{
					flag = true;
				}
				else if (s[i] != ' ')
				{
					str += s[i];
				}
				else
				{
					if (str!= "")
					{
						vet.push_back(str);
						str = "";
					}
				}

			}
		}
		if (str != "")
		{
			vet.push_back(str);
		}
		cout << vet.size() << endl;
		for (auto& e : vet)
		{
			cout << e << endl;
		}
	}
	return 0;
}