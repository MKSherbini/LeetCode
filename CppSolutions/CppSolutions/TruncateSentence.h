#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/truncate-sentence/

class TruncateSentence
{
public:
	// 0 ms, faster than 100% : 6.4 MB, less than 83.94%
	string solution(string s, int k) {
		int it = 0;
		while (k--)
		{
			it++;
			while (it<s.size()&&s[it] != ' ')
				it++;
		}
		return s.substr(0, it);
	}
	vector<string> output = {
		"Hello how are you",
		"What is the solution",
		"chopper is not a tanuki",
	};
	static constexpr int const& inputs = 2;
	vector<string> input1 = {
		"Hello how are you Contestant",
		"What is the solution to this problem",
		"chopper is not a tanuki",
	};
	vector<int> input2 = {
		4,
		4,
		5,
	};

};

