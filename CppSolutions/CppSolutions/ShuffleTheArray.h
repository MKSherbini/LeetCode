#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/shuffle-the-array/

class ShuffleTheArray
{
public:
	// 0 ms, faster than 100.00% : 9.5 MB, less than 99.97%
	vector<int> solution(vector<int>& nums, int n) {
		vector<int> ret(2 * n);
		for (int i = 0; i < n; i++)
			ret[i * 2] = nums[i], ret[i * 2 + 1] = nums[i + n];
		return ret;
	}

	vector<vector<int>> output = {
		{2,3,5,4,1,7},
		{1,4,2,3,3,2,4,1},
		{1,2,1,2}
	};
	static constexpr int const& inputs = 2;
	vector<vector<int>> input1 = {
		{2,5,1,3,4,7},
		{1,2,3,4,4,3,2,1},
		{1,1,2,2}
	};
	vector<int> input2 = {
		3,
		4,
		2
	};

};
// x => i*2
// y => (i-n)*2+1 
