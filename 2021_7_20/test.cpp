
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
void TestHeapSort()
{
	vector<int> v({ 8, 7, 6, 5, 4, 3, 2, 1, 0 });
	PrintVector(v);
	HeapSort(v, v.size());
	PrintVector(v);
}
void TestBubbleSort()
{
	vector<int> v({ 8, 2,3, 12, 4, 6, 1, 2, 0 });
	PrintVector(v);
	BubbleSort(v, v.size());
	PrintVector(v);
}
void TestQuickSort()
{
	vector<int> v({ 8, 2, 3, 12, 4, 6, 1, 2, 0 });
	PrintVector(v);
	QuickSort(v,0,v.size()-1);
	PrintVector(v);
}
void TestQuickSortNoR()
{
	vector<int> v({ 8, 2, 3, 12, 4, 6, 1, 2, 0 });
	PrintVector(v);
	QuickSortNoR(v, 0, v.size() - 1);
	PrintVector(v);
}
void TestMemergeSort()
{
	vector<int> v({ 8, 2, 3, 12, 4, 6, 1, 2, 0 });
	PrintVector(v);
	MemergeSort(v, v.size());
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
	vector<int> a7(N, 0);
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
	int begin5 = clock();
	BubbleSort(a5, N);
	int end5 = clock();
	int begin6 = clock();
	QuickSort(a6, 0, N - 1);
	int end6 = clock();
	//int begin7 = clock();
	//MergeSort(a6, N);
	//int end7 = clock();

	cout << "InsertSort:"<<"   时间复杂度O(N^2),耗费时间:                         " << end1 - begin1 << endl;
	cout << "ShellSort:" << "  时间复杂度O(N^1.5)--O(N^2),耗费时间:               " << end2 - begin2 << endl;
	cout << "SelectSort:" << " 时间复杂度O(N^2),耗费时间:                         " << end3 - begin3 << endl;
	cout << "HeapSort:" << "   时间复杂度O(N*logN),耗费时间:                      " << end4 - begin4 << endl;
	cout << "BubbleSort" << "  时间复杂度O(N^2),耗费时间:                         " << end5 - begin5 << endl;
	cout << "QucikSort" <<"    经过三数取中优化,时间复杂度为O(N*logN),耗费时间:   " << end6 - begin6 << endl;
}
int main()
{
	//TestInsertSort();
	//TestShellSort();
	/*TestSelectSort();*/
	/*TestBubbleSort();*/
	/*TestHeapSort();*/
	/*TestQuickSortNoR();*/
	TestMemergeSort();
	/*TestOP();*/
	return 0;
}