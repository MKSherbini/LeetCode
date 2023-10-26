#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/binary-trees-with-factors/?envType=daily-question&envId=2023-10-26

class BinaryTreesWithFactors
{
public:
	// 9 ms, faster than 99.61% : 9.2 MB, less than 75.2%
	int solution(vector<int> arr) {
		sort(begin(arr), end(arr));
		unordered_map<int, int> mem;
		const int MOD = 1e9 + 7;
		int n = size(arr);

		for (auto x : arr)
			mem[x] = 1;

		for (int i : arr) {
			for (int j : arr) {
				if (j > sqrt(i)) break;

				if (i % j == 0 && mem.count(i / j)) {
					long long t = (long long)mem[j] * mem[i / j];
					if (i / j != j) t += t;
					t += mem[i];
					t %= MOD;
					mem[i] = t;
				}
			}
		}

		int ans = 0;
		for (auto x : arr) {
			ans += mem[x];
			ans %= MOD;
		}

		return ans;
	}

	// WA
	int solution2(vector<int> arr) {
		sort(begin(arr), end(arr));
		unordered_map<int, vector<pair<int, int>>> factors;
		int n = size(arr);

		for (int i = n - 1; i >= 0; i--) {
			int num = arr[i];
			for (int j = i - 1; j >= 0; j--) {
				int factor = arr[j];
				int c = 0;
				while (num % factor == 0) {
					c++;
					num /= factor;
				}
				if (c) {
					factors[arr[i]].push_back({ factor, c });
				}
			}
			if (num != 1) factors.erase(num);
		}

		Printer::print(factors);

		const int MOD = 1e9 + 7;
		unordered_map<int, int> mem;
		function<int(int)> f = [&](int i) -> int {
			if (empty(factors[i])) return 1;
			if (mem.count(i)) return mem[i];

			int ret = 1;
			for (auto& [factor, cnt] : factors[i]) {
				int j = f(factor);
				ret += j;
				ret %= MOD;
			}

			return mem[i] = ret;
		};

		int ans = 0;
		for (auto x : arr) {
			ans += f(x);
			ans %= MOD;
		}
		Printer::print(mem);
		return ans;
	}
	vector<int> output = {
		3,
		7
	};
	static constexpr int const& inputs = 1;
	vector<vector<int>> input1 = {
		{2,4},
		{2,4,5,10}
	};
};