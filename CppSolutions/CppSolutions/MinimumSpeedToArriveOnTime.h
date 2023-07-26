#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/minimum-speed-to-arrive-on-time/

class MinimumSpeedToArriveOnTime
{
public:
	// 395 ms, faster than 31.36% : 101.3 MB, less than 94.22%
	int solution(vector<int> dist, double hour) {
		int n = size(dist);
		int l = 1, r = 1e7 + 1;

		auto f = [&](int s) {
			double hours = 0;
			for (int i = 0; i < n; i++) {
				if (i == n - 1)
					hours += 1.0 * dist[i] / s;
				else
					hours += (dist[i] + s - 1) / s;
			}

			return hours;
		};

		int lastAns = -1;
		while (l < r) {
			int md = l + (r - l) / 2;
			double mdHour = f(md);

			Printer::print(md, mdHour);
			if (mdHour <= hour) {
				lastAns = md;
				r = md;
			}
			else {
				l = md + 1;
			}
		}

		return lastAns;
	}
	vector<int> output = {
		1,
		3,
		-1,
		10000000
	};
	static constexpr int const& inputs = 2;
	vector<vector<int>> input1 = {
		{1,3,2},
		{1,3,2},
		{1,3,2},
		{1,1,100000}
	};
	vector<double> input2 = {
		6,
		2.7,
		1.9,
		2.01
	};
};