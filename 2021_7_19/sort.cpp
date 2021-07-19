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
void AdjustDown(vector<int>& v,int n,int parent)
{

	int child = parent * 2 + 1;

	while (child<n)
	{
		if (child+1<n && v[child] < v[child + 1])
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