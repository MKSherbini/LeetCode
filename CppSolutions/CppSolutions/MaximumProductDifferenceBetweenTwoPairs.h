#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/maximum-product-difference-between-two-pairs/

class MaximumProductDifferenceBetweenTwoPairs
{
public:
	// 12 ms, faster than 98.38% : 20.6 MB, less than 64.73%
	int solution(vector<int> nums) {
		vector<int> mn(2, 1e5), mx(2, 0);
		for (auto x : nums) {
			if (x > mx[0]) mx[0] = x;
			if (x < mn[1]) mn[1] = x;
			if (mn[0] > mn[1]) swap(mn[0], mn[1]);
			if (mx[0] > mx[1]) swap(mx[0], mx[1]);
			Printer::print(mn, mx);
		}

		return mx[0] * mx[1] - mn[0] * mn[1];
	}
	vector<int> output = {
		34,
		64
	};
	static constexpr int const& inputs = 1;
	vector<vector<int>> input1 = {
		{5,6,2,7,4},
		{4,2,5,9,7,4,8}
	};
};