#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/snapshot-array/

class SnapshotArray
{
public:
	// 404 ms, faster than 54.17% : 155.9 MB, less than 30.75%
	SnapshotArray(int length) {
		v.resize(length);
		for (auto& x : v)
			x[0] = 0;
	}

	void set(int index, int val) {
		v[index][-snapId] = val;
	}

	int snap() {
		return snapId++;
	}

	int get(int index, int snap_id) {
		return v[index].lower_bound(-snap_id)->second;
	}
private:
	vector<map<int, int>> v;
	int snapId = 0;
};