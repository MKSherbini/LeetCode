#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/queries-on-number-of-points-inside-a-circle/

class QueriesOnNumberOfPointsInsideACircle
{
public:
	// 270 ms, faster than 20.98% : 16.1 MB, less than 91.25%
	vector<int> solution(vector<vector<int>>& points, vector<vector<int>>& queries) {
		vector<int> v(queries.size());
		for (int i = 0; i < queries.size(); i++)
		{
			//cout << "query.x " << queries[i][0] << ", query.y " << queries[i][1] << endl;
			for (int j = 0; j < points.size(); j++)
			{
				//cout << "point.x " << points[j][0] << ", point.y " << points[j][1] << ", R "
				//	<< queries[i][2] << ", pick "
				//	<< ((points[j][0] - queries[i][0]) * (points[j][0] - queries[i][0]) +
				//		(points[j][1] - queries[i][1]) * (points[j][1] - queries[i][1])
				//		<= queries[i][2] * queries[i][2]) << endl;
				if ((points[j][0] - queries[i][0]) * (points[j][0] - queries[i][0]) +
					(points[j][1] - queries[i][1]) * (points[j][1] - queries[i][1])
					<= queries[i][2] * queries[i][2])
					v[i]++;
			}
		}

		return v;
	}
	vector<vector<int>> output = {
		{3, 2, 2},
		{2, 3, 2, 4},
	};
	vector<vector<vector<int>>> input1 = {
		{{1, 3},{3, 3},{5, 3},{2, 2}},
		{{1, 1},{2, 2},{3, 3},{4, 4},{5, 5}},
	};
	vector<vector<vector<int>>> input2 = {
		{{2, 3, 1},{4, 3, 1},{1, 1, 2}},
		 {{1, 2, 2},{2, 2, 2},{4, 3, 2},{4, 3, 3}},
	};
};

