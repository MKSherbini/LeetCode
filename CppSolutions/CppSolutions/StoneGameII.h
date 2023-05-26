#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/stone-game-ii/

class StoneGameII
{
public:
	// 127 ms, faster than 24.73% : 27.1 MB, less than 16.75%
	int solution(vector<int> piles) {
		int n = size(piles);
		if (n == 1) return piles[0]; // why???????????

		vector mem(n, vector(n, vector<int>(2, -1)));

		function<int(int, int, bool)> f = [&](int i, int m, bool aliceTurn)-> int {
			if (i >= n) return 0;
			if (mem[i][m][aliceTurn] != -1) return mem[i][m][aliceTurn];

			int ret = aliceTurn ? -1e7 : 1e7;
			int sum = 0;
			for (int x = 1; x <= 2 * m; x++) {
				if (x + i - 1 >= n) break;
				sum += piles[x + i - 1];
				if (aliceTurn)
					ret = max(ret, f(x + i, max(x, m), 0) + sum);
				else
					ret = min(ret, f(x + i, max(x, m), 1));
			}

			return mem[i][m][aliceTurn] = ret;
		};

		return f(0, 1, 1);
	}
	vector<int> output = {
		10,
		104
	};
	static constexpr int const& inputs = 1;
	vector<vector<int>> input1 = {
		{2,7,9,4,4},
		{1,2,3,4,5,100}
	};
};