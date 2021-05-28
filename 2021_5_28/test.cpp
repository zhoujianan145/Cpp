typedef map<string, int>::iterator count_it;
struct Greater{

public:

	bool operator()(const count_it& x, const count_it& y)
	{
		if (x->second != y->second)
			return  x->second > y->second;
		else
			return x->first < y->first;
	}

};
class Solution {
public:
	vector<string> topKFrequent(vector<string>& words, int k) {
		//不能用sort，因为他是快排，不稳定相同单词会改变顺序。
		map<string, int> countMap;
		for (auto& e : words)
		{
			countMap[e]++;
		}
		priority_queue<count_it, vector<count_it>, Greater> LittleHeap;

		count_it it = countMap.begin();
		while (k)
		{
			LittleHeap.push(it);
			k--;
			it++;
		}
		while (it != countMap.end())
		{
			if (it->second>LittleHeap.top()->second)
			{
				LittleHeap.pop();
				LittleHeap.push(it);
			}
			it++;
		}
		vector<string> ret;


		while (!LittleHeap.empty())
		{
			ret.push_back(LittleHeap.top()->first);
			LittleHeap.pop();
		}
		reverse(ret.begin(), ret.end());

		return ret;
	}
};