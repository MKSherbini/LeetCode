#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/counting-bits/

class CountingBits
{
public:
	// 3 ms, faster than 91.69% : 7.7 MB, less than 88.27%
	vector<int> solution(int n) {
		vector<int> ans(n + 1);
		for (int i = 0; i < n + 1; i++)
		{
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
	vector<int> input1 = {
		2,
		5,
	};
};

