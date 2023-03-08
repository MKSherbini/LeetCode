#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/koko-eating-bananas/

class KokoEatingBananas
{
public:
	// 37 ms, faster than 96.29% : 18.8 MB, less than 98.14%
	int solution(vector<int> piles, int h) {
		int l = 1, r = *max_element(begin(piles), end(piles));

		while (l < r) {
			int md = l + (r - l) / 2;
			Printer::print(l, r);
			if (valid(piles, md, h)) {
				r = md;
			}
			else {
				l = md + 1;
			}
		}

		return l;
	}
	bool valid(vector<int>& piles, int md, int h) {
		for (auto x : piles) {
			h -= (x + md - 1) / md;
			if (h < 0)
				return false;
		}
		return h >= 0;
	}
	vector<int> output = {
		4,
		30,
		23
	};
	static constexpr int const& inputs = 2;
	vector<vector<int>> input1 = {
		{3,6,7,11},
		{30,11,23,4,20},
		{30,11,23,4,20}
	};
	vector<int> input2 = {
		8,
		5,
		6
	};
};