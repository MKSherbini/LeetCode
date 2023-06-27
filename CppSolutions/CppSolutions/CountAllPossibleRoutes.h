#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/count-all-possible-routes/

class CountAllPossibleRoutes
{
public:
	// 350 ms, faster than 20.25% : 12 MB, less than 24.47%
	int solution(vector<int> locations, int start, int finish, int fuel) {
		int n = size(locations);
		const int MOD = 1e9 + 7;
		vector mem(n, vector(fuel + 1, -1));
		function<int(int, int)> f = [&](int i, int curF)->int {
			if (curF < 0) return 0;
			if (mem[i][curF] != -1) return mem[i][curF];

			int ret = i == finish;
			for (size_t j = 0; j < n; j++) {
				if (i == j) continue;
				ret += f(j, curF - abs(locations[i] - locations[j]));
				ret %= MOD;
			}

			return mem[i][curF] = ret;
		};

		return f(start, fuel);
	}
	vector<int> output = {
		4,
		5,
		0,
		615088286
	};
	static constexpr int const& inputs = 4;
	vector<vector<int>> input1 = {
		{2,3,6,8,4},
		{4,3,1},
		{5,2,1},
		{1,2,3}
	};
	vector<int> input2 = {
		1,
		1,
		0,
		0
	};
	vector<int> input3 = {
		3,
		0,
		2,
		2
	};
	vector<int> input4 = {
		5,
		6,
		3,
		40
	};
};