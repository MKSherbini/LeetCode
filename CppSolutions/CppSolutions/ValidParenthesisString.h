#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/valid-parenthesis-string/

class ValidParenthesisString
{
public:
	// 0 ms, faster than 100% : 7.4 MB, less than 53.16%
	uint8_t solution(string s) {
		int cnt = 0;
		int n = size(s);

		stack<int> magic;
		for (size_t i = 0; i < n; i++) {
			if (s[i] == '(') cnt++;
			else if (s[i] == '*') magic.push(i);
			else if (s[i] == ')') {
				if (cnt) cnt--;
				else if (!empty(magic)) s[magic.top()] = '(', magic.pop();
				else return false;
			}
		}

		cnt = 0, magic = {};
		for (int i = n - 1; i >= 0; i--) {
			if (s[i] == ')') cnt++;
			else if (s[i] == '*') magic.push(i);
			else if (s[i] == '(') {
				if (cnt) cnt--;
				else if (!empty(magic)) s[magic.top()] = ')', magic.pop();
				else return false;
			}
		}

		return true;
	}
	vector<uint8_t> output = {
		true,
		true,
		true
	};
	static constexpr int const& inputs = 1;
	vector<string> input1 = {
		"()",
		"(*)",
		"(*))"
	};
};