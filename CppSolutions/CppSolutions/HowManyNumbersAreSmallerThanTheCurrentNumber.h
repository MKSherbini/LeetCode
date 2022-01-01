#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/queries-on-number-of-points-inside-a-circle/

class HowManyNumbersAreSmallerThanTheCurrentNumber
{
public:
	// 0 ms, faster than 100.00% : 10.2 MB, less than 66.74%
	vector<int> solution(vector<int>& nums) {
		vector<pair<int, int>> sorted(nums.size());
		vector<int> ans(nums.size());
		for (int i = 0; i < nums.size(); i++)
			sorted[i] = { nums[i], i };
		sort(begin(sorted), end(sorted));

		for (int i = 0; i < nums.size(); i++)
			ans[i] = lower_bound(begin(sorted), end(sorted), pair<int, int>{ nums[i], -1 }) - begin(sorted);

		return ans;
	}
	vector<vector<int>> output = {
		{4,0,1,1,3},
		{2,1,0,3},
		{0,0,0,0},
	};
	vector<vector<int>> input1 = {
		{8,1,2,2,3},
		{6,5,4,8},
		{7,7,7,7},
	};
};

