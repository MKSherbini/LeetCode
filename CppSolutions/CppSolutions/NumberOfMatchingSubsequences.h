#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/number-of-matching-subsequences/

class NumberOfMatchingSubsequences
{
public:
	// 704 ms, faster than 22.54% : 387.2 MB, less than 5.31%
	int solution(string s, vector<string> words) {
		vector mem(size(s), vector<int>(26, size(s) + 1));

		for (int i = size(s) - 1; i >= 0; i--)
		{
			if (i < size(s) - 1) mem[i] = mem[i + 1];
			mem[i][s[i] - 'a'] = i;
		}

		int ans = 0;
		for (auto& w : words)
			if (find(mem, w)) {
				//Printer::print(w);
				ans++;
			}

		return ans;
	}

	bool find(vector<vector<int>>& mem, string& w) {
		int i = 0, j = 0;
		while (i < size(mem) && j < size(w)) {
			//Printer::print(i, j, mem[i][w[j] - 'a']);
			i = mem[i][w[j++] - 'a'] + 1;
		}
		return i <= size(mem) && j == size(w);
	}

	vector<int> output = {
		3,
		2
	};
	static constexpr int const& inputs = 2;
	vector<string> input1 = {
		"abcde",
		"dsahjpjauf"
	};
	vector<vector<string>> input2 = {
		{"a","bb","acd","ace"},
		{"ahjpjau","ja","ahbwzgqnuk","tnmlanowax"}
	};
};