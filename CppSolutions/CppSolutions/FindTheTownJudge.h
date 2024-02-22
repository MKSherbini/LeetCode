#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/find-the-town-judge/

class FindTheTownJudge
{
public:
	// 123 ms, faster than 82.05% : 65.1 MB, less than 53.48%
	int solution(int n, vector<vector<int>> trust) {
		if (n == 1) return 1;
		vector<int> v(n);
		int judge = -1;
		set<int> trusting;
		for (auto& x : trust) {
			v[x[1] - 1]++;
			trusting.insert(x[0]);
			if (v[x[1] - 1] == n - 1) judge = x[1];
		}

		return trusting.count(judge) ? -1 : judge;
	}

	// 190 ms, faster than 78.68% : 61.6 MB, less than 65.98%
	int solution2(int n, vector<vector<int>> trust) {
		if (n == 1) return 1;
		map<int, int> f;
		int judge = -1;
		for (auto& x : trust) {
			f[x[1]]++;
			if (f[x[1]] == n - 1) judge = x[1];
		}
		for (auto& x : trust)
			if (x[0] == judge) return -1;

		return judge;
	}
	vector<int> output = {
		2,
		3,
		-1
	};
	static constexpr int const& inputs = 2;
	vector<int> input1 = {
		2,
		3,
		3
	};
	vector<vector<vector<int>>> input2 = {
		{{1,2}},
		{{1,3},{2,3}},
		{{1,3},{2,3},{3,1}}
	};
};