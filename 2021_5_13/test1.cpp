//#include<iostream>
//#include<string>
//using namespace std;
//int main()
//{
//	//char a[14] = "abcd";
//
//	//char a1[14];
//	//a1 = "acssdasdasd";
//	string s = "adsca";
//	cin >> s;
//
//
//	cout << s;
//	return 0;
//}

#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int countSpace(const string& str)
{
	int count = 0;
	for (int i = 0; i<str.size(); i++)
	{
		if (str[i] == ' ')
		{
			count++;
		}
	}
	return count;
}
int main()
{
	string table = "3 4 5 6 7 8 9 10 J Q K A 2 joker JOKER";
	string str(table);

	while (getline(cin, str))
	{
		if (str.find("joker JOKER") != -1)
		{
			cout << "joker JOKER" << endl;
		}
		else
		{
			int i = str.find('-');
			string s1 = str.substr(0, i);
			string s2 = str.substr(i + 1, str.size());
			int count1 = countSpace(s1) + 1;
			int count2 = countSpace(s2) + 1;

			if (count1 == count2)
			{
				/*if (s1[0]>s2[0])*/
				//���� 3 4 5 6 7 �� 10 J Q K A �Ƚϵ�ʱ��ʵ���� 3 �� 1 �Ƚϣ��������������3��10�Ƚϡ�
				//��Ŀ���ᵽ��˳�ӵĻ�����������Сֵ�Ƚϣ���ô������3��10�Ƚ���
				string s3 = s1.substr(0, ' ');
				string s4 = s2.substr(0, ' ');
				//3��10
				if (stoi(s3)>stoi(s4))
					cout << s1 << endl;
				else
					cout << s2 << endl;
			}
			else
			{
				if (count1 == 4)
					cout << s1 << endl;
				else if (count2 == 4)
					cout << s2 << endl;
				else
					cout << "ERROR" << endl;
			}
		}
	}
	return 0;
}