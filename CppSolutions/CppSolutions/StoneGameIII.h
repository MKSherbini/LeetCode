#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/stone-game-iii/

class StoneGameIII
{
public:
	// 819 ms, faster than 5.21% : 232.5 MB, less than 5.45%
	string solution(vector<int> piles) {
		int n = size(piles);
		vector mem(n, vector<int>(2, -1));

		function<int(int, bool)> f = [&](int i, bool aliceTurn)-> int {
			if (i >= n) return 0;
			if (mem[i][aliceTurn] != -1) return mem[i][aliceTurn];

			int ret = aliceTurn ? -1e7 : 1e7;
			int sum = 0;
			for (int x = 1; x <= 3; x++) {
				if (x + i - 1 >= n) break;
				sum += piles[x + i - 1];
				if (aliceTurn)
					ret = max(ret, f(x + i, 0) + sum);
				else
					ret = min(ret, f(x + i, 1));
			}

			return mem[i][aliceTurn] = ret;
		};

		int sum = 0;
		for (auto x : piles) sum += x;

		int alice = f(0, 1);
		if (sum - alice < alice)
			return "Alice";

		if (sum - alice > alice)
			return "Bob";

		return "Tie";
	}
	vector<string> output = {
		"Bob",
		"Alice",
		"Tie"
	};
	static constexpr int const& inputs = 1;
	vector<vector<int>> input1 = {
		{1,2,3,7},
		{1,2,3,-9},
		{1,2,3,6}
	};
};