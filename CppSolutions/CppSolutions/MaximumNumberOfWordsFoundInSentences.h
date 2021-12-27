#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/maximum-number-of-words-found-in-sentences/

class MaximumNumberOfWordsFoundInSentences
{
public:
	// 12 ms, faster than 68.75% : 9.6 MB, less than 93.75%
	int solution(vector<string>& sentences) {
		int mx = 0;
		for (int i = 0; i < sentences.size(); i++)
		{
			int cnt = 1;
			for (int j = 0; j < sentences[i].size(); j++)
				if (sentences[i][j] == ' ') cnt++;

			mx = max(mx, cnt);
		}
		return mx;
	}
	vector<int> output = {
		6,
		3,
		1,
	};
	vector<vector<string>> input1 = {
		{"alice and bob love leetcode", "i think so too", "this is great thanks very much"},
		{"please wait", "continue to fight", "continue to win"},
		{"a"},
	};
};

