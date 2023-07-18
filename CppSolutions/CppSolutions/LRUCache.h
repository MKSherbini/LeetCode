#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/lru-cache/

class LRUCache
{
public:
	// 529 ms, faster than 35.64% : 177.2 MB, less than 38.78%
	LRUCache(int capacity) :n{ capacity } {

	}

	int get(int key) {
		if (!m.count(key)) return -1;
		auto& [timeStamp, val] = m[key];
		s.erase({ timeStamp, key });
		s.insert({ t, key });
		timeStamp = t++;
		return val;
	}

	void put(int key, int value) {
		if (n == size(m) && !m.count(key)) {
			int key = s.begin()->second;
			s.erase(begin(s));
			m.erase(key);
		}

		if (m.count(key)) {
			auto& [timeStamp, val] = m[key];
			auto it = s.find({ timeStamp, key });
			s.erase(it);
		}
		s.insert({ t, key });
		m[key] = { t++, value };
	}
private:
	int n;
	int t = 0;
	unordered_map<int, pair<int, int>> m;
	set<pair<int, int>> s;
};