#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/missing-number/

class MissingNumber
{
public:
	// 3 ms, faster than 99.92% : 17.9 MB, less than 93.84%
	int solution(vector<int> nums) {
		int ans = (nums.size() * (nums.size() + 1)) / 2, sum = 0;
		for (auto x : nums)
			ans -= x;

		return ans;
	}

	// 15 ms, faster than 95.17% : 18.3 MB, less than 8.81%
	int solution2(vector<int> nums) {
		vector<int> vis(nums.size() + 1, 0);
		for (auto x : nums) {
			vis[x] = 1;
		}
		for (size_t i = 0; i < vis.size(); i++)
		{
			if (!vis[i]) return i;
		}
	}
	vector<int> output = {
		2,
		2,
		8
	};
	static constexpr int const& inputs = 1;
	vector<vector<int>> input1 = {
		{3,0,1},
		{0,1},
		{9,6,4,2,3,5,7,0,1}
	};
};