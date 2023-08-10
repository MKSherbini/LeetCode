#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/search-in-rotated-sorted-array-ii/

class SearchInRotatedSortedArrayII
{
public:
	// 0 ms, faster than 100% : 13.9 MB, less than 88.75%
	bool solution(vector<int> nums, int target) {
		int l = 0, r = size(nums) - 1;

		while (l <= r) {
			int md = l + (r - l) / 2;

			if (nums[md] == target || nums[l] == target || nums[r] == target)
				return true;

			if (nums[l] == nums[r]) {
				l++, r--;
				continue;
			}
			if (((nums[md] < target && target <= nums[r]) && nums[md] <= nums[r]) ||
				(!(nums[l] <= target && target < nums[md]) && nums[l] <= nums[md]))
				l = md + 1;
			else
				r = md - 1;
		}

		return false;
	}
	// 0 ms, faster than 100% : 13.9 MB, less than 88.75%
	bool solution2(vector<int> nums, int target) {
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
		if (idx == sz || nums[idx] != target) return false;
		return true;
	}
	vector<int> output = {
		true,
		false
	};
	static constexpr int const& inputs = 2;
	vector<vector<int>> input1 = {
		{2,5,6,0,0,1,2},
		{2,5,6,0,0,1,2}
	};
	vector<int> input2 = {
		0,
		3
	};
};