#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/isomorphic-strings/

class IsomorphicStrings
{
public:
	// 3 ms, faster than 91.67% : 9.2 MB, less than 63.46%
	uint8_t solution(string s, string t) {
		int n = size(s);
		unordered_map<char, char> m;
		unordered_set<char> st;
		for (size_t i = 0; i < n; i++) {
			if ((m.count(s[i]) && m[s[i]] == t[i])) continue;

			if (st.count(t[i])) return 0;
			else if (!m.count(s[i])) m[s[i]] = t[i], st.insert(t[i]);
			else if (m[s[i]] != t[i]) return 0;
		}

		return 1;
	}
	vector<uint8_t> output = {
		true,
		false,
		true
	};
	static constexpr int const& inputs = 2;
	vector<string> input1 = {
		"egg",
		"foo",
		"paper"
	};
	vector<string> input2 = {
		"add",
		"bar",
		"title"
	};
};