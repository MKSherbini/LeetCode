#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/search-in-rotated-sorted-array/

class SearchInRotatedSortedArray
{
public:
	// 4 ms, faster than 74.1% : 11 MB, less than 95.68%
	int solution(vector<int> nums, int target) {
		int k = 0, sz = nums.size();
		for (int i = 1; i < sz; i++)
			if (nums[i] < nums[i - 1]) {
				k = i;
				break;
			}

		k = sz - k;
		int steps = 0;
		int next = 0;
		int prev = nums[0];
		int cycleStart = 0;
		while (steps++ < sz)
		{
			next = (next + k) % sz;
			int temp = nums[next];
			nums[next] = prev;
			prev = temp;
			if (next <= cycleStart && next < sz - 1) {
				++cycleStart;
				next = cycleStart;
				prev = nums[next];
			}
		}
		Printer::print(nums);
		int idx = lower_bound(begin(nums), end(nums), target) - begin(nums);
		if (idx == sz || nums[idx] != target) return -1;
		return (idx - k + sz) % sz;
	}
	vector<int> output = {
		4,
		-1,
		-1
	};
	static constexpr int const& inputs = 2;
	vector<vector<int>> input1 = {
		{4,5,6,7,0,1,2},
		{4,5,6,7,0,1,2},
		{1}
	};
	vector<int> input2 = {
		0,
		3,
		0
	};
};