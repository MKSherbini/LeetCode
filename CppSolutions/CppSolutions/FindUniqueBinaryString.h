#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/find-unique-binary-string/

class FindUniqueBinaryString
{
public:
	// 0 ms, faster than 100% : 10.6 MB, less than 75.23%
	string solution(vector<string> nums) {
		int n = size(nums);
		unordered_set<string> s;
		for (auto& num : nums)
			s.insert(num);

		string t(n, '0');
		if (!s.count(t)) return t;
		for (size_t i = 0; i < n; i++) {
			t[i] = '1';
			if (!s.count(t)) return t;
		}

		return "WTF";
	}
	vector<string> output = {
		"11",
		"11",
		"101"
	};
	static constexpr int const& inputs = 1;
	vector<vector<string>> input1 = {
		{"01","10"},
		{"00","01"},
		{"111","011","001"}
	};
};