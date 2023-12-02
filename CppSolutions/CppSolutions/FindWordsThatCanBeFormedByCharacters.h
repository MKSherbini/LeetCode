#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/find-words-that-can-be-formed-by-characters/

class FindWordsThatCanBeFormedByCharacters
{
public:
	// 34 ms, faster than 95.87% : 20.4 MB, less than 73.81%
	int solution(vector<string> words, string chars) {
		vector<int> f(26);
		for (auto c : chars) f[c - 'a']++;
		
		int ans = 0;
		for (auto& s : words) {
			auto t = f;
			bool f = 1;
			for (auto c : s) {
				if (t[c - 'a']-- == 0) {
					f = 0;
					break;
				}
			}
			if (f) ans += size(s);
		}

		return ans;
	}
	vector<int> output = {
		6,
		10
	};
	static constexpr int const& inputs = 2;
	vector<vector<string>> input1 = {
		{"cat","bt","hat","tree"},
		{"hello","world","leetcode"}
	};
	vector<string> input2 = {
		"atach",
		"welldonehoneyr"
	};
};