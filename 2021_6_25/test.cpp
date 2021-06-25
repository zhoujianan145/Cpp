class Solution {

public:
	int openLock(vector<string>& deadends, string target) {
		unordered_set<string> dict(deadends.begin(), deadends.end());
		if (dict.count("0000"))
			return -1;
		unordered_set<string> vis;
		queue<string> q;
		q.push("0000");
		vis.insert("0000");
		int count = 0;
		while (!q.empty())
		{
			int size = q.size();
			while (size--)
			{
				string Tstr = q.front();
				q.pop();
				if (Tstr == target)
				{
					return count;
				}

				for (int i = 0; i<Tstr.size(); i++)
				{
					string str1 = Tstr;
					string str2 = Tstr;
					str1[i] = str1[i] == '9' ? '0' : str1[i] + 1;
					str2[i] = str2[i] == '0' ? '9' : str2[i] - 1;
					if (!dict.count(str1) && !vis.count(str1))
					{
						q.push(str1);
						vis.insert(str1);
					}
					if (!dict.count(str2) && !vis.count(str2))
					{
						q.push(str2);
						vis.insert(str2);
					}
				}
			}
			count++;
		}
		return -1;
	}
};