#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/bulb-switcher/

class BulbSwitcher
{
public:
	// 0 ms, faster than 100% : 5.8 MB, less than 94.29%
	int solution(int n) {
		//Printer::print(sqrt(1000000000));
		int l = 0, r = 31622;
		while (l < r) {
			int md = l + (r - l) / 2;
			int sqr = md * md;
			if (sqr <= n) l = md + 1;
			else r = md;
		}

		return l - 1;
	}
	inline int sumOdds(int x) {
		//x = (x + 1) / 2;
		return x * x;
	}
	vector<int> output = {
		1,
		0,
		1
	};
	static constexpr int const& inputs = 1;
	vector<int> input1 = {
		3,
		0,
		1
	};
};
//
//1 0
//3 1
//5 2
//7 3 ?
//
//0
//1
//1
//1
//2
//2
//2
//2
//2
//3
//3
//3
//3
//3
//3
//3
//4
//4
//4

