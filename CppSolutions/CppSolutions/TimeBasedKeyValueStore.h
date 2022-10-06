#pragma once
#include "stdc++.h"

class TimeBasedKeyValueStore
{
public:
	TimeBasedKeyValueStore() {

	}
	// 335 ms, faster than 95.29% : 130.4 MB, less than 39.89%
	void set(string key, string value, int timestamp) {
		m[key][-timestamp] = value;
	}

	string get(string key, int timestamp) {
		auto it = m[key].lower_bound(-timestamp);
		if (it == end(m[key])) return "";

		return it->second;
	}

	// 349 ms, faster than 92.3% : 130.4 MB, less than 39.28%
	void set2(string key, string value, int timestamp) {
		m[key][timestamp] = value;
	}

	string get2(string key, int timestamp) {
		if (m[key].empty()) return "";
		auto it = m[key].lower_bound(timestamp);
		if (it == end(m[key]) || it->first > timestamp) --it;
		if (it == end(m[key]) || it == begin(m[key]) && it->first > timestamp) return "";

		return it->second;
	}
private:
	unordered_map< string, map<int, string>> m;
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
