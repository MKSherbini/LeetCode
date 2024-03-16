#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/contiguous-array/

class ContiguousArray
{
public:
	// 78 ms, faster than 82.76% : 87.7 MB, less than 74.78%
	int solution(vector<int> nums) {
		int n = size(nums);
		unordered_map<int, int> m;
		int slope = 0;
		int ans = 0;
		m[0] = -1;
		for (int i = 0; i < n; i++) {
			slope += nums[i] == 1 ? 1 : -1;
			if (m.count(slope)) ans = max(ans, i - m[slope]);
			else m[slope] = i;
		}

		return ans;
	}
	vector<int> output = {
		2,
		2
	};
	static constexpr int const& inputs = 1;
	vector<vector<int>> input1 = {
		{0,1},
		{0,1,0}
	};
};