#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/count-subarrays-with-fixed-bounds/

class CountSubarraysWithFixedBounds
{
public:
	// 102 ms, faster than 96.73% : 70.2 MB, less than 100%
	long long  solution(vector<int> nums, int minK, int maxK) {
		int n = size(nums);

		long long ans = 0;
		int mn = -1, mx = -1, last = -1;
		for (size_t k = 0; k < n; k++) {
			if (nums[k] == minK) {
				mn = k;
			}
			if (nums[k] == maxK) {
				mx = k;
			}
			if (nums[k] < minK || nums[k] > maxK) {
				last = k, mn = -1, mx = -1;
			}

			if (mn != -1 && mx != -1) {
				Printer::print(min(mn, mx), max(mn, mx), last);
				ans += min(mn, mx) - last;
			}
		}

		return ans;
	}
	vector<int> output = {
		81,
		8,
		2,
		10
	};
	static constexpr int const& inputs = 3;
	vector<vector<int>> input1 = {
		{1, 4, 10, 10, 8, 10, 1, 10, 3, 10, 1, 2, 7, 5, 6},
		{4,1,5,1,4},
		{1,3,5,2,7,5},
		{1,1,1,1}
	};
	vector<int> input2 = {
		1,
		1,
		1,
		1
	};
	vector<int> input3 = {
		10,
		5,
		5,
		1
	};
	//4,1,5,1,4
	//1,5
	//4,1,5
	//4,1,5,1
	//4,1,5,1,4	
	//1,5,1
	//1,5,1,4
	//5,1
	//5,1,4
	//
	//
	//
};