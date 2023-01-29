#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/lfu-cache/

class Item {
public:
	int freq, time, key, val;
	Item() {}
	Item(int freq, int time, int key, int val) :
		freq(freq), time(time), key(key), val(val) {}

	bool operator > (const Item& o) const {
		return freq != o.freq ? freq > o.freq : time > o.time;
	}
	bool operator < (const Item& o) const {
		return freq != o.freq ? freq < o.freq : time < o.time;
	}
};
class LFUCache {
public:
	LFUCache(int capacity) {
		n = capacity;
	}

	// 505 ms, faster than 90.61% : 182.4 MB, less than 49.55%
	int get(int key) {
		if (!m.count(key)) return -1;
		auto it = s.lower_bound({ m[key].first, m[key].second, key, 0 });
		auto item = *it;
		s.erase(it);
		item.time = t++;
		item.freq++;
		s.insert(item);
		m[key] = { item.freq, item.time };
		return item.val;
	}

	void put(int key, int value) {
		if (n == 0) return;

		if (m.count(key)) {
			auto it = s.lower_bound({ m[key].first, m[key].second, key, 0 });
			auto item = *it;
			s.erase(it);
			item.time = t++;
			item.freq++;
			item.val = value;
			s.insert(item);
			m[key] = { item.freq, item.time };
			return;
		}

		if (size(s) == n) {
			m.erase(s.begin()->key);
			s.erase(s.begin());
		}

		auto item = Item{ 1, t++, key, value };
		s.insert(item);
		m[key] = { item.freq, item.time };
	}
private:
	int n;
	int i = 0;
	int t = 0;
	unordered_map<int, pair<int, int>> m;
	set<Item> s;
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */