
#include"sort.h"

void PrintVector(const vector<int>& v)
{
	for (auto& e : v)
	{
		cout << e << " ";
	}
	cout << endl;
}
void TestInsertSort()
{
	vector<int> v({3,1,4,1,7,9,8,2,0,5});
	PrintVector(v);
	InsertSort(v, v.size());
	PrintVector(v);

}
void TestShellSort()
{
	vector<int> v({ 3, 1, 4, 1, 7, 9, 8, 2, 0, 5 });
	PrintVector(v);
	ShellSort(v, v.size());
	PrintVector(v);
}
void TestSelectSort()
{
	vector<int> v({ 8,7,6,5,4,3,2,1,0});
	PrintVector(v);
	SelectSort(v, v.size());
	PrintVector(v);
}
void TestBubbleSort()
{
	vector<int> v({ 8, 2,3, 12, 4, 6, 1, 2, 0 });
	PrintVector(v);
	BubbleSort(v, v.size());
	PrintVector(v);
}
void TestOP()
{
	srand(time(0));
	const int N = 10000;
	
	vector<int> a1(N,0);
	vector<int> a2(N,0);
	vector<int> a3(N,0);
	vector<int> a4(N,0);
	vector<int> a5(N,0);
	vector<int> a6(N,0);
	for (int i = 0; i < N; ++i)
	{
		a1[i] = rand();
		a2[i] = a1[i];
		a3[i] = a1[i];
		a4[i] = a1[i];
		a5[i] = a1[i];
		a6[i] = a1[i];
	}
	int begin1 = clock();
	InsertSort(a1, N);
	int end1 = clock();
	int begin2 = clock();
	ShellSort(a2, N);
	int end2 = clock();
	int begin3 = clock();
	SelectSort(a3, N);
	int end3 = clock();
	int begin4 = clock();
	HeapSort(a4, N);
	int end4 = clock();
	//int begin5 = clock();
	//QuickSort(a5, 0, N - 1);
	//int end5 = clock();
	//int begin6 = clock();
	//MergeSort(a6, N);
	//int end6 = clock();

	cout << "InsertSort:" << end1 - begin1 << endl;
	cout << "ShellSort:" << end2 - begin2 << endl;
	cout << "SelectSort:" << end3 - begin3 << endl;
	cout << "HeapSort:" << end4 - begin4 << endl;

}
int main()
{
	//TestInsertSort();
	//TestShellSort();
	/*TestSelectSort();*/
	TestBubbleSort();
	/*TestOP();*/
	return 0;
}