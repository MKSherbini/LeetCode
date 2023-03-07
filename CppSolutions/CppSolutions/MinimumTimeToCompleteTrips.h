#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/minimum-time-to-complete-trips/

class MinimumTimeToCompleteTrips
{
public:
	// 224 ms, faster than 98.87% : 94.4 MB, less than 76.55%
	int solution(vector<int> time, int totalTrips) {
		if (size(time) == 1) return 1LL * time[0] * totalTrips;
		long long left = 1, right = 1LL * *max_element(begin(time), end(time)) * totalTrips;

		while (left < right) {
			long long mid = (left + right) / 2;
			if (valid(time, mid, totalTrips)) {
				right = mid;
			}
			else {
				left = mid + 1;
			}
		}
		return left;
	}
	bool valid(vector<int>& time, long long givenTime, long long totalTrips) {
		for (int t : time) {
			totalTrips -= givenTime / t;
			if (totalTrips <= 0)
				return true;
		}
		return totalTrips <= 0;
	}

	// WA
	int solution2(vector<int> time, int totalTrips) {
		if (size(time) == 1) return time[0] * totalTrips;
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;

		for (auto t : time)
			q.push({ t,t });

		Printer::print(q);

		int ans = 0;
		while (totalTrips) {
			auto [time, inc] = q.top();
			Printer::print(q.top());
			q.pop();
			int timesTilNext = (q.top().first - time) / inc;
			if (timesTilNext == 0) {
				ans = time;
				totalTrips--;
				q.push({ time + inc, inc });
			}
			else {
				int mn = min(totalTrips, timesTilNext);
				totalTrips -= mn;
				ans = time + inc * (mn - 1);
				q.push({ time + inc * mn, inc });
			}
		}

		return ans;
	}
	vector<int> output = {
		3,
		2,
		25
	};
	static constexpr int const& inputs = 2;
	vector<vector<int>> input1 = {
		{1,2,3},
		{2},
		{5,10,10}
	};
	vector<int> input2 = {
		5,
		1,
		9
	};
};