class Solution {
public:
	double myPow(double x, int n) {

		//0次方就是1，1的n次方也是1
		if (n == 0 || x == 1)
			return 1;

		//开始拿n直接做的，后面发现INT_MIN会溢出，这里用long存储
		//那么后面while循环也要改成b
		long b = n;

		if (b<0)
		{
			b = -b;
			x = 1 / x;
		}

		double multi = 1;
		double ret = x;

		while (b)
		{
			if (b & 1)
			{
				multi *= ret;
			}
			ret *= ret;
			b = b >> 1;
		}
		return multi;

	}
};
