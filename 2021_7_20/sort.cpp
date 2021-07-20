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
//���µ����㷨
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
//����ȡ��
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
//����ָ�뷨
int PartSort1(vector<int>& v,int begin, int end)
{
	int midIndex = GetMidIndex(v, begin, end);
	swap(v[midIndex], v[end]);

	int keyIndex = end;
	while (begin < end)
	{
		//����Ҵ�
		while (begin<end && v[begin] <= v[keyIndex])
		{
			begin++;
		}
		//�ұ���С
		while (begin<end && v[end] >= v[keyIndex])
		{
			end--;
		}
		//�ҵ�������
		swap(v[begin], v[end]);
	}
	//ͬʱ��begin��end���㴦��kֵ����
	swap(v[begin], v[keyIndex]);

	//ͬʱ�����м�λ�õ�����,�Դ�Ϊ���޵ݹ�ָ������
	return begin;
}
//�ڿӷ�
int PartSort2(vector<int>& v,int begin, int end)
{
	int midIndex = GetMidIndex(v, begin, end);
	swap(v[midIndex], v[end]);
	//�ڿӷ���Ҫ����k,end�ᱻ����
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
//ǰ��ָ�뷨
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
		//զ����Ҫ++
	    cur++;
	}
	++prev;
	swap(v[prev], v[kIndex]);

	return prev;
}
//���˿�������
void QuickSort(vector<int>& v, int left, int right)
{
	if (left >= right)
		return;


	int div= PartSort3(v,left, right);

	QuickSort(v, left, div - 1);

	QuickSort(v, div+1,right );

}
//�ǵݹ飬�ݹ��Ч�ʲ������������������ջ���.
void QuickSortNoR(vector<int>& v, int left, int right)
{
	//�������±�
	stack<int> st;
	//���ң����� 
	//���󣬳���
	st.push(right);
	st.push(left);

	while (!st.empty())
	{
		int begin = st.top();
		st.pop();
		int end = st.top();
		st.pop();
		int div = PartSort1(v, begin, end);

		//������if��ʱ�̼�ס����ȳ�
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
//��������
void _MemergeSort(vector<int>& v, int left,int right, vector<int>& temp)
{
	if (left >= right)
	{
		return;
	}
    
	int mid = left + (right - left) / 2;

	//�˼ҿ����� [left,div-1]div[div+1,right]
	//����[left,mid][mid+1,right]������
	_MemergeSort(v, left, mid , temp);
	_MemergeSort(v, mid+1, right, temp);


	//�����ں������ң��������൱�ڴ���
	//������1[left,mid]������2[mid+1,right]���ϲ�����ʱ����ʹ������
	int begin1 = left;
	int begin2 = mid + 1;
	int end1 = mid;
	int end2 = right;

	int index = begin1;
	//�ϲ�������
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
	//�������Ǹ����������ˣ�������ǰ�˳�
	while (begin1 <= end1)
	{
		temp[index++] = v[begin1++];
	}
	while (begin2 <= end2)
	{
		temp[index++] = v[begin2++];
	}

	//������ԭ����
	//������[left,mid][mid+1,right]
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