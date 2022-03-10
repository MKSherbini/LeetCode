#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/minimum-size-subarray-sum/

class MinimumSizeSubarraySum
{
public:
	// 4 ms, faster than 96.26% : 10.5 MB, less than 92.65%
	int solution(int target, vector<int> nums) {
		int ans = INT_MAX;
		int tempSum = 0;
		for (int i = 0, st = 0; i < nums.size(); i++)
		{
			tempSum += nums[i];

			while (tempSum >= target) {
				if (tempSum >= target)
					ans = min(ans, i - st + 1);
				//Printer::print(st);
				//Printer::print(i);
				//Printer::print(tempSum);
				//Printer::print(ans, 1);
				tempSum -= nums[st];
				st++;
			}
		}
		return ans == INT_MAX ? 0 : ans;
	}
	vector<int> output = {
		2,
		1,
		0,
		3
	};
	static constexpr int const& inputs = 2;
	vector<int> input1 = {
		7,
		4,
		11,
		11
	};
	vector<vector<int>> input2 = {
		{2,3,1,2,4,3},
		{1,0,0,4,4},
		{1,1,1,1,1,1,1,1},
		{1,2,3,4,5}
	};
};