#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/binary-subarrays-with-sum/

class BinarySubarraysWithSum
{
public:
	// 14 ms, faster than 97.34% : 31 MB, less than 94.65%
	int solution(vector<int> nums, int goal) {
		int n = size(nums);
		int i = 0, j = 0, sum = 0;
		int zeros = 0;
		int ans = 0;

		while (j < n) {
			sum += nums[j];

			while (i < j && nums[i] == 1 && sum > goal) {
				sum--;
				zeros = 0;
				i++;
			}
			while (i < j && nums[i] == 0) {
				zeros++;
				i++;
			}

			if (sum == goal) ans += zeros + 1;
			j++;
			Printer::print(i, j, zeros, sum);
		}

		return ans;
	}
	vector<int> output = {
		4,
		15
	};
	static constexpr int const& inputs = 2;
	vector<vector<int>> input1 = {
		{1,0,1,0,1},
		{0,0,0,0,0}
	};
	vector<int> input2 = {
		2,
		0
	};
};