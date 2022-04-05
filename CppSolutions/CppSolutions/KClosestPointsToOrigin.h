#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/k-closest-points-to-origin/

class KClosestPointsToOrigin
{
public:
	// 200 ms, faster than 90.14% : 56.8 MB, less than 98.86%
	vector<vector<int>> solution(vector<vector<int>> points, int k) {
		sort(begin(points), end(points), [](auto& a, auto& b) {
			return (a[0] * a[0] + a[1] * a[1]) < (b[0] * b[0] + b[1] * b[1]);
			});
		return vector<vector<int>>(begin(points), begin(points) + k);
	}
	vector<vector<vector<int>>> output = {
		{{-2,2}},
		{{3,3},{-2,4}}
	};
	static constexpr int const& inputs = 2;
	vector<vector<vector<int>>> input1 = {
		{{1,3},{-2,2}},
		{{3,3},{5,-1},{-2,4}}
	};
	vector<int> input2 = {
		1,
		2
	};
};