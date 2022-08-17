#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/unique-morse-code-words/

class UniqueMorseCodeWords
{
public:
	// 0 ms, faster than 100% : 8.4 MB, less than 98.15%
	int solution(vector<string> words) {
		vector morse = { ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."
		};
		set<string> s;

		for (auto w : words)
		{
			string res;
			for (auto c : w)
				res += morse[c - 'a'];
			s.insert(res);
		}
		return size(s);
	}
	vector<int> output = {
		2,
		1
	};
	static constexpr int const& inputs = 1;
	vector<vector<string>> input1 = {
		{"gin","zen","gig","msg"},
		{"a"}
	};
};