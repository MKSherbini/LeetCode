#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/queue-reconstruction-by-height/

class QueueReconstructionByHeight
{
public:
	// 778 ms, faster than 5.02% : 12.6 MB, less than 36.75%
	vector<vector<int>> solution(vector<vector<int>> people) {
		sort(begin(people), end(people), [](auto& x, auto& y) { return x[0] != y[0] ? x[0] > y[0] : x[1] < y[1]; });

		int i = 0;

		while (i < size(people))
		{
			if (i != people[i][1])
			{
				auto temp = people[i];
				people.erase(begin(people) + i);
				people.insert(begin(people) + temp[1], temp);
			}
			i++;
		}

		return people;
	}
	vector<vector<vector<int>>> output = {
		{{5,0},{7,0},{5,2},{6,1},{4,4},{7,1}},
		{{4,0},{5,0},{2,2},{3,2},{1,4},{6,0}}
	};
	static constexpr int const& inputs = 1;
	vector<vector<vector<int>>> input1 = {
		{{7,0},{4,4},{7,1},{5,0},{6,1},{5,2}},
		{{6,0},{5,0},{4,0},{3,2},{2,2},{1,4}}
	};
};