#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/find-the-original-array-of-prefix-xor/

class FindTheOriginalArrayOfPrefixXor
{
public:
	// 72 ms, faster than 96.84% : 76.1 MB, less than 88.47%
	vector<int> solution(vector<int> pref) {
		int n = size(pref);
		vector<int> ans(n);
		int x = 0;
		for (size_t i = 0; i < n; i++) {
			ans[i] = x ^ pref[i];
			x ^= ans[i];
		}
		return ans;
	}
	vector<vector<int>> output = {
		{5,7,2,3,2},
		{13}
	};
	static constexpr int const& inputs = 1;
	vector<vector<int>> input1 = {
		{5,2,0,3,1},
		{13}
	};
};