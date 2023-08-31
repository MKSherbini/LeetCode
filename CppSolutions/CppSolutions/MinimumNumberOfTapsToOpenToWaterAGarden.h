#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/minimum-number-of-taps-to-open-to-water-a-garden/

class MinimumNumberOfTapsToOpenToWaterAGarden
{
public:
	// 4 ms, faster than 98.74% : 14.6 MB, less than 72.16%
	int solution(int n, vector<int> ranges) {
		vector maxHop(n + 1, 0);
		for (int i = 0; i < n + 1; i++) {
			int st = max(0, i - ranges[i]), end = min(n, i + ranges[i]);
			maxHop[st] = max(maxHop[st], end);
		}

		int ans = 1;
		int limit = maxHop[0];
		int nextHop = 0;
		for (int i = 0; i < n + 1; i++) {
			if (i > nextHop) {
				return -1;
			}

			if (i > limit) {
				ans++;
				limit = nextHop;
			}

			nextHop = max(nextHop, maxHop[i]);
		}

		return ans;
	}

	int solution2(int n, vector<int> ranges) {
		n++;
		const int OO = 1e8;
		vector mem(n, vector(101, -1));
		function<int(int, int)> f = [&](int i, int l) -> int {
			if (i >= n) return l == 0 ? 0 : OO;
			if (l > 100) return OO;
			if (mem[i][l] != -1) return mem[i][l];

			int ret = f(i + 1, l + 1);
			if (ranges[i] >= l)
				ret = min(ret, 1 + f(i + ranges[i] + 1, 0));

			return mem[i][l] = ret;
		};
		f(0, 0);
		Printer::print(mem);

		return f(0, 0) == OO ? -1 : f(0, 0);
	}
	vector<int> output = {
		1,
		-1
	};
	static constexpr int const& inputs = 2;
	vector<int> input1 = {
		5,
		3
	};
	vector<vector<int>> input2 = {
		{3,4,1,1,0,0},
		{0,0,0,0}
	};
};