////#include<iostream>
////#include<vector>
////using namespace std;
////class Board {
////public:
////	bool checkWon(vector<vector<int> >&  board) {
////		if (board[0][0] + board[1][1] + board[2][2] == 3)
////		{
////			return true;
////		}
////		if (board[0][2] + board[1][1] + board[2][0])
////		{
////			return true;
////		}
////		for (int i = 0; i<board.size(); i++)
////		{
////			if (board[i][0] + board[i][1] + board[i][2] == 3)
////			{
////				return true;
////			}
////			if (board[0][i] + board[1][i] + board[2][i] == 3)
////			{
////				return true;
////			}
////		}
////		return false;
////	}
////};
////
////int main()
////{
////	vector<vector<int>> vv = { { -1, 1, -1 }, { 0, 0, 1 }, { 0, 0, 0 } };
////	Board().checkWon(vv);
////	return 0;
////}
//#include<iostream>
//#include<string>
//using namespace std;
//bool NoLetter(const string& str)
//{
//	int nums = 0;
//	for (size_t i = 0; i<str.size(); ++i)
//	{
//		if ((str[i] >= 'a'&& str[i] <= 'z') || (str[i] >= 'A'&&str[i] <= 'Z'))
//		{
//			return false;
//		}
//	}
//	return true;
//
//}
//int BigLetterNums(const string& str)
//{
//
//	int BigLetterNums = 0;
//	for (size_t i = 0; i<str.size(); ++i)
//	{
//		if ((str[i] >= 'A'&& str[i] <= 'Z'))
//		{
//			BigLetterNums++;
//		}
//	}
//	return BigLetterNums;
//}
//int LessLetterNums(const string& str)
//{
//	int LessLetterNums = 0;
//	for (size_t i = 0; i<str.size(); ++i)
//	{
//		if ((str[i] >= 'a' && str[i] <= 'z'))
//		{
//			LessLetterNums++;
//		}
//	}
//	return LessLetterNums;
//}
//
//int Nums(const string& str)
//{
//	int nums = 0;
//	for (size_t i = 0; i<str.size(); ++i)
//	{
//		if ((str[i] >= '0' && str[i] <= '9'))
//		{
//			nums++;
//		}
//	}
//	return nums;
//}
//int SignNums(const string& str)
//{
//	int nums = 0;
//	for (size_t i = 0; i<str.size(); ++i)
//	{
//		if ((str[i] >= 0x21 && str[i] <= 0x2F))
//			nums++;
//		if (str[i] >= 0x3A && str[i] <= 0x40)
//			nums++;
//		if (str[i] >= 0x5B && str[i] <= 0x60)
//			nums++;
//		if (str[i] >= 0x7B && str[i] <= 0x7E)
//			nums++;
//	}
//	return nums;
//}
//int main()
//{
//	string password;
//	while (getline(cin, password))
//	{
//		int score = 0;
//		if (password.size() <= 4)
//			score += 5;
//		else if (password.size() >= 5 && password.size() <= 7)
//			score += 10;
//		else if (password.size() >= 8)
//			score += 25;
//		if (NoLetter(password))
//			score += 0;
//
//		if (BigLetterNums(password) == password.size() || LessLetterNums(password) == password.size())
//			score += 10;
//		if (Nums(password) == 0)
//			score += 0;
//		if (Nums(password) == 1)
//			score += 1;
//		if (Nums(password)>1)
//			score += 20;
//		if (SignNums(password) == 0)
//			score += 0;
//		if (SignNums(password) == 1)
//			score += 10;
//		if (SignNums(password)>1)
//			score += 25;
//		if ((!NoLetter(password)) && (Nums(password)>0))
//			score += 2;
//		if ((!NoLetter(password)) && (Nums(password)>0) && (SignNums(password)>0))
//			score += 3;
//		if ((BigLetterNums(password)>0) && (LessLetterNums(password)>0) && (Nums(password)>0) && (SignNums(password)>0))
//			score += 5;
//		if (score >= 90){
//			cout << "VERY_SECURE" << endl;
//		}
//		else if (score >= 80){
//			cout << "SECURE" << endl;
//		}
//		else if (score >= 70){
//			cout << "VERY_STRONG" << endl;
//		}
//		else if (score >= 60){
//			cout << "STRONG" << endl;
//		}
//		else if (score >= 50){
//			cout << "AVERAGE" << endl;
//		}
//		else if (score >= 25){
//			cout << "WEAK" << endl;
//		}
//		else{
//			cout << "VERY_WEAK" << endl;
//		}
//	}
//
//	return 0;
//}
//#include<iostream>
//#include<string>
//using namespace std;
//bool NoLetter(const string& str)
//{
//	int nums = 0;
//	for (size_t i = 0; i<str.size(); ++i)
//	{
//		if ((str[i] >= 'a'&& str[i] <= 'z') || (str[i] >= 'A'&&str[i] <= 'Z'))
//		{
//			return false;
//		}
//	}
//	return true;
//
//}
//int BigLetterNums(const string& str)
//{
//
//	int BigLetterNums = 0;
//	for (size_t i = 0; i<str.size(); ++i)
//	{
//		if ((str[i] >= 'A'&& str[i] <= 'Z'))
//		{
//			BigLetterNums++;
//		}
//	}
//	return BigLetterNums;
//}
//int LessLetterNums(const string& str)
//{
//	int LessLetterNums = 0;
//	for (size_t i = 0; i<str.size(); ++i)
//	{
//		if ((str[i] >= 'a' && str[i] <= 'z'))
//		{
//			LessLetterNums++;
//		}
//	}
//	return LessLetterNums;
//}
//
//int Nums(const string& str)
//{
//	int nums = 0;
//	for (size_t i = 0; i<str.size(); ++i)
//	{
//		if ((str[i] >= '0' && str[i] <= '9'))
//		{
//			nums++;
//		}
//	}
//	return nums;
//}
//int SignNums(const string& str)
//{
//	int nums = 0;
//	for (size_t i = 0; i<str.size(); ++i)
//	{
//		if ((str[i] >= 0x21 && str[i] <= 0x2F))
//			nums++;
//		if (str[i] >= 0x3A && str[i] <= 0x40)
//			nums++;
//		if (str[i] >= 0x5B && str[i] <= 0x60)
//			nums++;
//		if (str[i] >= 0x7B && str[i] <= 0x7E)
//			nums++;
//	}
//	return nums;
//}
//int main()
//{
//	string password;
//	while (getline(cin, password))
//	{
//		int score = 0;
//		if (password.size() <= 4)
//			score += 5;
//		else if (password.size() >= 5 && password.size() <= 7)
//			score += 10;
//		else if (password.size() >= 8)
//			score += 25;
//		if (NoLetter(password))
//			score += 0;
//
//		if (BigLetterNums(password) == password.size() || LessLetterNums(password) == password.size())
//			score += 10;
//		if ((BigLetterNums(password)>0) && (LessLetterNums(password)>0))
//			score += 20;
//		if (Nums(password) == 0)
//			score += 0;
//		if (Nums(password) == 1)
//			score += 1;
//		if (Nums(password)>1)
//			score += 20;
//		if (SignNums(password) == 0)
//			score += 0;
//		if (SignNums(password) == 1)
//			score += 10;
//		if (SignNums(password)>1)
//			score += 25;
//		if ((!NoLetter(password)) && (Nums(password)>0))
//			score += 2;
//		if ((!NoLetter(password)) && (Nums(password)>0) && (SignNums(password)>0))
//			score += 3;
//		if ((BigLetterNums(password)>0) && (LessLetterNums(password)>0) && (Nums(password)>0) && (SignNums(password)>0))
//			score += 5;
//		if (score >= 90){
//			cout << "VERY_SECURE" << endl;
//		}
//		else if (score >= 80){
//			cout << "SECURE" << endl;
//		}
//		else if (score >= 70){
//			cout << "VERY_STRONG" << endl;
//		}
//		else if (score >= 60){
//			cout << "STRONG" << endl;
//		}
//		else if (score >= 50){
//			cout << "AVERAGE" << endl;
//		}
//		else if (score >= 25){
//			cout << "WEAK" << endl;
//		}
//		else{
//			cout << "VERY_WEAK" << endl;
//		}
//	}
//
//	return 0;
//}
#include<iostream>
#include<string>
using namespace std;
bool NoLetter(const string& str)
{
	int nums = 0;
	for (size_t i = 0; i<str.size(); ++i)
	{
		if ((str[i] >= 'a'&& str[i] <= 'z') || (str[i] >= 'A'&&str[i] <= 'Z'))
		{
			return false;
		}
	}
	return true;

}
int BigLetterNums(const string& str)
{

	int BigLetterNums = 0;
	for (size_t i = 0; i<str.size(); ++i)
	{
		if ((str[i] >= 'A'&& str[i] <= 'Z'))
		{
			BigLetterNums++;
		}
	}
	return BigLetterNums;
}
int LessLetterNums(const string& str)
{
	int LessLetterNums = 0;
	for (size_t i = 0; i<str.size(); ++i)
	{
		if ((str[i] >= 'a' && str[i] <= 'z'))
		{
			LessLetterNums++;
		}
	}
	return LessLetterNums;
}

int Nums(const string& str)
{
	int nums = 0;
	for (size_t i = 0; i<str.size(); ++i)
	{
		if ((str[i] >= '0' && str[i] <= '9'))
		{
			nums++;
		}
	}
	return nums;
}
int SignNums(const string& str)
{
	int nums = 0;
	for (size_t i = 0; i<str.size(); ++i)
	{
		if ((str[i] >= 0x21 && str[i] <= 0x2F))
			nums++;
		if (str[i] >= 0x3A && str[i] <= 0x40)
			nums++;
		if (str[i] >= 0x5B && str[i] <= 0x60)
			nums++;
		if (str[i] >= 0x7B && str[i] <= 0x7E)
			nums++;
	}
	return nums;
}
int main()
{
	string password;
	while (getline(cin, password))
	{
		int score = 0;
		if (password.size() <= 4)
			score += 5;
		else if (password.size() >= 5 && password.size() <= 7)
			score += 10;
		else if (password.size() >= 8)
			score += 25;

		if (NoLetter(password))
			score += 0;
		else if (BigLetterNums(password) == password.size() || LessLetterNums(password) == password.size())
			score += 10;
		else if ((BigLetterNums(password)>0) && (LessLetterNums(password)>0))
			score += 20;
		if (Nums(password) == 0)
			score += 0;
		else if (Nums(password) == 1)
			score += 1;
		else if (Nums(password)>1)
			score += 20;
		if (SignNums(password) == 0)
			score += 0;
		else if (SignNums(password) == 1)
			score += 10;
		else if (SignNums(password)>1)
			score += 25;

		if ((BigLetterNums(password)>0) && (LessLetterNums(password)>0) && (Nums(password)>0) && (SignNums(password)>0))
			score += 5;
		else if ((!NoLetter(password)) && (Nums(password)>0) && (SignNums(password)>0))
			score += 3;
		else if ((!NoLetter(password)) && (Nums(password)>0))
			score += 2;


		if (score >= 90){
			cout << "VERY_SECURE" << endl;
		}
		else if (score >= 80){
			cout << "SECURE" << endl;
		}
		else if (score >= 70){
			cout << "VERY_STRONG" << endl;
		}
		else if (score >= 60){
			cout << "STRONG" << endl;
		}
		else if (score >= 50){
			cout << "AVERAGE" << endl;
		}
		else if (score >= 25){
			cout << "WEAK" << endl;
		}
		else{
			cout << "VERY_WEAK" << endl;
		}
	}

	return 0;
}