#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/find-the-longest-valid-obstacle-course-at-each-position/

class FindTheLongestValidObstacleCourseAtEachPosition
{
public:
	// 302 ms, faster than 73.29% : 117.6 MB, less than 80.14%
	vector<int> solution(vector<int> obstacles) {
		int n = size(obstacles);

		vector<int> ans(n, 1), mem;

		for (size_t i = 0; i < n; i++) {
			auto it = upper_bound(begin(mem), end(mem), obstacles[i]) - begin(mem);
			if (it != size(mem)) {
				mem[it] = obstacles[i];
			}
			else {
				mem.push_back(obstacles[i]);
			}
			ans[i] = it + 1;
			Printer::print(mem);
		}

		return ans;
	}
	vector<vector<int>> output = {
		{1,2,3,3},
		{1,2,1},
		{1,1,2,3,2,2}
	};
	static constexpr int const& inputs = 1;
	vector<vector<int>> input1 = {
		{1,2,3,2},
		{2,2,1},
		{3,1,5,6,4,2}
	};
};