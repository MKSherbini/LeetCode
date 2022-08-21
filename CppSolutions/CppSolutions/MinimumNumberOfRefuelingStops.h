#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/minimum-number-of-refueling-stops/

class MinimumNumberOfRefuelingStops
{
public:
	// 26 ms, faster than 96.63% : 16.1 MB, less than 80.69%
	int solution(int target, int startFuel, vector<vector<int>>& stations) {
		int stops = 0;
		priority_queue<int> p;

		int i = 0;
		long fuel = startFuel;

		while (fuel < target) {
			Printer::print(fuel);
			while (i < size(stations))
				if (stations[i][0] <= fuel) p.push(stations[i++][1]);
				else break;
			Printer::print(p);
			if (p.empty()) break;
			fuel += p.top();
			p.pop();
			stops++;
		}

		return fuel >= target ? stops : -1;
	}
	vector<int> output = {
		0,
		-1,
		2,
		6
	};
	static constexpr int const& inputs = 3;
	vector<int> input1 = {
		1,
		100,
		100,
		1000000
	};
	vector<int> input2 = {
		1,
		1,
		10,
		70768
	};
	vector<vector<vector<int>>> input3 = {
		{},
		{{10,100}},
		{{10,60},{20,30},{30,30},{60,40}},
		{{12575,171159},{81909,101253},{163732,164401},{190025,65493},{442889,31147},{481202,166081},{586028,206379},{591952,52748},{595013,9163},{611883,217156}}
	};
};
