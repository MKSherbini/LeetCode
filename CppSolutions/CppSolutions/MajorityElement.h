#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/majority-element/

class MajorityElement
{
public:
	// 0 ms, faster than 100% : 21.8 MB, less than 40.09%
	int solution(vector<int> nums) {
		int ans = 0, c = 0;
		for (auto x : nums) {
			if (ans == x) c++;
			else if (c > 0) c--;
			else ans = x;
		}

		return ans;
	}
	vector<int> output = {
		3,
		2
	};
	static constexpr int const& inputs = 1;
	vector<vector<int>> input1 = {
		{3,2,3},
		{2,2,1,1,1,2,2}
	};
};