#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/design-hashset/

class DesignHashset
{
public:
	// 67 ms, faster than 99.48% : 43.4 MB, less than 51.62%
	DesignHashset() {
		v.assign(1000001, 0);
	}

	void add(int key) {
		v[key] = 1;
	}

	void remove(int key) {
		v[key] = 0;
	}

	bool contains(int key) {
		return v[key] == 1;
	}
private:
	vector<bool> v;
};