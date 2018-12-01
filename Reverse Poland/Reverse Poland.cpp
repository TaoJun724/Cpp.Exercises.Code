#include<iostream>
#include<vector>
#include<string>
#include<stack>
using namespace std;


class Solution {
public:
	int evalRPN(vector<string>& tokens) {
		stack<int> s;

		for (size_t i = 0; i<tokens.size(); ++i)
		{
			string& str = tokens[i];
			if (!("+" == str || "-" == str || "*" == str || "/" == str))
			{
				s.push(atoi(str.c_str()));
			}
			else
			{
				int right = s.top();
				s.pop();

				int left = s.top();
				s.pop();

				switch (str[0])
				{
				case '+':
					s.push(left + right);
					break;
				case '-':
					s.push(left - right);
					break;
				case '*':
					s.push(left*right);
					break;
				case '/':
					s.push(left / right);
					break;
				}
			}
		}
		return s.top();
	}
};

int main()
{
	vector<string> t;
	t.push_back("2");
	t.push_back("1");
	t.push_back("+");
	t.push_back("3");
	t.push_back("*");
    
	Solution s;
	int ret = s.evalRPN(t);
	cout << ret << endl;
}