#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/increasing-triplet-subsequence/

class IncreasingTripletSubsequence
{
public:
	// 68 ms, faster than 96.72% : 61.5 MB, less than 87.63%
	bool solution(vector<int> nums) {
		int mn = nums[0];
		vector<int> v;

		for (size_t i = 1; i < size(nums); i++)
		{
			if (size(v) == 2 && v[1] < nums[i]) return 1;

			if (nums[i] < mn) {
				mn = nums[i];
			}
			else if (nums[i] > mn) {
				if (size(v) == 0) {
					v.push_back(mn);
					v.push_back(nums[i]);
				}
				else if (size(v) == 2 && nums[i] < v[1]) {
					v[0] = mn;
					v[1] = nums[i];
				}
			}

		}
		return 0;
	}
	vector<int> output = {
		true,
		false,
		true
	};
	static constexpr int const& inputs = 1;
	vector<vector<int>> input1 = {
		{1,2,3,4,5},
		{5,4,3,2,1},
		{2,1,5,0,4,6}
	};
};