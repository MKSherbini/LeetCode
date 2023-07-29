#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/soup-servings/

class SoupServings
{
public:
	// 137 ms, faster than 12.93% : 29.5 MB, less than 42.59%
	double solution(int n) {
		unordered_map<int, unordered_map<int, double>> mem;
		function<double(int, int)> f = [&](int a, int b) -> double {
			if (a <= 0 || b <= 0) {
				if (a <= 0 && b <= 0)
					return .5;
				if (a <= 0)
					return 1;
				return 0;
			}

			if (mem[a].count(b)) {
				return mem[a][b];
			}

			const vector<pair<int, int>> options = { {100, 0}, {75, 25}, {50, 50}, {25, 75} };
			double ret = 0;
			for (auto [da, db] : options)
				ret += f(a - da, b - db) * .25;

			return mem[a][b] = ret;
		};

		for (int i = 1; i <= n; i += 100) {
			if (f(i, i) > 1 - 1e-5) {
				return 1;
			}
		}

		return f(n, n);
	}
	vector<double> output = {
		0.62500,
		0.71875
	};
	static constexpr int const& inputs = 1;
	vector<int> input1 = {
		50,
		100
	};
};