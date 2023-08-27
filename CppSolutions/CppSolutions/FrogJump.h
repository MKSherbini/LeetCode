#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/frog-jump/

class FrogJump
{
public:
	// 75 ms, faster than 83.27% : 233 MB, less than 18.36%
	bool solution(vector<int> stones) {
		int n = size(stones);
		vector mem(n, vector(n, -1));
		function<bool(int, int)> f = [&](int i, int prevI) -> bool {
			if (i == n - 1) return true;
			if (prevI == -1) return stones[i + 1] == stones[i] + 1 ? f(i + 1, i) : false;
			if (mem[i][prevI] != -1) return mem[i][prevI];

			int k = stones[i] - stones[prevI];
			int hop = lower_bound(begin(stones), end(stones), stones[i] + k - 1) - begin(stones);
			if (hop == n) return false;
			if (hop == i) hop++;

			int ret = false;
			while (hop < n && (abs(stones[hop] - stones[i] - k) <= 1)) {
				Printer::print(i, hop);
				ret |= f(hop, i);
				hop++;
			}

			return mem[i][prevI] = ret;
		};

		return f(0, -1);
	}
	vector<int> output = {
		true,
		false
	};
	static constexpr int const& inputs = 1;
	vector<vector<int>> input1 = {
		{0,1,3,5,6,8,12,17},
		{0,1,2,3,4,8,9,11}
	};
};