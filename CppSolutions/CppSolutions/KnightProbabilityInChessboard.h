#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/knight-probability-in-chessboard/

class KnightProbabilityInChessboard
{
public:
	// 176 ms, faster than 15.89% : 27.7 MB, less than 16.24%
	double solution(int n, int k, int row, int column) {
		int mx = k * 3 + 25;

		function<bool(int)> valid = [&](int x) -> bool {
			return x >= 0 && x < n;
		};
		vector mem(n, vector(n, vector<double>(k + 1, -1)));
		function<double(int, int, int)> f = [&](int i, int j, int k)-> double {
			if (!valid(i) || !valid(j)) 
				return 0;

			if (k <= 0)
				return i == row && j == column;
			k--;

			if (mem[i][j][k] != -1)
				return mem[i][j][k];

			double ret = 0;
			const vector<pair<int, int>> dir = { {2, -1}, {2, 1}, {-2, -1}, {-2, 1} };
			for (auto [dx, dy] : dir) {
				ret += f(i + dx, j + dy, k) / 8;
				ret += f(i + dy, j + dx, k) / 8;
			}

			return mem[i][j][k] = ret;
		};

		double ans = 0;
		for (size_t i = 0; i < n; i++) {
			for (size_t j = 0; j < n; j++) {
				ans += f(i, j, k);
			}
		}

		return ans;
	}
	vector<double> output = {
		0.06250,
		1.00000
	};
	static constexpr int const& inputs = 4;
	vector<int> input1 = {
		3,
		1
	};
	vector<int> input2 = {
		2,
		0
	};
	vector<int> input3 = {
		0,
		0
	};
	vector<int> input4 = {
		0,
		0
	};
};