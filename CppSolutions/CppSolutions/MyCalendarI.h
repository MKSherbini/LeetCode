#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/my-calendar-i/

class MyCalendarI
{
public:
	MyCalendarI() {

	}
	// 124 ms, faster than 77.79% : 39.1 MB, less than 27.98%
	bool book2(int start, int end) {
		if (m.empty()) {
			m.insert({ start,end });
			return true;
		}
		auto i = m.lower_bound(start);
		if (i == m.end()) {
			if (prev(i)->second <= start) {
				m.insert({ start,end });
				return true;
			}
			else {
				return false;
			}
		}
		if ((i->first >= end && (i == m.begin() || prev(i)->second <= start))) { // insert before
			m.insert({ start,end });
			return true;
		}

		return false;
	}
	// 95 ms, faster than 95.09% : 38.6 MB, less than 68.9%
	// and keep connecting ...
	bool book(int start, int end) {
		if (m.empty()) {
			m.insert({ start,end });
			return true;
		}
		auto i = m.lower_bound(start);
		auto pre = prev(i);
		if (i == m.end()) {
			if (pre->second <= start) {
				if (pre->second == start)
					pre->second = end;
				else
					m.insert({ start,end });
				return true;
			}
			else {
				return false;
			}
		}
		if ((i->first >= end && (i == m.begin() || pre->second <= start))) { // insert before
			if (i != m.begin() && pre->second == start)
				pre->second = end;
			else if (i->first == end)
			{
				end = i->second;
				m.erase(i);
				m.insert({ start,end });
			}
			else
				m.insert({ start,end });
			return true;
		}

		return false;
	}

	map<int, int> m;
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */;

