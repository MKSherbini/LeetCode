#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/maximum-erasure-value/

class MaximumErasureValue
{
public:
	// 665 ms, faster than 25.28% : 156.6 MB, less than 8.75%
	int solution(vector<int> nums) {
		set<int> s;
		size_t mx = 0;
		for (size_t i = 0, st = 0, sum = 0; i < nums.size(); i++)
		{
			while (st < i && s.count(nums[i]))
				sum -= nums[st], s.erase(nums[st++]);
			s.insert(nums[i]);
			sum += nums[i];
			mx = max(mx, sum);
		}
		return mx;
	}

	vector<int> output = {
		17,
		8
	};
	static constexpr int const& inputs = 1;
	vector<vector<int>> input1 = {
		{4,2,4,5,6},
		{5,2,1,2,5,2,1,2,5}
	};
};