#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/find-first-palindromic-string-in-the-array/

class FindFirstPalindromicStringInTheArray
{
public:
	// 42 ms, faster than 87.39% : 23.2 MB, less than 83.77%
	string solution(vector<string> words) {
		for (auto& w : words) {
			int n = size(w);
			for (size_t i = 0; i < n / 2; i++) {
				if (w[i] != w[n - i - 1]) goto out;
			}
			return w;
		out:;
		}

		return "";
	}
	vector<string> output = {
		"ada",
		"racecar",
		""
	};
	static constexpr int const& inputs = 1;
	vector<vector<string>> input1 = {
		{"abc","car","ada","racecar","cool"},
		{"notapalindrome","racecar"},
		{"def","ghi"}
	};
};