#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/minimum-cost-to-cut-a-stick/

class MinimumCostToCutAStick
{
public:
	// 168 ms, faster than 5.04% : 10.2 MB, less than 60.46%
	int solution(int n, vector<int> cuts) {
		cuts.push_back(0);
		cuts.push_back(n);
		sort(begin(cuts), end(cuts));

		int m = size(cuts);
		vector mem(m, vector<int>(m, -1));
		function<int(int, int)> f = [&](int i, int j)-> int {
			if (mem[i][j] != -1) return mem[i][j];
			if (j == i + 1) return 0;

			int ret = 1e7;
			for (int k = i + 1; k < j; k++) {
				ret = min(ret, cuts[j] - cuts[i] + f(i, k) + f(k, j));
			}
			Printer::print(i, j, ret);

			return mem[i][j] = ret;
		};

		return f(0, m - 1);
	}

	// ??
	int solution2(int n, vector<int> cuts) {
		sort(begin(cuts), end(cuts));

		auto findIdx = [&](int p) -> int {
			return upper_bound(begin(cuts), end(cuts), p) - begin(cuts);
		};
		function<int(int, int)> f = [&](int st, int end)-> int {
			int i = findIdx(st), j = findIdx(end) - 1;
			while (j > 0 && cuts[j] >= end)
				j--;

			if (j < i) return 0;
			if (j == i) return end - st;

			int ret = 1e7;
			for (int k = i; k < j; k++) {
				ret = min(ret, end - st + f(st, cuts[k]) + f(cuts[k], end));
			}
			Printer::print(st, end, ret);

			return ret;
		};

		return f(0, n) - 1;
	}
	vector<int> output = {
		16,
		22
	};
	static constexpr int const& inputs = 2;
	vector<int> input1 = {
		7,
		9
	};
	vector<vector<int>> input2 = {
		{1,3,4,5},
		{5,6,1,4,2}
	};
};