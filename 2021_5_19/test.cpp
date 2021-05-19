//#include<iostream>
//#include<limits.h>
//#include<string>
//using namespace std;
//
//int main()
//{
//	string str1;
//	string str2;
//	while (getline(cin, str1) && getline(cin, str2))
//	{
//		int len = INT_MIN;
//		for (int i = 0; i<str1.size(); i++)
//		{
//			for (int j = 0; j<str2.size(); j++)
//			{
//				int lenIndex = j;
//				while (str1[i] == str2[j])
//				{
//					i++;
//					j++;
//				}
//
//				len = j - lenIndex + 1>len ? j - lenIndex + 1 : len;
//				j++;
//			}
//		}
//		cout << len << endl;
//	}
//	return 0;
//}
//
//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//
//int main()
//{
//	int T = 0;
//	int n = 0;
//	int k = 0;
//	vector<int> v;
//	while (cin >> T)
//	{
//		while (T--)
//		{
//			while (cin >> n >> k)
//			{
//				while (k--)
//				{
//
//					for (int i = 0; i<2 * n; i++)
//					{
//						cin >> v[i];
//					}
//					int leftHand = n - 1;
//					int rightHand = 2 * n - 1;
//					vector<int> tempv(v.size(), 0);
//					for (int i = 0; i<tempv.size(); i += 2)
//					{
//						tempv[i] = v[rightHand--];
//						tempv[i + 1] = v[leftHand--];
//					}
//					reverse(tempv.begin(), tempv.end());
//				}
//			}
//		}
//	}
//	return 0;
//}
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int main()
{
	int T = 0;
	int n = 0;
	int k = 0;

	cin >> T;
	while (T--)
	{
		    cin >> n >> k;
			vector<int> v(2 * n);
			for (int i = 0; i<2 * n; i++)
			{
				cin >> v[i];
			}
			while (k--)
			{
			int leftHand = n - 1;
			int rightHand = 2 * n - 1;
			vector<int> tempv(v.size(), 0);
			for (int i = 0; i<tempv.size(); i += 2)
			{
				tempv[i] = v[rightHand--];
				tempv[i + 1] = v[leftHand--];
			}
			reverse(tempv.begin(), tempv.end());
		}
	}

	return 0;
}