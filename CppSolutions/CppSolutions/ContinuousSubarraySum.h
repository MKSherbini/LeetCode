#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/continuous-subarray-sum/

class ContinuousSubarraySum
{
public:
	// 221 ms, faster than 97.99% : 113.7 MB, less than 83.05%
	bool solution(vector<int> nums, int k) {
		unordered_map<int, int> m;

		int pre = 0;
		for (int i = 0; i < size(nums); i++)
		{
			pre += nums[i];
			pre %= k;

			if (!pre && i) return true;

			if (m.find(pre) != end(m)) {
				if (i - m[pre] >= 2) return true;
			}
			else {
				m[pre] = i;
			}
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
		{23,2,4,6,7},
		{23,2,6,4,7},
		{23,2,6,4,7}
	};
	vector<int> input2 = {
		6,
		6,
		13
	};
};