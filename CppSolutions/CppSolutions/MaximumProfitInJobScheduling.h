#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/maximum-profit-in-job-scheduling/

class MaximumProfitInJobScheduling
{
public:
	// 176 ms, faster than 90.79% : 59.8 MB, less than 45.23%
	int solution(vector<int> startTime, vector<int> endTime, vector<int> profit) {
		mem.assign(size(startTime), -1);
		for (size_t i = 0; i < size(startTime); i++)
			jobs.push_back({ startTime[i], endTime[i], profit[i] });

		sort(begin(jobs), end(jobs));
		sort(begin(startTime), end(startTime));
		return f(0, startTime);
	}
	vector<vector<int>> jobs;
	vector<int> mem;
	int f(int i, vector<int>& startTime) {
		if (i >= size(jobs)) return 0;
		if (mem[i] != -1) return mem[i];
		int j = lower_bound(begin(startTime) + i, end(startTime), jobs[i][1]) - begin(startTime);
		Printer::print(i, j);

		return mem[i] = max(
			f(j, startTime) + jobs[i][2],
			f(i + 1, startTime)
		);
	}
	vector<int> output = {
		120,
		150,
		6
	};
	static constexpr int const& inputs = 3;
	vector<vector<int>> input1 = {
		{1,2,3,3},
		{1,2,3,4,6},
		{1,1,1}
	};
	vector<vector<int>> input2 = {
		{3,4,5,6},
		{3,5,10,6,9},
		{2,3,4}
	};
	vector<vector<int>> input3 = {
		{50,10,40,70},
		{20,20,100,70,60},
		{5,6,4}
	};
};