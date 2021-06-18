class Solution {
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		vector<int> v;
		int t = 0;
		if (matrix.size() == 0)
			return v;
		int b = matrix.size() - 1;
		int l = 0;
		int r = matrix[0].size() - 1;


		while (true)
		{
			for (int i = l; i <= r; i++)
			{
				v.push_back(matrix[t][i]);
			}
			t++;
			if (t>b)
			{
				break;
			}
			for (int i = t; i <= b; i++)
			{
				v.push_back(matrix[i][r]);
			}
			r--;
			if (r<l)
			{
				break;
			}
			for (int i = r; i >= l; i--)
			{
				v.push_back(matrix[b][i]);
			}
			b--;
			if (b<t)
			{
				break;
			}
			for (int i = b; i >= t; i--)
			{
				v.push_back(matrix[i][l]);
			}
			l++;
			if (l>r)
			{
				break;
			}

		}
		return v;

	}
};s