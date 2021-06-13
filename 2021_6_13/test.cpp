class Solution {
private:
	int m;
	int n;
public:
	void DFS(vector<vector<int>>& image, int sr, int sc, int newColor, int oldColor)
	{
		//越界    
		//不等于所给的颜色或者已经标记为新的颜色
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
		//拿到他此时的颜色
		int oldColor = image[sr][sc];
		//对给定节点进行深搜
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
			if (nums[mid]<target)//搜索区间[mid+1,right]
			{
				left = mid + 1;
			}
			else//搜索区间为[left,mid]
			{
				//等于target就会把区间锁住
				right = mid;
			}
		}
		if (nums[left] == target)
			return left;
		else
			return -1;
	}
};