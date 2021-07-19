#include<iostream>
#include<algorithm>
#include<vector>
#include<ctime>
using namespace std;

//��ӡ
void PrintVector(const vector<int>& v);

//1.��������

//ֱ�Ӳ�������O(N^2)
void InsertSort(vector<int>& v, int n);
//ϣ������O(N^1.3)-O(N^1.3)
void ShellSort(vector<int>& v, int n);

//2.ѡ������

//ֱ��ѡ������O(N^2)
void SelectSort(vector<int>& v, int n);
//������O(n*logN)
void HeapSort(vector<int>& v, int n);
void AdjustDown(vector<int>& v, int n, int parent);

//3.��������
//ð������
void BubbleSort(vector<int>& v, int n);

