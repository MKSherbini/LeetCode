#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/guess-number-higher-or-lower/

int guess(int num);

class GuessNumberHigherOrLower
{
public:
	// 0 ms, faster than 100% : 5.7 MB, less than 99.35%
	int solution(int n, int pick) {
		int mn = 1, mx = n, md;
		while (mn < mx) {
			md = (mn + (mx - mn) / 2);
			n = guess(md);
			if (n == -1) mx = md - 1;
			else if (n == 1) mn = md + 1;
			else break;
		}
		return md;
	}
public:
	vector<int> output = {
		6,
		1,
		1
	};
	static constexpr int const& inputs = 2;
	vector<int> input1 = {
		10,
		1,
		2
	};
	vector<int> input2 = {
		6,
		1,
		1
	};
};