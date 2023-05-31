#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/design-underground-system/

class DesignUndergroundSystem
{
public:
	// 154 ms, faster than 73.87% : 59.1 MB, less than 46.4%
	DesignUndergroundSystem() {

	}

	void checkIn(int id, string stationName, int t) {
		checkedIn[id] = { stationName, t };
	}

	void checkOut(int id, string stationName, int t) {
		auto& [st, t0] = checkedIn[id];
		string key = st + "_" + stationName;
		if (!m.count(key)) {
			m[key] = { t - t0, 1 };
			return;
		}
		auto& [avg, n] = m[key];
		m[key] = { ((avg * n++) + (t - t0)) / n,n };
	}

	double getAverageTime(string startStation, string endStation) {
		return m[startStation + "_" + endStation].first;
	}
private:
	unordered_map<string, pair<double, int>> m; // start_end to avg and n
	unordered_map<int, pair<string, int>> checkedIn; // checkedIn at station and t
};