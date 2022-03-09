#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/subarray-product-less-than-k/

class SubarrayProductLessThanK
{
public:
	// 76 ms, faster than 89.6% : 61.2 MB, less than 93.55%
	int solution(vector<int> nums, int k) {
		if (k <= 1) return 0;
		int ans = 0;
		int tempProd = 1;
		for (int i = 0, st = 0; i < nums.size(); i++)
		{
			tempProd *= nums[i];
			while (tempProd > k && st < i) {
				tempProd /= nums[st];
				st++;
			}

			if (tempProd <= k)
				ans += i - st + (tempProd != k);
			//Printer::print(nums[st]);
			//Printer::print(nums[i]);
			//Printer::print(ans, 1);
		}
		return ans;
	}
	vector<int> output = {
		8,
		0,
		0
	};
	static constexpr int const& inputs = 2;
	vector<vector<int>> input1 = {
		{10,5,2,6},
		{1,2,3},
		{1,1,1}
	};
	vector<int> input2 = {
		100,
		0,
		1
	};
};