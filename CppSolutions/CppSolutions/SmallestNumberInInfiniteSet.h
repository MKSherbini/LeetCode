#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/smallest-number-in-infinite-set/

class SmallestNumberInInfiniteSet
{
public:
	// 68 ms, faster than 95.61% : 35.4 MB, less than 92.24%
	SmallestNumberInInfiniteSet() {

	}

	int popSmallest() {
		if (s.empty())
			return i++;

		int ret = *s.begin();
		s.erase(s.begin());
		return ret;
	}

	void addBack(int num) {
		if (num < i)
			s.insert(num);
	}
private:
	set<int> s;
	int i = 1;
};