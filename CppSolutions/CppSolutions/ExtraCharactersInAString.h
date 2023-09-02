#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/extra-characters-in-a-string/

class ExtraCharactersInAString
{
public:
	// 52 ms, faster than 99.04% : 61.3 MB, less than 92.82%
	int solution(string s, vector<string> dictionary) {
		set<int> sizes;
		unordered_set<string> words;

		for (auto& s : dictionary)
			sizes.insert(size(s)), words.insert(s);

		int n = size(s);
		vector mem(n, -1);
		function<int(int)> f = [&](int i) -> int {
			if (i == n) return 0;
			if (mem[i] != -1) return mem[i];

			int ret = 1 + f(i + 1);
			for (auto sz : sizes) {
				if (i + sz > n) break;
				Printer::print(s.substr(i, sz), words.count(s.substr(i, sz)));
				if (words.count(s.substr(i, sz)))
					ret = min(ret, f(i + sz));
			}

			return mem[i] = ret;
		};

		return f(0);
	}
	vector<int> output = {
		1,
		3
	};
	static constexpr int const& inputs = 2;
	vector<string> input1 = {
		"leetscode",
		"sayhelloworld"
	};
	vector<vector<string>> input2 = {
		{"leet","code","leetcode"},
		{"hello","world"}
	};
};