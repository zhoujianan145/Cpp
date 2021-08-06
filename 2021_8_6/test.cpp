
#include"sort.h"
void TestInsertSort()
{
	vector<int> v({ 4, 5, 1, 3, 6, 8, 5, 7 });
	InsertSort(v, v.size());
	Print(v);

}
void TestShellSort()
{
	vector<int> v({ 4, 5, 1, 3, 6, 8, 5, 7 });
	ShellSort(v, v.size());
	Print(v);
}
void TestSelecSort()
{
	vector<int> v({ 4, 5, 1, 3, 6, 8, 5, 7 });
	SelectSort(v, v.size());
	Print(v);
}
void TestHeapSort()
{
	vector<int> v({ 4, 5, 1, 3, 6, 8, 5, 7 });
	HeapSort(v, v.size());
	Print(v);
}

void TestBubbleSort()
{
	vector<int> v({ 4, 5, 1, 3, 6, 8, 5, 7 });
	BubbleSort(v, v.size());
	Print(v);

}
void TestQuickSort()
{
	vector<int> v({ 4, 5, 1, 3, 6, 8, 5, 7 });
	QuickSort(v, 0, v.size() - 1);
	Print(v);
	
}
void QuickSortNoR(vector<int>& v, int left, int right)
{
	stack<int>
}
int main()
{
	//TestInsertSort();
	//TestShellSort();
	TestSelecSort();
	TestHeapSort();
	TestBubbleSort();
	TestQuickSort();
	return 0;
}