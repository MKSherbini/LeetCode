#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/predict-the-winner/

class PredictTheWinner
{
public:
	// 0 ms, faster than 100% : 8.4 MB, less than 10.3%
	bool solution(vector<int> nums) {
		int n = size(nums);
		int sum = accumulate(begin(nums), end(nums), 0);
		vector mem(n, vector(n, vector(2, -1)));
		function<int(int, int, bool)> f = [&](int i, int j, bool take) -> int {
			if (i > j) return 0;
			if (mem[i][j][take] != -1) return mem[i][j][take];

			return mem[i][j][take] = take ?
				max(f(i + 1, j, 0) + nums[i], f(i, j - 1, 0) + nums[j]) :
				min(f(i + 1, j, 1), f(i, j - 1, 1));
		};

		return f(0, n - 1, 1) >= sum - f(0, n - 1, 1);
	}
	vector<int> output = {
		false,
		true
	};
	static constexpr int const& inputs = 1;
	vector<vector<int>> input1 = {
		{1,5,2},
		{1,5,233,7}
	};
};