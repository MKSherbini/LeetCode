#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/find-in-mountain-array/


// This is the MountainArray's API interface.
// You should not implement it, or speculate about its implementation
class MountainArray {
public:
	int get(int index);
	int length();
};

class FindInMountainArray
{
public:
	// 0 ms, faster than 100% : 7.2 MB, less than 43.62%
	int findInMountainArray(int target, MountainArray& mountainArr) {
		int l = 0, r = mountainArr.length() - 1;
		while (l < r) {
			int md = l + (r - l) / 2;
			if (mountainArr.get(md) > mountainArr.get(md + 1))
				r = md;
			else
				l = md + 1;
		}

		int tp = l;
		l = 0, r = tp;
		while (l <= r) {
			int m = l + (r - l) / 2;
			int cur = mountainArr.get(m);
			if (cur == target)
				return m;
			if (cur < target)
				l = m + 1;
			else
				r = m - 1;
		}

		l = tp, r = mountainArr.length() - 1;
		while (l <= r) {
			int m = l + (r - l) / 2;
			int cur = mountainArr.get(m);
			if (cur == target)
				return m;
			if (cur > target)
				l = m + 1;
			else
				r = m - 1;
		}

		return -1;
	}

};