#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/

class CapacityToShipPackagesWithinDDays
{
public:
	// 36 ms, faster than 98.45% : 25.9 MB, less than 96.04%
	int solution(vector<int> weights, int days) {
		int total = 0, mx = 0;
		for (int w : weights) {
			total += w;
			mx = max(mx, w);
		}

		int l = mx, r = total;

		while (l < r) {
			int md = (l + r) / 2;
			if (f(weights, days, md)) {
				r = md;
			}
			else {
				l = md + 1;
			}
		}
		return l;
	}

	bool f(vector<int>& weights, int days, int x) {
		int cur = 0;
		for (int weight : weights) {
			cur += weight;
			if (cur > x) {
				--days;
				cur = weight;
			}
		}

		return days >= 1;
	}
	vector<int> output = {
		15,
		6,
		3
	};
	static constexpr int const& inputs = 2;
	vector<vector<int>> input1 = {
		{1,2,3,4,5,6,7,8,9,10},
		{3,2,2,4,1,4},
		{1,2,3,1,1}
	};
	vector<int> input2 = {
		5,
		3,
		4
	};
};