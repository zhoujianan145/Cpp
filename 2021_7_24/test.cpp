#include<iostream>
#include<vector>
using namespace std;


int main()
{

	
	//你自己存在里面的指针，指针new的对象，自己一个个delete才能释放

		int *p = new int;
		int a = 1;
		int *p1 = &a;
		vector<int*> v;
		v.push_back(p);
		v.push_back(p1);
		delete p;

		class MyStack {
			queue<int> q1;
			queue<int> q2;
		public:
			/** Initialize your data structure here. */
			MyStack() {

			}

			/** Push element x onto stack. */
			void push(int x) {
				q1.push(x);
			}

			/** Removes the element on top of the stack and returns that element. */
			int pop() {
				int n = q1.size() - 1;
				while (n--)
				{
					q2.push(q1.front());
					q1.pop();
				}
				int ret = q1.front();
				q1.pop();
				swap(q1, q2);
				return ret;

			}

			/** Get the top element. */
			int top() {
				return q1.back();
			}

			/** Returns whether the stack is empty. */
			bool empty() {
				return q1.empty();
			}
		};

		/**
		* Your MyStack object will be instantiated and called as such:
		* MyStack* obj = new MyStack();
		* obj->push(x);
		* int param_2 = obj->pop();
		* int param_3 = obj->top();
		* bool param_4 = obj->empty();
		*/
		class CQueue {
		private:
			stack<int> st1;
			stack<int> st2;
		public:
			CQueue() {

			}
			void appendTail(int value) {
				st1.push(value);
			}

			int deleteHead() {
				if (st2.empty())
				{
					while (!st1.empty())
					{
						int num = st1.top();
						st1.pop();
						st2.push(num);
					}
				}
				if (!st2.empty())
				{
					int num = st2.top();
					st2.pop();
					return num;
				}
				else
				{
					return -1;
				}

			}
		};

		/**
		* Your CQueue object will be instantiated and called as such:
		* CQueue* obj = new CQueue();
		* obj->appendTail(value);
		* int param_2 = obj->deleteHead();
		*/

	return 0;
}