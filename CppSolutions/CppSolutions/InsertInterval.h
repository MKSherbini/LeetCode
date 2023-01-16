#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/insert-interval/

class InsertInterval
{
public:
	// 7 ms, faster than 99.8% : 16.9 MB, less than 92.65%
	vector<vector<int>> solution(vector<vector<int>> intervals, vector<int> newInterval) {
		int n = size(intervals);
		int i, x = -1, y = -1;

		for (i = 0; i < n; i++) {
			if (newInterval[1] < intervals[i][0]) break;
			if (newInterval[0] >= intervals[i][0] && newInterval[0] <= intervals[i][1] ||
				newInterval[1] >= intervals[i][0] && newInterval[1] <= intervals[i][1] ||
				intervals[i][0] >= newInterval[0] && intervals[i][0] <= newInterval[1] ||
				intervals[i][1] >= newInterval[0] && intervals[i][1] <= newInterval[1]
				)
				if (x == -1)
					x = i;
				else
					y = i;
		}
		if (x == -1)
			intervals.insert(begin(intervals) + i, newInterval);
		else if (y == -1)
			intervals[x][0] = min(intervals[x][0], newInterval[0]),
			intervals[x][1] = max(intervals[x][1], newInterval[1]);
		else
			newInterval[1] = max(newInterval[1], intervals[y][1]),
			intervals.erase(begin(intervals) + x + 1, begin(intervals) + y + 1),
			intervals[x][0] = min(intervals[x][0], newInterval[0]),
			intervals[x][1] = max(intervals[x][1], newInterval[1]);

		return intervals;
	}
	vector<vector<vector<int>>> output = {
		{{1,5},{6,9}},
		{{1,2},{3,10},{12,16}}
	};
	static constexpr int const& inputs = 2;
	vector<vector<vector<int>>> input1 = {
		{{1,3},{6,9}},
		{{1,2},{3,5},{6,7},{8,10},{12,16}}
	};
	vector<vector<int>> input2 = {
		{2,5},
		{4,8}
	};
};