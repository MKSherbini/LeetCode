#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/sorting-the-sentence/

class SortingTheSentence
{
public:
	// 0 ms, faster than 100.00% : 6 MB, less than 99.29%
	string solution(string s) {
		map<int, pair<int, int>> words;
		int lastStart = 0;

		for (int i = 0; i < s.size(); i++)
			if (isdigit(s[i]))
				words[s[i] - 49] = { lastStart, i }, lastStart = i + 2;

		string res(s.size() - words.size(), ' ');
		for (int i = 0, it = 0; i < words.size(); i++) {
			if (i) it++;
			for (int j = words[i].first; j < words[i].second; j++)
				res[it++] = s[j];
		}

		return  res;
	}
	vector<string> output = {
		"This is a sentence",
		"Me Myself and I",
	};
	vector<string> input1 = {
		"is2 sentence4 This1 a3",
		"Myself2 Me1 I4 and3",
	};
};

