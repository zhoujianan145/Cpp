#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	int fib(int n) {
		//if (n == 0)
		//{
		//	return 0;
		//}
		//if (n == 1 || n == 2)
		//{
		//	return 1;
		//}
		vector<int> v(n + 1, 0);
		v[0] = 0;
		v[1] = 1;

		for (int i = 2; i<n + 1; i++)
		{
			v[i] = v[i - 1] + v[i - 2];
			v[i] %= 1000000007;
		}

		return v[n];
	}
};
//class Solution {
//public:
//	int minCostClimbingStairs(vector<int>& cost) {
//		//  vector<int> v(cost.size());
//		//  v[0]=cost[0];
//		//  v[1]=cost[1];
//		//  for(int i=2;i<cost.size();i++)
//		//  {
//		//      v[i]=min(v[i-1],v[i-2])+cost[i];
//		//  }
//		//  return min(v[v.size()-1],v[v.size()-2]);
//		int x0 = cost[0];
//		int x1 = cost[1];
//		int xi = 0;
//		for (int i = 2; i<cost.size(); ++i)
//		{
//			xi = min(x0, x1) + cost[i];
//			x0 = x1;
//			x1 = xi;
//		}
//		return min(x0, x1);
//	}
//};
//class Solution {
//public:
//	int climbStairs(int n) {
//		//   vector<int> v(n+1,0);
//		//   v[0]=1;
//		//   v[1]=1;
//		//   for(int i=2;i<n+1;i++)
//		//   {
//		//       v[i]=v[i-1]+v[i-2];
//		//   }
//		//   return v[n];
//
//		if (n == 0 || n == 1)
//		{
//			return 1;
//		}
//		int v0 = 1;
//		int v1 = 1;
//		int vi = 0;
//		for (int i = 0; i<n - 1; i++)
//		{
//			vi = v0 + v1;
//			v0 = v1;
//			v1 = vi;
//		}
//		return vi;
//	}
//};
int main()
{
	Solution().fib(0);
	return 0;
}