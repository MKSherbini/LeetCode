#pragma once
#include "stdc++.h"


class MyCalendarIII
{
public:
	MyCalendarIII() {

	}
	// 117 ms, faster than 93.11% : 26.3 MB, less than 94.41%
	int book(int start, int end) {
		m[start]++;
		m[end]--;
		int mx = 0, cur = 0;
		for (auto p : m) {
			cur += p.second;
			mx = max(mx, cur);
		}
		return mx;
	}

private:
	map<int, int> m;

	// why the fk WA?
	// ["MyCalendarThree","book","book","book","book","book","book","book","book","book","book"]
	// [[], [24, 40], [43, 50], [27, 43], [5, 21], [30, 40], [14, 29], [3, 19], [3, 14], [25, 39], [6, 19]]
//	int book(int start, int end) {
//		int ans = 0;
//		for (auto p : v) {
//			if (start <= p.first && p.first < end ||
//				start < p.second && p.second <= end ||
//				start >= p.first && end <= p.second)
//				ans++;
//		}
//
//		v.emplace_back(start, end);
//		return mx = max(ans + 1, mx);
//	}
//private:
//	vector<pair<int, int>> v;
//	int mx = 1;
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */