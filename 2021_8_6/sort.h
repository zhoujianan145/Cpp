

#include<iostream>
#include<vector>
#include<ctime>
#include<stack>
using namespace std;

void InsertSort(vector<int>& v,int n);
void ShellSort(vector<int>& v, int n);
void SelectSort(vector<int>& v, int n);
void AdjustDown(vector<int>& v, int n, int parent);
void HeapSort(vector<int>& v, int n);
void BubbleSort(vector<int>& v, int n);
void QuickSort(vector<int>& v, int left, int right);
void QuickSortNoR(vector<int>& v, int left, int right);
void Print(vector<int>& v);
