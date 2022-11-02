#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/minimum-genetic-mutation/

class MinimumGeneticMutation
{
public:
	// 0 ms, faster than 100% : 6.3 MB, less than 100%
	int solution(string start, string end, vector<string> bank) {
		int ans = f(start, end, bank, {});
		return ans == OO ? -1 : ans;
	}

	int f(string& cur, string& end, vector<string>& bank, bitset<11> taken) {
		if (cur == end) return 0;

		int ret = OO;
		for (size_t i = 0; i < size(bank); i++) {
			if (!taken.test(i) && oneMutation(cur, bank[i])) {
				taken.set(i);
				ret = min(ret, 1 + f(bank[i], end, bank, taken));
				taken.reset(i);
			}
		}

		return ret;
	}

	bool oneMutation(string& s, string& s2) {
		bool dif = 0;

		for (size_t i = 0; i < 8; i++)
			if (s[i] != s2[i])
				if (dif) return false;
				else dif = 1;

		return true;
	}

	const int OO = 99;

	vector<int> output = {
		1,
		2,
		3
	};
	static constexpr int const& inputs = 3;
	vector<string> input1 = {
		"AACCGGTT",
		"AACCGGTT",
		"AAAAACCC"
	};
	vector<string> input2 = {
		"AACCGGTA",
		"AAACGGTA",
		"AACCCCCC"
	};
	vector<vector<string>> input3 = {
		{"AACCGGTA"},
		{"AACCGGTA","AACCGCTA","AAACGGTA"},
		{"AAAACCCC","AAACCCCC","AACCCCCC"}
	};
};