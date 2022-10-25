#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/check-if-two-string-arrays-are-equivalent/

class CheckIfTwoStringArraysAreEquivalent
{
public:
	// 3 ms, faster than 93.69% : 11.2 MB, less than 99.22%
	bool solution(vector<string> word1, vector<string> word2) {
		int n = size(word1), m = size(word2);
		int i = 0, ii = 0, j = 0, jj = 0;

		while (i < n && j < m) {
			if (word1[i][ii++] != word2[j][jj++]) return false;

			if (ii == size(word1[i])) ii = 0, i++;
			if (jj == size(word2[j])) jj = 0, j++;
		}

		return i == n && j == m;
	}
	vector<int> output = {
		true,
		false,
		true
	};
	static constexpr int const& inputs = 2;
	vector<vector<string>> input1 = {
		{"ab", "c"},
		{"a", "cb"},
		{"abc", "d", "defg"}
	};
	vector<vector<string>> input2 = {
		{"a", "bc"},
		{"ab", "c"},
		{"abcddefg"}
	};
};