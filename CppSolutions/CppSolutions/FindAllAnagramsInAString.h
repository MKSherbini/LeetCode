#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/find-all-anagrams-in-a-string/

class FindAllAnagramsInAString
{
public:
	// 8 ms, faster than 97.2% : 8.5 MB, less than 98.38%
	vector<int> solution(string s, string p) {
		vector<int> ans;
		vector<int> pCharsCount(26, 0);
		for (int i = 0; i < p.size(); i++)
			pCharsCount[p[i] - 'a']++;

		vector<int> tempCharsCount(26, 0);
		for (int i = 0, st = 0; i < s.size(); i++)
		{
			if (pCharsCount[s[i] - 'a'] == 0) {
				fill(begin(tempCharsCount), end(tempCharsCount), 0);
				st = i + 1;
				continue;
			}

			tempCharsCount[s[i] - 'a']++;


			while (tempCharsCount[s[i] - 'a'] > pCharsCount[s[i] - 'a']) {
				//Printer::print(s.substr(st, i - st + 1));
				tempCharsCount[s[st] - 'a']--;
				st++;
			}

			if (i - st + 1 == p.size()) ans.push_back(st);
			//Printer::print(s.substr(st, i - st + 1), 1);
		}
		return ans;
	}
	vector<vector<int>> output = {
		{0,6},
		{0,1,2}
	};
	static constexpr int const& inputs = 2;
	vector<string> input1 = {
		"cbaebabacd",
		"abab"
	};
	vector<string> input2 = {
		"abc",
		"ab"
	};
};