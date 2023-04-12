#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/simplify-path/

class SimplifyPath
{
public:
	// 0 ms, faster than 100% : 11.1 MB, less than 6.95%
	string solution(string path) {
		vector<string> v(1);
		int n = size(path);
		for (size_t i = 0; i < n; i++) {
			if (path[i] == '/' && !v.back().empty()) v.push_back("");
			while (i < n && path[i] == '/') {
				i++;
			}
			if (i >= n) break;
			v.back() += path[i];
		}
		if (v.back().empty()) v.pop_back();

		Printer::print(v);
		int del = 0;
		string ans;
		for (int i = size(v) - 1; i >= 0; i--) {
			if (v[i] == "..") del++;
			else if (v[i] == ".");
			else if (del) del--;
			else ans = "/" + v[i] + ans;
		}

		return ans.empty() ? "/" : ans;
	}
	vector<string> output = {
		"/home",
		"/",
		"/home/foo"
	};
	static constexpr int const& inputs = 1;
	vector<string> input1 = {
		"/home/",
		"/../",
		"/home//foo/"
	};
};