class Solution {
private:
	int m;
	int n;
public:
	void DFS(vector<vector<int>>& image, int sr, int sc, int newColor, int oldColor)
	{
		//Խ��    
		//��������������ɫ�����Ѿ����Ϊ�µ���ɫ
		if (sr<0 || sc<0 || sr >= m || sc >= n || image[sr][sc] != oldColor || image[sr][sc] == newColor)
			return;

		image[sr][sc] = newColor;
		DFS(image, sr + 1, sc, newColor, oldColor);
		DFS(image, sr - 1, sc, newColor, oldColor);
		DFS(image, sr, sc + 1, newColor, oldColor);
		DFS(image, sr, sc - 1, newColor, oldColor);
	}
	vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
		m = image.size();
		n = image[0].size();
		//�õ�����ʱ����ɫ
		int oldColor = image[sr][sc];
		//�Ը����ڵ��������
		DFS(image, sr, sc, newColor, oldColor);
		return image;
	}
};
class Solution {
public:
	int search(vector<int>& nums, int target) {
		int left = 0;
		int right = nums.size() - 1;

		while (left<right)
		{
			int mid = left + (right - left) / 2;
			if (nums[mid]<target)//��������[mid+1,right]
			{
				left = mid + 1;
			}
			else//��������Ϊ[left,mid]
			{
				//����target�ͻ��������ס
				right = mid;
			}
		}
		if (nums[left] == target)
			return left;
		else
			return -1;
	}
};