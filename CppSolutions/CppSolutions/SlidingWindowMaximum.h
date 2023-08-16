#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/sliding-window-maximum/

class SlidingWindowMaximum
{
public:
	// 576 ms, faster than 10.66% : 207.2 MB, less than 7.94%
	vector<int> solution(vector<int> nums, int k) {
		int n = size(nums);
		k--;
		vector<int> ans(n - k);
		set<pair<int, int>> s;
		for (size_t i = 0; i < n; i++) {
			s.insert({ nums[i], i });
			if (i >= k) {
				ans[i - k] = prev(end(s))->first;
				s.erase({ nums[i - k], i - k });
			}
		}

		return ans;
	}
	vector<vector<int>> output = {
		{3,3,5,5,6,7},
		{1}
	};
	static constexpr int const& inputs = 2;
	vector<vector<int>> input1 = {
		{1,3,-1,-3,5,3,6,7},
		{1}
	};
	vector<int> input2 = {
		3,
		1
	};
};