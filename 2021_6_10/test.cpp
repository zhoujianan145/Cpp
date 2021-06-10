class Solution {
public:
	double myPow(double x, int n) {

		//0�η�����1��1��n�η�Ҳ��1
		if (n == 0 || x == 1)
			return 1;

		//��ʼ��nֱ�����ģ����淢��INT_MIN�������������long�洢
		//��ô����whileѭ��ҲҪ�ĳ�b
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
