#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/word-break/

class WordBreak
{
public:
	// 0 ms, faster than 100% : 7.9 MB, less than 81.09%
	bool solution(string s, vector<string> wordDict) {
		int n = size(s);
		set<int> sizes;
		set<string> words;

		for (auto w : wordDict)
			sizes.insert(size(w)), words.insert(w);

		vector<int> mem(s.size(), -1);
		function<bool(int)> f = [&](int i) -> bool {
			if (i == n) return true;
			if (mem[i] != -1) return mem[i];

			bool ret = 0;

			for (auto size : sizes) {
				if (size + i > n) continue;
				Printer::print(i, size, s.substr(i, size), words.count(s.substr(i, size)));
				if (!words.count(s.substr(i, size))) continue;
				ret |= f(i + size);
			}

			return mem[i] = ret;
		};

		return f(0);
	}

	// 0 ms, faster than 100% : 7.5 MB, less than 95.42%
	bool solution2(string s, vector<string> wordDict) {
		vector<int> mem(s.size(), -1);
		auto ret = curse(s, wordDict, mem, 0);
		Printer::print(mem);
		return max(0, ret);
	}
	int curse(string& s, vector<string>& wordDict, vector<int>& mem, int i) {
		if (i == s.size()) return 1;
		if (mem[i] != -1) return mem[i];

		int ret = 0;
		for (auto word : wordDict) {
			int sz = word.size();
			if (s.substr(i, sz) == word) {
				ret |= curse(s, wordDict, mem, i + sz);
				if (ret) break;
			}
		}

		return mem[i] = ret;
	}
	vector<int> output = {
		true,
		true,
		false
	};
	static constexpr int const& inputs = 2;
	vector<string> input1 = {
		"leetcode",
		"applepenapple",
		"catsandog"
	};
	vector<vector<string>> input2 = {
		{"leet","code"},
		{"apple","pen"},
		{"cats","dog","sand","and","cat"}
	};
};