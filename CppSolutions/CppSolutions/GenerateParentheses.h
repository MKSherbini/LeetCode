#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/generate-parentheses/

class GenerateParentheses
{
public:
	// 6 ms, faster than 52% : 17.1 MB, less than 10.97%
	vector<string> solution(int n) {
		vector<string> ans;
		curse(ans, n, {}, {});
		cout << endl;
		sort(begin(ans), end(ans));
		ans.erase(unique(begin(ans), end(ans)), end(ans));
		return ans;
	}
	void curse(vector<string>& ans, int n, string st, string end) {
		Printer::print(st, end);
		if (n * 2 == st.size() + end.size()) ans.push_back(st + end);
		else if (n * 2 < st.size() + end.size()) return;
		curse(ans, n, st + '(', ')' + end);
		if (end.size())
			curse(ans, n, st + end[0], end.substr(1));
	}
	vector<vector<string>> output = {
		{"((()))","(()())","(())()","()(())","()()()"},
		{"()"}
	};
	static constexpr int const& inputs = 1;
	vector<int> input1 = {
		3,
		1
	};
};