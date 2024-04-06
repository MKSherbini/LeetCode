#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/

class MinimumRemoveToMakeValidParentheses
{
public:
	// 11 ms, faster than 98.91% : 12.1 MB, less than 83.63%
	string solution(string s) {
		int n = size(s);
		int cnt = 0;
		for (size_t i = 0; i < n; i++) {
			if (s[i] == '(') cnt++;
			else if (s[i] == ')') {
				if (!cnt) s[i] = '#';
				else cnt--;
			}
		}
		cnt = 0;
		for (int i = n - 1; i >= 0; i--) {
			if (s[i] == ')') cnt++;
			else if (s[i] == '(') {
				if (!cnt) s[i] = '#';
				else cnt--;
			}
		}

		string ans;
		for (auto c : s) {
			if (c == '#') continue;
			ans += c;
		}

		return ans;
	}

	// 11 ms, faster than 98.91% : 13.9 MB, less than 21.47%
	string solution2(string s) {
		int n = size(s);
		stack<int> st;
		for (size_t i = 0; i < n; i++) {
			if (s[i] == '(') st.push(i);
			else if (s[i] == ')') {
				if (st.empty()) s[i] = '#';
				else st.pop();
			}
		}

		while (!st.empty()) {
			s[st.top()] = '#';
			st.pop();
		}

		string ans;
		for (auto c : s) {
			if (c == '#') continue;
			ans += c;
		}

		return ans;
	}
	vector<string> output = {
		"lee(t(c)o)de",
		"ab(c)d",
		""
	};
	static constexpr int const& inputs = 1;
	vector<string> input1 = {
		"lee(t(c)o)de)",
		"a)b(c)d",
		"))(("
	};
};