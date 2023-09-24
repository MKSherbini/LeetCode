#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/champagne-tower/

class ChampagneTower
{
public:
	// 7 ms, faster than 60.35% : 43.3 MB, less than 10.86%
	double solution(int poured, int query_row, int query_glass) {
		vector mem(101, vector(101, 0.0));

		mem[0][0] = poured;
		for (size_t row = 0; row <= query_row; row++) {
			for (size_t glass = 0; glass < 101; glass++) {
				if (mem[row][glass] > 1) {
					double left = mem[row][glass] - 1;
					mem[row][glass] = 1;
					mem[row + 1][glass + 1] += left / 2;
					mem[row + 1][glass] += left / 2;
				}
			}
		}

		return mem[query_row][query_glass];
	}
	vector<double> output = {
		0.00000,
		0.50000,
		1.00000
	};
	static constexpr int const& inputs = 3;
	vector<int> input1 = {
		1,
		2,
		100000009
	};
	vector<int> input2 = {
		1,
		1,
		33
	};
	vector<int> input3 = {
		1,
		1,
		17
	};
};