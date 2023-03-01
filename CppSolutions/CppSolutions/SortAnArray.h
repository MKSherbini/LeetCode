#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/sort-an-array/

class SortAnArray
{
public:
	// 118 ms, faster than 95.9% : 61.1 MB, less than 68.62%
	vector<int> solution(vector<int> nums) {
		sort(begin(nums), end(nums));
		return nums;
	}
	vector<vector<int>> output = {
		{1,2,3,5},
		{0,0,1,1,2,5}
	};
	static constexpr int const& inputs = 1;
	vector<vector<int>> input1 = {
		{5,2,3,1},
		{5,1,1,2,0,0}
	};
};