#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/substring-with-concatenation-of-all-words/

class SubstringWithConcatenationOfAllWords
{
public:
	// 791 ms, faster than 36.7% : 286.3 MB, less than 27.2%
	vector<int> solution(string s, vector<string> words) {
		unordered_map<string, int> f;
		int ws = size(words[0]);
		int target = ws * size(words);

		for (auto w : words)
			f[w]++;

		vector<int> ans;
		for (size_t i = 0; i < size(s) - target + 1; i++)
		{
			if (i == 8)
				int x = 1;
			auto t(f);
			bool gd = 1;
			for (size_t j = 0; j < target; j += ws)
			{
				auto it = begin(t);
				if ((it = t.find(s.substr(i + j, ws))) == end(t) || it->second == 0) {
					gd = 0;
					break;
				}
				it->second--;
			}
			if (gd)
				ans.push_back(i);
		}


		return ans;
	}


	vector<vector<int>> output = {
		{0,9},
		{},
		{6,9,12},
		{8}
	};
	static constexpr int const& inputs = 2;
	vector<string> input1 = {
		"barfoothefoobarman",
		"wordgoodgoodgoodbestword",
		"barfoofoobarthefoobarman",
		"wordgoodgoodgoodbestword"
	};
	vector<vector<string>> input2 = {
		{"foo","bar"},
		{"word","good","best","word"},
		{"bar","foo","the"},
		{"word","good","best","good"}
	};
};