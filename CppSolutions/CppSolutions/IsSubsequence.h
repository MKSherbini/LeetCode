#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/is-subsequence/?envType=study-plan-v2&envId=leetcode-75

class IsSubsequence
{
public:
	// 0 ms, faster than 100% : 6.3 MB, less than 55.75%
	bool solution(string s, string t) {
		int n = size(s), m = size(t);
		int i = 0, j = 0;

		while (i < n && j < m) {
			if (s[i] == t[j]) i++, j++;
			else j++;
		}

		return i == n;
	}
	vector<int> output = {
		true,
		false
	};
	static constexpr int const& inputs = 2;
	vector<string> input1 = {
		"abc",
		"axc"
	};
	vector<string> input2 = {
		"ahbgdc",
		"ahbgdc"
	};
};