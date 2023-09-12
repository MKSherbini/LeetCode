#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/decode-string/?envType=study-plan-v2&envId=leetcode-75

class DecodeString
{
public:
	// 0 ms, faster than 100% : 6.6 MB, less than 55.53%
	string solution(string s) {
		int n = size(s);
		stack<int> st;
		unordered_map<int, int> m;
		for (size_t i = 0; i < n; i++) {
			if (s[i] == '[') st.push(i);
			else if (s[i] == ']') m[st.top()] = i, st.pop();
		}

		function<string(int, int)> f = [&](int i, int j) -> string {
			if (i > j) return {};
			if (isalpha(s[i])) {
				string ret;
				while (i <= j && isalpha(s[i])) {
					ret += s[i++];
				}
				return ret + f(i, j);
			}
			string rs;
			while (isdigit(s[i])) {
				rs += s[i++];
			}
			int r = stoi(rs);
			ostringstream repeated;
			fill_n(ostream_iterator<string>(repeated), r, f(i + 1, m[i] - 1));
			return repeated.str() + f(m[i] + 1, j);
		};

		return f(0, n - 1);
	}
	vector<string> output = {
		"aaabcbc",
		"accaccacc",
		"abcabccdcdcdef"
	};
	static constexpr int const& inputs = 1;
	vector<string> input1 = {
		"3[a]2[bc]",
		"3[a2[c]]",
		"2[abc]3[cd]ef"
	};
};