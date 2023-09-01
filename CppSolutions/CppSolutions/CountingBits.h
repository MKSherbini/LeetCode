#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/counting-bits/

class CountingBits
{
public:
	// 0 ms, faster than 100% : 7.7 MB, less than 89.73%
	vector<int> solution(int n) {
		vector<int> ans(n + 1);
		for (int i = 0; i < n + 1; i++) {
			int cnt = 0, x = i;
			while (x)
				cnt += x & 1, x >>= 1;

			ans[i] = cnt;
		}
		return ans;
	}
	vector<vector<int>> output = {
		{0,1,1},
		{0,1,1,2,1,2},
	};
	static constexpr int const& inputs = 1;
	vector<int> input1 = {
		2,
		5,
	};
};


