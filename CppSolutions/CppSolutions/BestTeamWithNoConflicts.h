#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/best-team-with-no-conflicts/

class BestTeamWithNoConflicts
{
public:
	// 441 ms, faster than 27.92% : 231.6 MB, less than 5.52%
	int solution(vector<int> scores, vector<int> ages) {
		int n = size(scores);

		vector<pair<int, int>> p(n);
		vector<vector<int>> mem(n, vector(1001, -1));

		for (size_t i = 0; i < n; i++)
			p[i] = { scores[i], ages[i] };

		sort(begin(p), end(p));

		return f(p, mem, 0, 0);

	}
	int f(vector<pair<int, int>>& p, vector<vector<int>>& mem, int mn, int i) {
		if (i == size(p)) return 0;
		if (mem[i][mn] != -1) return mem[i][mn];

		int ret = f(p, mem, mn, i + 1);

		if (p[i].second >= mn)
			ret = max(ret, p[i].first + f(p, mem, p[i].second, i + 1));

		return mem[i][mn] = ret;
	}
	vector<int> output = {
		34,
		16,
		6
	};
	static constexpr int const& inputs = 2;
	vector<vector<int>> input1 = {
		{1,3,5,10,15},
		{4,5,6,5},
		{1,2,3,5}
	};
	vector<vector<int>> input2 = {
		{1,2,3,4,5},
		{2,1,2,1},
		{8,9,10,1}
	};
};