#pragma once
#include"sort.h"

//ֱ�Ӳ�������
void InsertSort(vector<int>& v, int n)
{
	//i�����n-2��
	for (int i = 0; i < n - 1; i++)
	{
		//����
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
//ϣ������
void ShellSort(vector<int>& v, int n)
{
	int gap = n;
	//������Сgap,�Ӷ����ж�������
	while (gap > 1)
	{
		gap = gap / 3 + 1;
		//�Էֺõļ�����е�������
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

//ֱ��ѡ������
void SelectSort(vector<int>& v, int n)
{
	int begin = 0;
	int end = n - 1;


	while (begin<end)
	{
		//ÿ�ζ����µ�begin��ʼ
		int maxi = begin;
		int mini = begin;
		//��С���Ҵ�����������ҽ���
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
		//��begin����maxiʱ����С����begin������ͬʱ��������Ҳ������
		//����С���������ģ���λ�ø���һ��
		if (begin == maxi)
		{
			maxi = mini;
		}
		swap(v[end], v[maxi]);
		begin++;
		end--;
	}
	

}

//������
void HeapSort(vector<int>& v, int n)
{
	//�Ƚ��ɴ��
	//n-1Ϊ���һ��Ԫ��
	for (int i = (n - 1-1) / 2; i >= 0; --i)
	{
		AdjustDown(v, n, i);
	}
	//������Ԫ�ؽ��������һ��λ�ã�size--��������Ԫ�����½���
	//��ȡ���Ԫ�ؽ���
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
//ð������
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