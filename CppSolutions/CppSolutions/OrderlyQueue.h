#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/orderly-queue/

class OrderlyQueue
{
public:
	// 0 ms, faster than 100% : 10.6 MB, less than 67.82%
	string solution(string s, int k) {
		if (k > 1) {
			sort(begin(s), end(s));
			return s;
		}

		string ans = s;

		for (size_t i = 0; i < size(s); i++)
			ans = min(ans, s.substr(i) + s.substr(0, i));

		return ans;
	}
	vector<string> output = {
		"acb",
		"aaabc"
	};
	static constexpr int const& inputs = 2;
	vector<string> input1 = {
		"cba",
		"baaca"
	};
	vector<int> input2 = {
		1,
		3
	};
};