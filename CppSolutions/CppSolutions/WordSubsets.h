#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/word-subsets/

class WordSubsets
{
public:
	// 213 ms, faster than 82.92% : 102.2 MB, less than 77.08%
	vector<string> solution(vector<string> words1, vector<string> words2) {
		vector target(26, 0);

		for (auto& w : words2) {
			vector t(26, 0);
			for (auto& c : w)
				t[c - 'a']++;
			for (size_t i = 0; i < 26; i++)
				target[i] = max(target[i], t[i]);
		}
		Printer::print(target);
		vector<string> ans;
		for (auto& w : words1) {
			vector t(target);
			bool valid = 1;
			for (auto& c : w)
				t[c - 'a']--;
			Printer::print(t);
			for (auto& x : t)
				if (x > 0) valid = false;
			if (valid) ans.push_back(w);
		}


		return ans;
	}
	vector<vector<string>> output = {
		{"facebook","google","leetcode"},
		{"apple","google","leetcode"}
	};
	static constexpr int const& inputs = 2;
	vector<vector<string>> input1 = {
		{"amazon","apple","facebook","google","leetcode"},
		{"amazon","apple","facebook","google","leetcode"}
	};
	vector<vector<string>> input2 = {
		{"e","o"},
		{"l","e"}
	};
};