#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended-ii/

class MaximumNumberOfEventsThatCanBeAttendedII
{
public:
	// 864 ms, faster than 5.05% : 188.5 MB, less than 5.05%
	int solution(vector<vector<int>> events, int k) {
		sort(begin(events), end(events), [](const auto& a, const auto b) {return a[0] < b[0]; });
		int n = size(events);

		function<int(int, int)> find = [&](int i, int l)->int {
			int r = n;
			while (l < r) {
				int mid = (l + r) / 2;
				if (events[mid][0] <= i) {
					l = mid + 1;
				}
				else {
					r = mid;
				}
			}
			return l;
		};

		vector mem(n, vector(k + 1, -1));
		function<int(int, int)> f = [&](int i, int j)-> int {
			if (j == 0 || i == n) {
				return 0;
			}
			if (mem[i][j] != -1) {
				return mem[i][j];
			}
			int nextIndex = find(events[i][1], i + 1);
			return mem[i][j] = max(f(i + 1, j),
				events[i][2] + f(nextIndex, j - 1));
		};

		return f(0, k);
	}
	vector<int> output = {
		7,
		10,
		9
	};
	static constexpr int const& inputs = 2;
	vector<vector<vector<int>>> input1 = {
		{{1,2,4},{3,4,3},{2,3,1}},
		{{1,2,4},{3,4,3},{2,3,10}},
		{{1,1,1},{2,2,2},{3,3,3},{4,4,4}}
	};
	vector<int> input2 = {
		2,
		2,
		3
	};
};