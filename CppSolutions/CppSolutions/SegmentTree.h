#pragma once
#include "stdc++.h"

// https://codeforces.com/blog/entry/18051

class SegmentTree
{
	int n;
	vector<int> t;
public:
	SegmentTree(vector<int>& nums) : n(size(nums)), t(2 * n, 0) {
		copy(begin(nums), end(nums), begin(t) + n);
	}
	void build() {
		for (int i = n - 1; i > 0; --i) t[i] = t[i << 1] + t[i << 1 | 1];
		//Printer::print(t);
	}
	void modify(int p, int value) {
		for (t[p += n] = value; p > 1; p >>= 1) t[p >> 1] = t[p] + t[p ^ 1];
		//Printer::print(t);
	}
	int query(int l, int r) {
		int res = 0;
		for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
			if (l & 1) res += t[l++];
			if (r & 1) res += t[--r];
		}
		//Printer::print(t);
		return res;
	}
};
