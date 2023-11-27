#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/knight-dialer/

class KnightDialer
{
public:
	// 160 ms, faster than 46.05% : 25 MB, less than 57.31%
	int solution(int n) {
		const int MOD = 1e9 + 7;
		vector mem(10, vector(n, -1));
		vector<vector<int>> nxt = {
			{4, 6},
			{6, 8},
			{7, 9},
			{4, 8},
			{3, 9, 0},
			{},
			{1, 7, 0},
			{2, 6},
			{1, 3},
			{2, 4}
		};
		function<int(int, int)> f = [&](int i, int moves) -> int {
			if (moves == 0) return 1;
			if (mem[i][moves] != -1) return mem[i][moves];
			int ret = 0;
			for (auto j : nxt[i]) {
				ret += f(j, moves - 1);
				ret %= MOD;
			}

			return mem[i][moves] = ret;
		};

		int ans = 0;
		for (size_t i = 0; i < 10; i++) {
			ans += f(i, n - 1);
			ans %= MOD;
		}

		return ans;
	}

	// ?? tle on ide, acc on leetcode????
	int solution2(int n) {
		const int MOD = 1e9 + 7;
		vector mem(4, vector(3, vector(n + 1, -1)));
		vector<vector<int>> nums = {
			{1, 2, 3},
			{4, 5, 6},
			{7, 8, 9},
			{-1, 0, -1}
		};
		function<bool(int, int)> valid = [&](int x, int n) -> bool {
			return x >= 0 && x < n;
		};
		function<int(int, int, int)> f = [&](int i, int j, int moves) -> int {
			if (!valid(i, 4) ||
				!valid(j, 3) ||
				nums[i][j] == -1 ||
				moves <= 0) return 0;
			if (mem[i][j][moves] != -1) return mem[i][j][moves];
			Printer::print(i, j, moves);
			moves--;
			int ret = 1;
			const vector<pair<int, int>> dir = { {2, 1}, {1, 2}, {-1, 2}, {-2, 1},{-2, -1}, {-1, -2}, {1, -2}, {2, -1} };
			for (auto [dx, dy] : dir) {
				ret += f(i + dx, j + dy, moves);
			}

			return mem[i][j][moves + 1] = ret;
		};

		int ans = 0;
		for (size_t i = 0; i < 4; i++) {
			for (size_t j = 0; j < 3; j++) {
				if (nums[i][j] == -1) continue;
				ans += f(i, j, n);
				ans %= MOD;
			}
		}

		return ans;
	}
	vector<int> output = {
		10,
		20,
		136006598
	};
	static constexpr int const& inputs = 1;
	vector<int> input1 = {
		1,
		2,
		3131
	};
};