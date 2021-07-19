#include<iostream>
#include<algorithm>
#include<vector>
#include<ctime>
using namespace std;

//¥Ú”°
void PrintVector(const vector<int>& v);

//1.≤Â»Î≈≈–Ú

//÷±Ω”≤Â»Î≈≈–ÚO(N^2)
void InsertSort(vector<int>& v, int n);
//œ£∂˚≈≈–ÚO(N^1.3)-O(N^1.3)
void ShellSort(vector<int>& v, int n);

//2.—°‘Ò≈≈–Ú

//÷±Ω”—°‘Ò≈≈–ÚO(N^2)
void SelectSort(vector<int>& v, int n);
//∂—≈≈–ÚO(n*logN)
void HeapSort(vector<int>& v, int n);
void AdjustDown(vector<int>& v, int n, int parent);

//3.Ωªªª≈≈–Ú
//√∞≈›≈≈–Ú
void BubbleSort(vector<int>& v, int n);

