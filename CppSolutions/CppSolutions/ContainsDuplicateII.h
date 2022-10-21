#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/contains-duplicate-ii/

class ContainsDuplicateII
{
public:
	// 175 ms, faster than 97.99% : 76.9 MB, less than 80.91%
	bool solution(vector<int> nums, int k) {
		unordered_map<int, bool> m;

		for (size_t i = 0; i < size(nums); i++)
		{
			if (i >= k + 1) m[nums[i - k - 1]] = false;

			if (m[nums[i]]) return true;
			m[nums[i]] = true;
		}

		return false;
	}
	vector<int> output = {
		true,
		true,
		false
	};
	static constexpr int const& inputs = 2;
	vector<vector<int>> input1 = {
		{1,2,3,1},
		{1,0,1,1},
		{1,2,3,1,2,3}
	};
	vector<int> input2 = {
		3,
		1,
		2
	};
};