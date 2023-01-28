#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/data-stream-as-disjoint-intervals/

class DataStreamAsDisjointIntervals
{
public:
	DataStreamAsDisjointIntervals() {

	}

	// 51 ms, faster than 96.86% : 33 MB, less than 88.63%
	void addNum(int value) {
		if (ranges.empty())
			ranges[value] = value;

		auto it = ranges.lower_bound(value);
		if (it == begin(ranges)) {
			if (it->first > value + 1)
				ranges[value] = value;
			else if (it->first == value + 1)
				ranges[value] = it->second, ranges.erase(it);
			return;
		}

		auto prv = prev(it);
		if (it->first == value + 1 && prv->second == value - 1)
			prv->second = it->second, ranges.erase(it);
		else if (prv->second == value - 1)
			prv->second = value;
		else if (it->first == value + 1)
			ranges[value] = it->second, ranges.erase(it);
		else if (it->first != value && prv->second < value)
			ranges[value] = value;
	}

	vector<vector<int>> getIntervals() {
		vector<vector<int>> ans;
		for (auto& r : ranges)
			ans.push_back({ r.first, r.second });
		return ans;
	}
private:
	map<int, int> ranges;
};

/**
 * Your DataStreamAsDisjointIntervals object will be instantiated and called as such:
 * DataStreamAsDisjointIntervals* obj = new DataStreamAsDisjointIntervals();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */