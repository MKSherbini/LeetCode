#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/concatenated-words/

class ConcatenatedWords
{
public:
	// 128 ms, faster than 100% : 39.3 MB, less than 94.79%
	vector<string> solution(vector<string> words) {
		unordered_set<string> m;
		vector<int> sizes(30);
		for (auto& w : words)
			m.insert(w), sizes[size(w) - 1] = 1;

		vector<string> ans;
		for (auto& w : words) {
			if (match(w, sizes, m, 0)) ans.push_back(w);
		}

		return ans;
	}
	bool match(string& w, vector<int>& sizes, unordered_set<string>& m, int st) {
		if (st == size(w)) return true;
		int ret = 0;
		for (int i = size(w) - st - 1 - (st == 0); i >= 0; i--) {
			if (!sizes[i]) continue;
			int sz = i + 1;
			if (m.count(w.substr(st, sz))) {
				ret |= match(w, sizes, m, st + sz);
				if (ret) return ret;
			}
		}
		return ret;
	}
	vector<vector<string>> output = {
		{"catsdogcats","dogcatsdog","ratcatdogcat"},
		{"catdog"}
	};
	static constexpr int const& inputs = 1;
	vector<vector<string>> input1 = {
		{"cat","cats","catsdogcats","dog","dogcatsdog","hippopotamuses","rat","ratcatdogcat"},
		{"cat","dog","catdog"}
	};
};