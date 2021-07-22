int a = rand7();
int b = rand7();

int num = (a - 1) * 7 + b;
while (num <= 40)
{
	return num % 10 + 1;
}
a = num - 40;
b = rand7();
num = (a - 1) * 7 + b;
while (num <= 60)
{
	return num % 10 + 1;
}
a = num - 60;
b = rand7();
num = (a - 1) * 7 + b;
while (num <= 20)
{
	return num % 10 + 1;
}
class Solution {
public:
	int candy(vector<int>& ratings) {
		int n = ratings.size();
		vector<int> candyV(n, 1);
		//1 3 4 5 2

		for (int i = 1; i<n; ++i)
		{   //左边开始比较
			if (ratings[i - 1]<ratings[i])
			{
				//在他们基础上+1
				candyV[i] = candyV[i - 1] + 1;
			}
		}

		for (int i = n - 1; i>0; --i)
		{
			//右边开始比较，因为是至少，人家原本分好的大，你就不要在动了
			if (ratings[i - 1]>ratings[i])
			{
				candyV[i - 1] = max(candyV[i - 1], candyV[i] + 1);
			}
		}
		int ret = 0;
		for (auto& e : candyV)
		{
			ret += e;
		}
		return ret;
	}
};