
#include"sort.h"

void InsertSort(vector<int>& v, int n)
{
	for (int i = 0; i < n - 1; ++i)
	{
		int end = i;
		int temp = v[end + 1];

		while (end >= 0)
		{
			if (v[end] > temp)
			{
				v[end + 1] = v[end];
				end--;
			}
			else
			{
				break;
			}
			v[end + 1] = temp;
		}
	}

}
void ShellSort(vector<int>& v, int n)
{
	int gap = n;
	while (gap > 1)
	{
		gap = gap / 3 + 1;
		for (int i = 0; i < n - gap; i++)
		{
			int end = i;
			int temp = v[end + gap];

			while (end >= 0)
			{
				if (v[end] > v[end + gap])
				{
					v[end+gap] = v[end];
					end -= gap;
				}
				else
				{
					break;
				}
				v[end + gap] = temp;
			}
		}
	}
}
void SelectSort(vector<int>& v, int n)
{
	int begin = 0;
	int end = n - 1;

	while (begin<end)
	{
		int mini = begin;
		int maxi = begin;
		for (int i = begin; i <= end; ++i)
		{
			if (v[i] > v[maxi])
			{
				maxi = i;
			}
			if (v[i] < v[mini])
			{
				mini = i;
			}
		}
		swap(v[begin], v[mini]);
		if (begin==maxi)
		{
			maxi = mini;
		}
		swap(v[end], v[maxi]);

		begin++;
		end--;
	}
	
}
void AdjustDown(vector<int>& v, int n,int parent)
{
	
	int child = parent * 2 + 1;

	while (child < n)
	{
		if (child + 1 < n && v[child + 1] > v[child])
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
void HeapSort(vector<int>& v, int n)
{
	for (int i = (n - 1 - 1) / 2; i >=0; --i)
	{
		AdjustDown(v, n,i);
	}

	int end = n - 1;
	while (end>0)
	{
		swap(v[end], v[0]);
		AdjustDown(v, end,0);
		end--;
	}
}

void BubbleSort(vector<int>& v, int n)
{
	int end = n;
	while (end > 0)
	{
		bool exchange = false;
		for (int i = 1; i < end; ++i)
		{
			if (v[i - 1]>v[i])
			{
				swap(v[i - 1], v[i]);
				exchange = true;
			}
		}
		if (exchange==false)
		{
			break;
		}
		end--;
	}

}
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
int partSort(vector<int>& v, int begin, int end)
{
	int kIndex = end;
	while (begin < end)
	{
		while (begin < end && v[begin] <= v[kIndex])
		{
			begin++;
		}
		while (begin < end && v[end] >= v[kIndex])
		{
			end--;
		}
		swap(v[begin], v[end]);
	}
	swap(v[begin], v[kIndex]);
	return begin;
}
void QuickSort(vector<int>& v, int left, int right)
{
	if (left >= right)
	{
		return;
	}
	int div = partSort(v, left, right);
	QuickSort(v, left, div - 1);
	QuickSort(v, div + 1, right);
}
void Print(vector<int>& v)
{
	for (auto& e : v)
	{
		cout << e << " ";
	}
	cout << endl;
}