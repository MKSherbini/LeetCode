#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/range-sum-query-mutable/


class RangeSumQueryMutable
{
public:
	// 409 ms, faster than 99.43% : 150.5 MB, less than 91.71%
	RangeSumQueryMutable(vector<int> nums) : s(nums) {
		s.build();
	}


	void update(int index, int val) {
		s.modify(index, val);
	}

	int sumRange(int left, int right) {
		return s.query(left, right + 1);
	}

	SegmentTree s;
};

