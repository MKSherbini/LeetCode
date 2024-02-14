#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/rearrange-array-elements-by-sign/

class RearrangeArrayElementsBySign
{
public:
	// 127 ms, faster than 96.63% : 126.2 MB, less than 60.27%
	vector<int> solution(vector<int> nums) {
		int n = size(nums);
		vector<int> ans(n);

		auto nextEl = [&](int st, bool sign) {
			int ret = -1;
			for (size_t i = st; i < n; i++) {
				if ((sign && nums[i] > 0) || (!sign && nums[i] < 0)) {
					ret = i;
					break;
				}
			}
			return ret;
		};
		bool sign = 1;
		int stN = -1, stP = -1;
		for (size_t i = 0; i < n; i++) {
			ans[i] = sign ? nums[stP = nextEl(stP + 1, 1)] : nums[stN = nextEl(stN + 1, 0)];
			sign = !sign;
		}

		return ans;
	}
	vector<vector<int>> output = {
		{3,-2,1,-5,2,-4},
		{1,-1}
	};
	static constexpr int const& inputs = 1;
	vector<vector<int>> input1 = {
		{3,1,-2,-5,2,-4},
		{-1,1}
	};
};