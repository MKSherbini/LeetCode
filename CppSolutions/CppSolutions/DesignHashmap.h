#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/design-hashmap/

class DesignHashmap
{
public:
	// 104 ms, faster than 75.53% : 208.4 MB, less than 14.05%
	DesignHashmap() {
		v.assign(1e6 + 1, -1);
	}

	void put(int key, int value) {
		v[key] = value;
	}

	int get(int key) {
		return v[key];
	}

	void remove(int key) {
		v[key] = -1;
	}
private:
	vector<int> v;
};