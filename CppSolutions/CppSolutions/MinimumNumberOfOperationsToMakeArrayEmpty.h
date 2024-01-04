#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/minimum-number-of-operations-to-make-array-empty/

class MinimumNumberOfOperationsToMakeArrayEmpty
{
public:
	// 98 ms, faster than 97.79% : 85.1 MB, less than 90.06%
	int solution(vector<int> nums) {
		unordered_map<int, int> m;
		for (auto x : nums) {
			m[x]++;
		}

		Printer::print(m);
		int ans = 0;
		for (auto& [_, c] : m) {
			int t = c / 3;
			c %= 3;
			if (c == 2 || (c == 1 && t)) {
				ans++;
			}
			else if (c == 1) {
				return -1;
			}
			ans += t;
		}

		return ans;
	}
	vector<int> output = {
		4,
		-1
	};
	static constexpr int const& inputs = 1;
	vector<vector<int>> input1 = {
		{2,3,3,2,2,4,2,3,4},
		{2,1,2,2,3,3}
	};
};