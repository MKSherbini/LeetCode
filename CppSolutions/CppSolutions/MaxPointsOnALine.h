#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/max-points-on-a-line/

class MaxPointsOnALine
{
public:
	// 207 ms, faster than 6.06% : 7.3 MB, less than 89.72%
	int solution(vector<vector<int>> points) {
		int mx = 1;
		for (size_t i = 0; i < points.size() - 1; i++)
		{
			for (size_t j = i + 1; j < points.size(); j++)
			{
				int online = 2;
				float slope1 = (points[j][1] - points[i][1]) == 0 ? OO : ((1. * points[j][0] - points[i][0]) / (points[j][1] - points[i][1]));
				//Printer::print("slope1", slope1);
				//Printer::print(points[i], points[j]);
				for (size_t k = j + 1; k < points.size(); k++)
				{
					float slope2 = (points[k][1] - points[i][1]) == 0 ? OO : ((1. * points[k][0] - points[i][0]) / (points[k][1] - points[i][1]));
					//Printer::print("slope2", slope2);
					//Printer::print("diff", abs(slope1 - slope2));
					if (abs(slope1 - slope2) <= 0.00001) {
						online++;
						//Printer::print(points[k], online);
					}
				}
				mx = max(mx, online);
			}
		}
		return mx;
	}
	const int OO = (int)1e8;
	vector<int> output = {
		3,
		4,
		2,
		3,
		3
	};
	static constexpr int const& inputs = 1;
	vector<vector<vector<int>>> input1 = {
		{{1,1},{2,2},{3,3}},
		{{1,1},{3,2},{5,3},{4,1},{2,3},{1,4}},
		{{0,0},{1,-1},{1,1}},
		{{2,3},{3,3},{-5,3}},
		{{9,-25},{-4,1},{-1,5},{-7,7}}
	};
};