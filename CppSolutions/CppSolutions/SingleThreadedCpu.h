#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/single-threaded-cpu/

class SingleThreadedCpu
{
public:
	// 707 ms, faster than 79.36% : 126.8 MB, less than 79.36%
	vector<int> solution(vector<vector<int>> tasks) {
		auto prio = [&](const int i, const int j) {return tasks[i][1] != tasks[j][1] ?
			tasks[i][1] > tasks[j][1] : tasks[i][2] > tasks[j][2]; };
		priority_queue<int, vector<int>, decltype(prio)> pq(prio);
		int n = size(tasks);
		for (size_t i = 0; i < n; i++)
			tasks[i].push_back(i);

		sort(begin(tasks), end(tasks), [](const auto& x, const auto& y) {return x[0] < y[0]; });

		Printer::print(tasks);
		pq.push(0);
		int i = 1;
		while (i < n && tasks[i][0] == tasks[0][0])
			pq.push(i), ++i;

		vector<int> ans;
		long long time = tasks[0][0];
		while (!pq.empty()) {
			auto& top = tasks[pq.top()];
			ans.push_back(top.back());
			time += top[1];
			pq.pop();
			if (i < n) {
				Printer::print(i);
				if (tasks[i][0] > time && pq.empty()) time = tasks[i][0];
				while (i < n && tasks[i][0] <= time)
					pq.push(i), ++i;
				Printer::print(i, time);
				Printer::print(pq);
			}
		}

		return ans;
	}
	vector<vector<int>> output = {
		{0,2,3,1},
		{4,3,2,0,1},
		{15,14,13,1,6,3,5,12,8,11,9,4,10,7,0,2 }
	};
	static constexpr int const& inputs = 1;
	vector<vector<vector<int>>> input1 = {
		{{1,2},{2,4},{3,2},{4,1}},
		{{7,10},{7,12},{7,5},{7,4},{7,2}},
		{{35,36},{11,7},{15,47},{34,2},{47,19},{16,14},{19,8},{7,34},{38,15},{16,18},{27,22},{7,15},{43,2},{10,5},{5,4},{3,11}}
	};
};