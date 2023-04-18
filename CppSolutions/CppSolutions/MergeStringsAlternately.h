#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/merge-strings-alternately/

class MergeStringsAlternately
{
public:
	// 0 ms, faster than 100% : 6.1 MB, less than 98.18%
	string solution(string word1, string word2) {
		int i = 0, j = 0, n = size(word1), m = size(word2);

		string ans;
		while (i < n && j < m)
			ans += word1[i++], ans += word2[j++];

		while (i < n)
			ans += word1[i++];

		while (j < m)
			ans += word2[j++];

		return ans;
	}
	vector<string> output = {
		"apbqcr",
		"apbqrs",
		"apbqcd"
	};
	static constexpr int const& inputs = 2;
	vector<string> input1 = {
		"abc",
		"ab",
		"abcd"
	};
	vector<string> input2 = {
		"pqr",
		"pqrs",
		"pq"
	};
};