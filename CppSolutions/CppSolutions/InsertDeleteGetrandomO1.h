#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/insert-delete-getrandom-o1/

class InsertDeleteGetrandomO1
{
public:
	// 218 ms, faster than 99.04% : 96.9 MB, less than 82.25%
	InsertDeleteGetrandomO1() {

	}

	bool insert(int val) {
		if (m.contains(val)) return false;

		m[val] = size(v);
		v.push_back(val);
		Printer::print("m: ", m);
		Printer::print("v: ", v);
		return true;
	}

	bool remove(int val) {
		if (!m.contains(val)) return false;

		m[v.back()] = m[val];
		swap(v[m[val]], v.back());
		v.pop_back();
		m.erase(val);
		Printer::print("m: ", m);
		Printer::print("v: ", v);
		return true;
	}

	int getRandom() {
		return v[rand() % size(v)];
	}
private:
	unordered_map<int, int> m;
	vector<int> v;
};