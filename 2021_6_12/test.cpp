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
				//ע��˳�򣬲�������ߵ��������ʱ�����ұߣ���������������ߡ�
				// ���磺2 ��1�� +�� 3
				//2 + 1
				right = s.top();
				s.pop();
				left = s.top();
				s.pop();

				//ͨ�����������������ջ��������һ�μ���
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
				//���ǲ���������ջ
				s.push(stoi(tokens[i]));
			}
		}
		return s.top();

	}
};