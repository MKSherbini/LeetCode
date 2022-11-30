#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/unique-number-of-occurrences/

class UniqueNumberOfOccurrences
{
public:
	// 0 ms, faster than 100% : 8.6 MB, less than 6.37%
	bool solution(vector<int> arr) {
		vector<int> f(2001, 0);

		for (auto x : arr)
			f[x + 1000]++;

		sort(begin(f), end(f), greater());

		for (size_t i = 1; i < size(f); i++)
			if (!f[i]) break;
			else if (f[i] == f[i - 1]) return false;

		return true;
	}
	vector<int> output = {
		true,
		false,
		true
	};
	static constexpr int const& inputs = 1;
	vector<vector<int>> input1 = {
		{1,2,2,1,1,3},
		{1,2},
		{-3,0,1,-3,1,1,1,-3,10,0}
	};
};