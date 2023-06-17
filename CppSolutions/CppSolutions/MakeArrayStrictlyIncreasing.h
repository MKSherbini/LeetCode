#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/make-array-strictly-increasing/

class MakeArrayStrictlyIncreasing
{
public:
	// 1883 ms, faster than 5.23% : 436.3 MB, less than 5.23%
	int solution(vector<int> arr1, vector<int> arr2) {
		sort(begin(arr2), end(arr2));
		int n = size(arr1), m = size(arr2);
		const int OO = 1e8;
		vector mem(n, vector(m, vector<int>(2, -1)));
		function<int(int, int, bool)> f = [&](int i, int j, bool prevPicked) -> int {
			if (i >= n) return 0;
			if (mem[i][j][prevPicked] != -1) return mem[i][j][prevPicked];

			int last = prevPicked ? arr2[j] : arr1[i - 1];
			int ret = OO;
			int it = upper_bound(begin(arr2) + j, end(arr2), last) - begin(arr2);

			if (arr1[i] > last)
				ret = min(ret, f(i + 1, j, 0));

			if (it < m && (arr2[it] < arr1[i] || arr1[i] <= last)) {
				ret = min(ret, 1 + f(i + 1, it, 1));
			}

			return mem[i][j][prevPicked] = ret;
		};
		int ans = min(f(1, 0, 0), 1 + f(1, 0, 1));
		return ans == OO ? -1 : ans;
	}
	vector<int> output = {
		1,
		2,
		-1
	};
	static constexpr int const& inputs = 2;
	vector<vector<int>> input1 = {
		{1,5,3,6,7},
		{1,5,3,6,7},
		{1,5,3,6,7}
	};
	vector<vector<int>> input2 = {
		{1,3,2,4},
		{4,3,1},
		{1,6,3,3}
	};
};