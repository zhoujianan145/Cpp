#pragma once
#include"sort.h"

//直接插入排序
void InsertSort(vector<int>& v, int n)
{
	//i最多在n-2处
	for (int i = 0; i < n - 1; i++)
	{
		//单趟
		int end = i;
		int temp = v[end + 1];

		while (end>=0)
		{
			if (temp < v[end])
			{
				v[end + 1] = v[end];
				end--;
			}
			else
			{
				break;
			}
		}
		v[end + 1] = temp;
	}
}
//希尔排序
void ShellSort(vector<int>& v, int n)
{
	int gap = n;
	//不断缩小gap,从而进行多趟排序
	while (gap > 1)
	{
		gap = gap / 3 + 1;
		//对分好的几组进行单趟排序
		for (int i = 0; i < n - gap; ++i)
		{
			int end = i;
			int temp = v[end + gap];
			while (end >= 0)
			{
				if (temp < v[end])
				{
					v[end + gap] = v[end];
					end -= gap;
				}
				else
				{
					break;
				}
			}
			v[end + gap] = temp;
		}
	}
	
	
}

//直接选择排序
void SelectSort(vector<int>& v, int n)
{
	int begin = 0;
	int end = n - 1;


	while (begin<end)
	{
		//每次都从新的begin开始
		int maxi = begin;
		int mini = begin;
		//找小，找大。与最左和最右交换
		for (int i = begin; i <= end; ++i)
		{
			if (v[i]>v[maxi])
			{
				maxi = i;
			}
			if (v[i] < v[mini])
			{
				mini = i;
			}
		}
		swap(v[begin], v[mini]);
		//当begin就是maxi时，最小的与begin交换，同时将最大的数也换走了
		//和最小的数交换的，将位置更新一下
		if (begin == maxi)
		{
			maxi = mini;
		}
		swap(v[end], v[maxi]);
		begin++;
		end--;
	}
	

}
//向下调整算法
void AdjustDown(vector<int>& v, int n, int parent)
{

	int child = parent * 2 + 1;

	while (child<n)
	{
		if (child + 1<n && v[child] < v[child + 1])
		{
			child++;
		}
		if (v[parent] < v[child])
		{
			swap(v[parent], v[child]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}

	}
}
//堆排序
void HeapSort(vector<int>& v, int n)
{
	//先建成大堆
	//n-1为最后一个元素
	for (int i = (n - 1-1) / 2; i >= 0; --i)
	{
		AdjustDown(v, n, i);
	}
	//将最大的元素交换到最后一个位置，size--，对其他元素重新建堆
	//再取最大元素交换
	int end = n - 1;
	while (end > 0)
	{
		swap(v[0], v[end]);
		AdjustDown(v,end, 0);
		--end;
	}

}

//冒泡排序
void BubbleSort(vector<int>& v, int n)
{
	int end = n;
	while (end>0)
	{
		bool exchange = true;
	    for (int i = 1; i < end; ++i)
	    {
		if (v[i - 1]>v[i])
		{
			swap(v[i - 1], v[i]);
			exchange = false;
		}
	    }
		if (exchange == true)
		{
			break;
		}
		end--;
	}
}
//三数取中
int GetMidIndex(vector<int>& v, int begin, int end)
{
	int mid = begin + (end - begin) / 2;

	if (v[begin] < v[mid])
	{
		
		if (v[mid]<v[end])
		{
			return mid;
		}
		else if (v[begin]>v[end])
		{
			return begin;
		}
		else
		{
			return end;
		}
	}
	else// 10 5 13
	{
		if (v[mid] > v[end])
		{
			return mid;
		}
		else if (v[begin] < v[end])
		{
			return begin;
		}
		else
		{
			return end;
		}
	}
	
}
//左右指针法
int PartSort1(vector<int>& v,int begin, int end)
{
	int midIndex = GetMidIndex(v, begin, end);
	swap(v[midIndex], v[end]);

	int keyIndex = end;
	while (begin < end)
	{
		//左边找大
		while (begin<end && v[begin] <= v[keyIndex])
		{
			begin++;
		}
		//右边找小
		while (begin<end && v[end] >= v[keyIndex])
		{
			end--;
		}
		//找到并交换
		swap(v[begin], v[end]);
	}
	//同时在begin和end交汇处与k值交换
	swap(v[begin], v[keyIndex]);

	//同时返回中间位置的坐标,以此为界限递归分割左和右
	return begin;
}
//挖坑法
int PartSort2(vector<int>& v,int begin, int end)
{
	int midIndex = GetMidIndex(v, begin, end);
	swap(v[midIndex], v[end]);
	//挖坑法，要保存k,end会被覆盖
	int k= v[end];
	while (begin < end)
	{
		while (begin < end && v[begin] <= k)
		{
			begin++;
		}
		v[end] = v[begin];
		while (begin < end && v[end] >= k)
		{
			end--;
		}
		v[begin] = v[end];
	}
	v[begin] = k;
	return begin;
}
//前后指针法
int PartSort3(vector<int>& v, int begin, int end)
{
	int midIndex = GetMidIndex(v, begin, end);
	swap(v[midIndex], v[end]);

	int prev = begin - 1;
	int cur = begin;
	int kIndex = end;
	while (cur <= end)
	{
		if (v[cur] < v[kIndex] && ++prev!=cur)
		{
			swap(v[cur], v[prev]);
		}
		//咋样都要++
	    cur++;
	}
	++prev;
	swap(v[prev], v[kIndex]);

	return prev;
}
//多趟快速排序
void QuickSort(vector<int>& v, int left, int right)
{
	if (left >= right)
		return;


	int div= PartSort3(v,left, right);

	QuickSort(v, left, div - 1);

	QuickSort(v, div+1,right );

}
//非递归，递归的效率不是最大的问题而是容易栈溢出.
void QuickSortNoR(vector<int>& v, int left, int right)
{
	//用来存下标
	stack<int> st;
	//入右，入左 
	//出左，出右
	st.push(right);
	st.push(left);

	while (!st.empty())
	{
		int begin = st.top();
		st.pop();
		int end = st.top();
		st.pop();
		int div = PartSort1(v, begin, end);

		//这俩个if，时刻记住后进先出
		if (end > div + 1)
		{
			st.push(end);
			st.push(div + 1);

		}
		if (begin < div - 1)
		{
			st.push(div - 1);
			st.push(begin);
		}
	}
}
//单趟排序
void _MemergeSort(vector<int>& v, int left,int right, vector<int>& temp)
{
	if (left >= right)
	{
		return;
	}
    
	int mid = left + (right - left) / 2;

	//人家快排是 [left,div-1]div[div+1,right]
	//你是[left,mid][mid+1,right]别搞混了
	_MemergeSort(v, left, mid , temp);
	_MemergeSort(v, mid+1, right, temp);


	//类似于后序，左，右，根。根相当于处理
	//将数组1[left,mid]和数组2[mid+1,right]，合并到临时数组使其有序
	int begin1 = left;
	int begin2 = mid + 1;
	int end1 = mid;
	int end2 = right;

	int index = begin1;
	//合并至数组
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (v[begin1] < v[begin2])
		{
			temp[index++] = v[begin1++];
		}
		else
		{
			temp[index++] = v[begin2++];
		}
	}
	//假如有那个数组走完了，导致提前退出
	while (begin1 <= end1)
	{
		temp[index++] = v[begin1++];
	}
	while (begin2 <= end2)
	{
		temp[index++] = v[begin2++];
	}

	//拷贝回原数组
	//区间是[left,mid][mid+1,right]
	for (int i = left; i <= right; ++i)
	{
		v[i] = temp[i];
	}


}
void MemergeSort(vector<int>& v, int n)
{
	vector<int> temp(n);
	_MemergeSort(v, 0, n - 1, temp);
}