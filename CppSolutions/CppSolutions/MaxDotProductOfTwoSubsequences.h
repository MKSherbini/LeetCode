#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/max-dot-product-of-two-subsequences/

class MaxDotProductOfTwoSubsequences
{
public:
	// 46 ms, faster than 35.48% : 13.8 MB, less than 21.08%
	int solution(vector<int> nums1, vector<int> nums2) {
		int n = size(nums1), m = size(nums2);

		auto [mn1, mx1] = minmax_element(begin(nums1), end(nums1));
		auto [mn2, mx2] = minmax_element(begin(nums2), end(nums2));

		if ((*mx1 <= 0 && *mn2 >= 0) ||
			(*mn1 >= 0 && *mx2 <= 0)) {
			return max(*mn1 * *mx2, *mn2 * *mx1);
		}

		vector mem(n, vector(m, -1));
		function<int(int, int)> f = [&](int i, int j) -> int {
			if (i == n || j == m) return 0;
			if (mem[i][j] != -1) return mem[i][j];

			int ret = f(i + 1, j);
			ret = max(ret, f(i, j + 1));
			ret = max(ret, nums1[i] * nums2[j] + f(i + 1, j + 1));

			return mem[i][j] = ret;
		};

		return f(0, 0);
	}
	vector<int> output = {
		18,
		21,
		-1
	};
	static constexpr int const& inputs = 2;
	vector<vector<int>> input1 = {
		{2,1,-2,5},
		{3,-2},
		{-1,-1}
	};
	vector<vector<int>> input2 = {
		{3,0,-6},
		{2,-6,7},
		{1,1}
	};
};