#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/

class MinimumNumberOfArrowsToBurstBalloons
{
public:
	// 486 ms, faster than 81.76% : 89.7 MB, less than 93.84%
	int solution(vector<vector<int>> points) {
		int n = size(points);
		sort(begin(points), end(points));
		int i = 0, j = 1;
		int ans = 0;

		while (i < n) {
			ans++;
			while (j < n && points[j][0] <= points[i][1]) {
				if (points[j][1] < points[i][1]) i = j;
				j++;
			}
			i = j;
		}
		return ans;
	}
	vector<int> output = {
		2,
		4,
		2
	};
	static constexpr int const& inputs = 1;
	vector<vector<vector<int>>> input1 = {
		{{10,16},{2,8},{1,6},{7,12}},
		{{1,2},{3,4},{5,6},{7,8}},
		{{1,2},{2,3},{3,4},{4,5}}
	};
};