#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/find-the-highest-altitude/

class FindTheHighestAltitude
{
public:
	// 0 ms, faster than 100% : 7.9 MB, less than 93.43%
	int solution(vector<int> gain) {
		int ans = 0, cur = 0;
		for (auto x : gain) {
			cur += x;
			ans = max(ans, cur);
		}
		
		return ans;
	}
	vector<int> output = {
		1,
		0
	};
	static constexpr int const& inputs = 1;
	vector<vector<int>> input1 = {
		{-5,1,5,0,-7},
		{-4,-3,-2,-1,4,3,2}
	};
};