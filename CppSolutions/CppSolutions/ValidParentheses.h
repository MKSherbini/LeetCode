#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/valid-parentheses/

class ValidParentheses
{
public:
	// 0 ms, faster than 100.00% : 6.3 MB, less than 50.03%
	bool solution(string s) {
		stack<char> st;
		for (int i = 0; i < s.size(); i++)
			if (s[i] == '{' || s[i] == '(' || s[i] == '[')
				st.push(s[i]);
			else if (!st.empty() &&
				(st.top() == '{' && s[i] == '}'
					|| st.top() == '[' && s[i] == ']'
					|| st.top() == '(' && s[i] == ')'))
				st.pop();
			else
				return false;

		return st.empty();
	}
	vector<int> output = {
		true,
		true,
		false,
		false,
		false,
	};
	vector<string> input1 = {
		"()",
		"()[]{}",
		"(]",
		"(((",
		"]]]",
	};
};

