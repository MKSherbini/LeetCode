#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/product-of-array-except-self/

class ProductOfArrayExceptSelf
{
public:
	// 69 ms, faster than 5.47% : 23.9 MB, less than 95.44%
	vector<int> solution(vector<int> nums) {
		int n = size(nums);
		vector<int> f(61, 1);
		for (auto x : nums)
			if (x == 0)
				f[x + 30]++;
			else
				f[x + 30] *= x;
		f[30]--;

		vector<int> ans(n, 1);
		for (int i = 0; i < n; i++) {
			if (f[30] - (nums[i] == 0) > 0) {
				ans[i] = 0;
				continue;
			}
			for (int j = 0; j < 61; j++) {
				if (j == 30) continue;
				if (j - 30 != nums[i])
					ans[i] *= f[j];
				else
					ans[i] *= f[j] / (j - 30);
			}
		}

		return ans;
	}
	vector<vector<int>> output = {
		{24,12,8,6},
		{0,0,9,0,0},
		{-51438240,-28576800,-128595600,28576800,28576800,36741600,32148900,-36741600,28576800,-25719120}
	};
	static constexpr int const& inputs = 1;
	vector<vector<int>> input1 = {
		{1,2,3,4},
		{-1,1,0,-3,3},
		{5,9,2,-9,-9,-7,-8,7,-9,10}
	};
};