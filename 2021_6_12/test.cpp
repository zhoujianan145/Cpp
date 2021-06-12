class Solution {
public:
	int evalRPN(vector<string>& tokens) {
		int left = 0;
		int right = 0;
		stack<int> s;
		for (int i = 0; i<tokens.size(); i++)
		{
			if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/")
			{
				//注意顺序，操作符左边的数运算的时候在右边，左边数的左边在左边。
				// 例如：2 ，1， +， 3
				//2 + 1
				right = s.top();
				s.pop();
				left = s.top();
				s.pop();

				//通过操作符算出的数入栈，用于下一次计算
				if (tokens[i] == "+")
					s.push(left + right);
				if (tokens[i] == "-")
					s.push(left - right);
				if (tokens[i] == "*")
					s.push(left*right);
				if (tokens[i] == "/")
					s.push(left / right);
			}

			else
			{
				//不是操作符就入栈
				s.push(stoi(tokens[i]));
			}
		}
		return s.top();

	}
};