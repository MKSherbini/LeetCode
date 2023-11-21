#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/count-nice-pairs-in-an-array/

class CountNicePairsInAnArray
{
public:
	// 70 ms, faster than 99.72% : 57 MB, less than 96.91%
	int solution(vector<int> nums) {
		unordered_map<int, int> m;
		const int MOD = 1e9 + 7;
		for (auto x : nums) {
			int t = x;
			int r = 0;
			while (x) {
				r *= 10;
				r += x % 10;
				x /= 10;
			}
			m[t - r]++;
		}

		long long ans = 0;
		for (auto& [x, c] : m) {
			ans += 1ll * c * (c - 1) / 2;
			ans %= MOD;
		}

		return ans;
	}
	vector<int> output = {
		2,
		4
	};
	static constexpr int const& inputs = 1;
	vector<vector<int>> input1 = {
		{42,11,1,97},
		{13,10,35,24,76}
	};
};