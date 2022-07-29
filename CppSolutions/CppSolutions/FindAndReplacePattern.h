#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/find-and-replace-pattern/

class FindAndReplacePattern
{
public:
	// 0 ms, faster than 100% : 8.2 MB, less than 83.72%
	vector<string> solution(vector<string> words, string pattern) {
		vector<string> ans;
		for (auto w : words)
		{
			map<char, char> m;
			int used[26] = { 0 };
			bool valid = true;
			for (size_t i = 0; i < size(w); i++)
			{
				if (m.find(w[i]) == end(m)) {
					if (used[pattern[i] - 'a']) {
						valid = false;
						break;
					}
					m[w[i]] = pattern[i];
					used[pattern[i] - 'a'] = 1;
				}
				else if (m[w[i]] != pattern[i]) {
					valid = false;
					break;
				}
			}
			if (valid) ans.push_back(w);
		}
		return ans;
	}
	vector<vector<string>> output = {
		{"mee","aqq"},
		{"a","b","c"}
	};
	static constexpr int const& inputs = 2;
	vector<vector<string>> input1 = {
		{"abc","deq","mee","aqq","dkd","ccc"},
		{"a","b","c"}
	};
	vector<string> input2 = {
		"abb",
		"a"
	};
};