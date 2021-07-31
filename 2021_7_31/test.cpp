//#include<iostream>
//#include<vector>
//#include<stack>
//using namespace std;
//
////插入排序
////1.直接插入
////O(N^2) 稳定
//void InsertSort(vector<int>& v,int n)
//{
//	for (int i = 0; i<n - 1; ++i)
//	{
//		int end=i;
//		int temp = v[end+1];
//		while (end >= 0)
//		{
//
//			if (v[end] > temp)
//			{
//				v[end+1] = v[end];
//				end--;
//			}
//			else
//			{
//				break;
//			}
//			
//		}
//		v[end+1] = temp;
//	}
//}
//
////2. 希尔排序
////O（N^1.3-N^2）不稳定
//void ShellSort(vector<int>& v, int n)
//{
//	int gap = n;
//	while (gap > 1)
//	{
//		gap = gap / 3 + 1;
//		for (int i = 0; i<n-gap; ++i)
//		{
//			int end = i;
//			int temp = v[end + gap];
//			while (end >= 0)
//			{
//				if (v[end] > temp)
//				{
//					v[end + gap] = v[end];
//					end -= gap;
//				}
//				else
//				{
//					break;
//				}
//			}
//			v[end + gap] = temp;
//		}
//	}
//}
//
////选择排序
////1.直接选择
////很差，O（N^2）不稳定
//void SelectSort(vector<int>& v, int n)
//{
//	int begin = 0;
//	int end = n - 1;
//
//	while (begin<end)
//	{
//		int maxi = begin;
//		int mini = begin;
//		
//		for (int i = begin; i <= end; ++i)
//		{
//			if (v[i]>v[maxi])
//			{
//				maxi = i;
//			}
//			if (v[i] < v[mini])
//			{
//				mini = i;
//			}
//		}
//		swap(v[begin], v[mini]);
//
//		if (begin == maxi)
//		{
//			maxi = mini;
//		}
//		swap(v[end], v[maxi]);
//		begin++;
//		end--;
//	}
//}
////2.堆排序
////向下调整
//void AdjustDown(vector<int>& v,int n,int parent)
//{
//	int child = parent * 2 + 1;
//	while (child < n)
//	{
//		
//		if (child+1<n && v[child + 1] > v[child])
//		{
//			child++;
//		}
//		if (v[parent]<v[child])
//		{
//			swap(v[parent], v[child]);
//			parent = child;
//			child = parent * 2 + 1;
//		}
//		else
//		{
//			break;
//		}
//	}
//}
////堆排
//void HeapSort(vector<int> v,int n)
//{
//	for (int i = (n - 1 - 1) / 2; i >=0; ++i)//易错
//	{
//		AdjustDown(v, n, i);
//	}
//	
//	int end = n - 1;
//	
//	while (end)
//	{
//		swap(v[end], v[0]);
//		AdjustDown(v, end, 0);
//		end--;
//	}
//}
//void BubbleSort(vector<int>& v,int n)
//{
//	int end = n;
//	while (end>0)
//	{
//		bool exchange = false;
//		for (int i = 1; i < end ; ++i)
//		{
//			
//			if (v[i-1] > v[i])
//			{
//				swap(v[i-1], v[i]);
//				exchange = true;
//			}
//		}
//		if (!exchange)
//		{
//			break;
//		}
//		end--;
//	}
//	
//}
//int GetmidIndex(const vector<int>& v, int begin,int end)
//{
//	int mid = begin + (end - begin) / 2;
//	//begin<mid<
//	if (v[begin] < v[mid])
//	{
//		if (v[end]>v[mid])
//		{
//			return mid;
//		}//begin<end<mid
//		else if (v[end] > v[begin])
//		{
//			return end;
//		}
//		else
//		{
//			return begin;
//		}
//	}
//	else//begin>mid
//	{
//		if (v[mid] > v[end])
//		{
//			return mid;
//		}//begin>end>mid
//		else if (v[begin] > v[end])
//		{
//			return end;
//		}
//		else
//		{
//			return begin;
//		}
//
//	}
//}
//int PartSort(vector<int>& v, int begin, int end)
//{
//	int midIndex = GetmidIndex(v,begin,end);
//	swap(v[end], v[midIndex]);
//	int k = end;
//	while (begin < end)
//	{
//		while (begin < end && v[begin] <= v[k])
//		{
//			begin++;
//		}
//		while (begin < end && v[end] >= v[k])
//		{
//			end--;
//		}
//		swap(v[begin], v[end]);
//	}
//	swap(v[begin], v[k]);
//	return begin;
//}
//void QuickSort(vector<int>& v,int left,int right)
//{
//
//	if (left >= right)
//		return;
//
//	int div = PartSort(v, left, right);
//
//	QuickSort(v, 0, div - 1);
//	QuickSort(v, div + 1, right);
//}
//void QuickSortNoR(vector<int>& v, int left, int right)
//{
//	stack<int> st;
//
//	st.push(right);
//	st.push(left);
//	
//	while (!st.empty())
//	{
//		int begin = st.top();
//		st.pop();
//		int end = st.top();
//		st.pop();
//
//		int div = PartSort(v, begin, end);
//
//		//begin div-1 div+1 end
//		if (end > div + 1)
//		{
//			st.push(end);
//			st.push(div + 1);
//		}
//
//		if (begin < div - 1)
//		{
//			st.push(div - 1);
//			st.push(begin);
//		}
//	}
//	
//
//}
//void _MerageSort(vector<int>& v,int left,int right,vector<int>& temp)
//{
//	if (left >= right)
//	{
//		return;
//	}
//	int mid = left + (right - left) / 2;
//	_MerageSort(v, left, mid, temp);
//	_MerageSort(v, mid + 1, right, temp);
//
//
//	int begin1 = left;
//	int end1 = mid;
//	int begin2 = mid + 1;
//	int end2 = right;
//	
//	int index = begin1;
//	while (begin1 <= end1 && begin2<=end2)
//	{
//		if (v[begin1] < v[begin2])
//		{
//			temp[index++] = v[begin1++];
//		}
//		else
//		{
//			temp[index++] = v[begin2++];
//		}
//	}
//	while (begin1 <= end1)
//	{
//		temp[index++] = v[begin1++];
//	}
//	while (begin2 <= end2)
//	{
//		temp[index++] = v[begin2++];
//	}
//}
//void MerageSort(vector<int>& v,int n)
//{
//	int left = 0;
//	int right = n - 1;
//	vector<int> temp;
//	_MerageSort(v, left, right, temp);
//}
//void Printf(const vector<int>& v)
//{
//	for (auto& e : v)
//	{
//		cout << e<<" ";
//	}
//	cout << endl;
//}
//void testInserotSort()
//{
//	vector<int> v({5, 3, 1, 8, 7, 9, 4});
//	InsertSort(v, v.size());
//	Printf(v);
//}
//void testShellSort()
//{
//	vector<int> v({ 5, 3, 1, 8, 7, 9, 4 });
//	ShellSort(v, v.size());
//	Printf(v);
//
//}
//void testSelectSort()
//{
//	vector<int> v({ 5, 3, 1, 8, 7, 9, 4 });
//	SelectSort(v, v.size());
//	Printf(v);
//
//}
//void testHeapSort()
//{
//	vector<int> v({ 5, 3, 1, 8, 7, 9, 4 });
//	HeapSort(v, v.size());
//	Printf(v);
//
//}
//void testBubbleSort()
//{
//	vector<int> v({ 5, 3, 1, 8, 7, 9, 4 });
//	BubbleSort(v, v.size());
//	Printf(v);
//
//}
//void testQuickSort()
//{
//	vector<int> v({ 5, 3, 1, 8, 7, 9, 4 });
//	QuickSort(v, 0,v.size()-1);
//	Printf(v);
//
//}
//void testQuickNoRSort()
//{
//	vector<int> v({ 5, 3, 1, 8, 7, 9, 4 });
//	QuickSortNoR(v, 0, v.size() - 1);
//	Printf(v);
//
//}
//int main()
//{
//	//testInserotSort();
//	//testShellSort();
//	//testSelectSort();
//	//testHeapSort();
//	//testBubbleSort();
//	//testQuickSort();
//	testQuickNoRSort();
//	return 0;
//}