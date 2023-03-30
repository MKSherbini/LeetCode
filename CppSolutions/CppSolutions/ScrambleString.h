#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/scramble-string/

class ScrambleString
{
public:
	// 146 ms, faster than 59.19% : 36.7 MB, less than 42.65%
	bool solution(string s1, string s2) {
		return f(s1, s2);
	}
	bool f(string s1, string s2) {
		int n = size(s1);
		if (s1 == s2) return true;
		if (n == 1) return false;

		string key = s1 + "/" + s2;
		if (mem.find(key) != end(mem)) return mem[key];

		for (size_t i = 1; i < n; i++) {
			if (f(s1.substr(0, i), s2.substr(0, i))
				&& f(s1.substr(i), s2.substr(i)))
				return mem[key] = true;

			if (f(s1.substr(0, i), s2.substr(n - i))
				&& f(s1.substr(i), s2.substr(0, n - i)))
				return mem[key] = true;
		}

		return mem[key] = false;
	}
	unordered_map<string, bool> mem;

	vector<int> output = {
		true,
		false,
		true
	};
	static constexpr int const& inputs = 2;
	vector<string> input1 = {
		"great",
		"abcde",
		"a"
	};
	vector<string> input2 = {
		"rgeat",
		"caebd",
		"a"
	};
};