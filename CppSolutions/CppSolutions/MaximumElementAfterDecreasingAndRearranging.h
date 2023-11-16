#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/maximum-element-after-decreasing-and-rearranging/

class MaximumElementAfterDecreasingAndRearranging
{
public:
	// 68 ms, faster than 94.78% : 51.5 MB, less than 96.27%
	int solution(vector<int> arr) {
		sort(begin(arr), end(arr));
		int n = size(arr);
		int ans = 1;
		arr[0] = 1;
		for (size_t i = 1; i < n; i++) {
			if (arr[i] - arr[i - 1] <= 1) continue;
			arr[i] = arr[i - 1] + 1;
		}

		return arr.back();
	}
	vector<int> output = {
		2,
		3,
		5
	};
	static constexpr int const& inputs = 1;
	vector<vector<int>> input1 = {
		{2,2,1,2,1},
		{100,1,1000},
		{1,2,3,4,5}
	};
};