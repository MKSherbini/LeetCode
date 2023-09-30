#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/132-pattern/

class Pattern132
{
public:
	// 55 ms, faster than 96.44% : 48.8 MB, less than 40.26%
	bool solution(vector<int> nums) {
		int n = size(nums);
		stack<int> s;
		int third = INT_MIN;

		for (int i = n - 1; i >= 0; i--) {
			if (nums[i] < third) return true;
			while (!s.empty() && s.top() < nums[i]) {
				third = s.top();
				s.pop();
			}
			s.push(nums[i]);
		}
		return false;
	}
	vector<int> output = {
		false,
		true,
		true
	};
	static constexpr int const& inputs = 1;
	vector<vector<int>> input1 = {
		{1,2,3,4},
		{3,1,4,2},
		{-1,3,2,0}
	};
};