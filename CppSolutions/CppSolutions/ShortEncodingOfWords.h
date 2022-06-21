#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/short-encoding-of-words/

class ShortEncodingOfWords
{
public:
	// 29 ms, faster than 100% : 13.6 MB, less than 100%
	int solution(vector<string> words) {
		for (auto& w : words)
			reverse(begin(w), end(w));
		sort(begin(words), end(words));

		int ans = words[words.size() - 1].size() + 1;

		for (size_t i = 0; i < words.size() - 1; i++)
			if (words[i + 1].rfind(words[i], 0))
				ans += words[i].size() + 1;

		Printer::print(words);
		return ans;
	}
	vector<int> output = {
		10,
		2
	};
	static constexpr int const& inputs = 1;
	vector<vector<string>> input1 = {
		{"time", "me", "bell"},
		{"t"}
	};
};