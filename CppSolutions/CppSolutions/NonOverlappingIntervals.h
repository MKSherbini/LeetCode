#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/non-overlapping-intervals/

class NonOverlappingIntervals
{
public:
	// 450 ms, faster than 87.61% : 89.6 MB, less than 99.27%
	int solution(vector<vector<int>> intervals) {
		int n = size(intervals);
		sort(begin(intervals), end(intervals), [](auto const& a, auto const& b)
			{return a[0] != b[0] ? a[0] < b[0] : a[1] < b[1]; });

		int ans = 0;
		int mx = INT_MIN;
		for (auto& v : intervals) {
			int st = v[0], end = v[1];

			if (st >= mx) {
				mx = end;
			}
			else {
				ans++;
				mx = min(mx, end);
			}
		}

		return ans;
	}

	// 555 ms, faster than 18.73% : 140.3 MB, less than 5.14%
	int solution2(vector<vector<int>> intervals) {
		int n = size(intervals);

		sort(begin(intervals), end(intervals), [](auto const& a, auto const& b) {return a[0] < b[0]; });
		auto pred = [](auto& a, auto& b) {return a[0] < b; };
		vector mem(n, -1);
		function<int(int)> f = [&](int i) -> int {
			if (i >= n) return 0;
			if (mem[i] != -1) return mem[i];

			int j = lower_bound(begin(intervals), end(intervals), intervals[i][1], pred) - begin(intervals);
			return mem[i] = max(f(i + 1), 1 + f(j));
		};

		return n - f(0);
	}
	vector<int> output = {
		1,
		2,
		0
	};
	static constexpr int const& inputs = 1;
	vector<vector<vector<int>>> input1 = {
		{{1,2},{2,3},{3,4},{1,3}},
		{{1,2},{1,2},{1,2}},
		{{1,2},{2,3}}
	};
};