#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/maximize-score-after-n-operations/

class MaximizeScoreAfterNOperations
{
public:
	// 437 ms, faster than 19.03% : 19.1 MB, less than 20.76%
	int solution(vector<int> nums) {
		int n = size(nums);
		vector<vector<int>> gcds(n, vector<int>(n));
		for (size_t i = 0; i < n; i++) {
			for (size_t j = i + 1; j < n; j++) {
				gcds[i][j] = gcds[j][i] = gcd(nums[i], nums[j]);
			}
		}
		vector<unordered_map< bitset<14>, int>> mem(n / 2);

		function<int(bitset<14>, int)> f = [&](bitset<14> vis, int order)-> int {
			if (order >= n / 2) return 0;
			if (mem[order].count(vis)) return mem[order][vis];
			int ret = 0;
			for (size_t i = 0; i < n; i++) {
				if (vis.test(i)) continue;
				for (size_t j = i + 1; j < n; j++) {
					if (vis.test(j)) continue;
					vis.set(i);
					vis.set(j);
					ret = max(ret, f(vis, order + 1) + (order + 1) * gcds[i][j]);
					vis.reset(i);
					vis.reset(j);
				}
			}
			return mem[order][vis] = ret;
		};
		//f({}, 0);
		//Printer::print(mem);
		return f({}, 0);
	}
	int gcd(int a, int b) {
		if (b > a) return gcd(b, a);
		return b == 0 ? a : gcd(b, a % b);
	}
	vector<int> output = {
		1,
		11,
		14
	};
	static constexpr int const& inputs = 1;
	vector<vector<int>> input1 = {
		{1,2},
		{3,4,6,8},
		{1,2,3,4,5,6}
	};
};