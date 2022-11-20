#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/basic-calculator/

class BasicCalculator
{
public:
	// 12 ms, faster than 80.96% : 7.9 MB, less than 98.52%
	int solution(string s) {
		int n = size(s);
		int ans = 0;
		stack<char> st;
		char lastSymbol = '+';
		for (size_t i = 0; i < n; i++) {
			if (s[i] == '(') {
				if (st.empty())
					st.push(lastSymbol);
				else
					st.push(lastSymbol == st.top() ? '+' : '-');
				lastSymbol = '+';
			}
			else if (s[i] == ')') {
				st.pop();
			}
			else if (s[i] == '+' || s[i] == '-') {
				lastSymbol = s[i];
			}
			else if (s[i] == ' ') {
			}
			else {
				string num;
				while (i < n && isdigit(s[i])) {
					num += s[i], ++i;
				}
				--i;
				int sign = 1;
				if (!st.empty())
					sign = st.top() == '+' ? 1 : -1;
				if (lastSymbol == '+')
					ans += sign * stoi(num);
				else
					ans -= sign * stoi(num);
				lastSymbol = '+';
			}
			Printer::print(s[i], lastSymbol, ans);
		}
		return ans;
	}

	vector<int> output = {
		2,
		3,
		23,
		1,
		-12
	};
	static constexpr int const& inputs = 1;
	vector<string> input1 = {
		"1 + 1",
		" 2-1 + 2 ",
		"(1+(4+5+2)-3)+(6+8)",
		"(1-(4+5+2)-3)+(6+8)",
		"- (3 + (4 + 5))"

	};
};