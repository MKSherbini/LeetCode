#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/partition-array-for-maximum-sum/?envType=daily-question&envId=2024-02-03

class PartitionArrayForMaximumSum
{
public:
	// 18 ms, faster than 37.9% : 12 MB, less than 7.15%
	int solution(vector<int> arr, int k) {
		int n = size(arr);
		vector<int> mem(n, -1);
		function<int(int)> f = [&](int st) -> int {
			if (st >= n) return 0;
			int& ret = mem[st];
			if (ret != -1) return ret;

			int end = min(n, st + k);
			int mx = 0;
			for (int i = st; i < end; i++) {
				mx = max(mx, arr[i]);
				ret = max(ret, mx * (i - st + 1) + f(i + 1));
			}

			return ret;
		};

		return f(0);
	}
	vector<int> output = {
		84,
		83,
		1
	};
	static constexpr int const& inputs = 2;
	vector<vector<int>> input1 = {
		{1,15,7,9,2,5,10},
		{1,4,1,5,7,3,6,1,9,9,3},
		{1}
	};
	vector<int> input2 = {
		3,
		4,
		1
	};
};