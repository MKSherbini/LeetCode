#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/widest-vertical-area-between-two-points-containing-no-points/?envType=daily-question&envId=2023-12-21

class WidestVerticalAreaBetweenTwoPointsContainingNoPoints
{
public:
	// 229 ms, faster than 65.97% : 66.5 MB, less than 97.42%
	int solution(vector<vector<int>> points) {
		int n = size(points);
		sort(begin(points), end(points), [](const auto& a, const auto& b) {return a[0] < b[0]; });

		int ans = 0;
		for (size_t i = 1; i < n; i++) {
			ans = max(ans, points[i][0] - points[i - 1][0]);
		}

		return ans;
	}
	vector<int> output = {
		1,
		3
	};
	static constexpr int const& inputs = 1;
	vector<vector<vector<int>>> input1 = {
		{{8,7},{9,9},{7,4},{9,7}},
		{{3,1},{9,0},{1,0},{1,4},{5,3},{8,8}}
	};
};