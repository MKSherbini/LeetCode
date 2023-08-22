#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/number-of-recent-calls/?envType=study-plan-v2&envId=leetcode-75

class NumberOfRecentCalls
{
public:
	// 140 ms, faster than 64.37% : 62.6 MB, less than 5.73%
	NumberOfRecentCalls() {

	}

	int ping(int t) {
		l.push_front(t);
		while (l.back() < t - 3000) {
			l.pop_back();
		}
		return size(l);
	}
private:
	list<int> l;
};