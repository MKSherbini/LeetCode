#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/minimum-time-visiting-all-points/

class MinimumTimeVisitingAllPoints
{
public:
	// 0 ms, faster than 100% : 10.4 MB, less than 95.02%
	int solution(vector<vector<int>> points) {
		int n = size(points);
		int ans = 0;

		for (size_t i = 1; i < n; i++) {
			ans += max(abs(points[i][0] - points[i - 1][0]), abs(points[i][1] - points[i - 1][1]));
		}

		return ans;
	}
	vector<int> output = {
		7,
		5
	};
	static constexpr int const& inputs = 1;
	vector<vector<vector<int>>> input1 = {
		{{1,1},{3,4},{-1,0}},
		{{3,2},{-2,2}}
	};
};