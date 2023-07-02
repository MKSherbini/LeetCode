#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/maximum-number-of-achievable-transfer-requests/

class MaximumNumberOfAchievableTransferRequests
{
public:
	// 141 ms, faster than 51.96% : 8.7 MB, less than 92.16%
	int solution(int n, vector<vector<int>> requests) {
		int m = size(requests);
		vector<int> groups(n);

		const int OO = 1e7;
		function<int(int, int)> f = [&](int i, int bad)-> int {
			if (i == m) {
				return bad ? -OO : 0;
			}
			int from = requests[i][0], to = requests[i][1];
			int ret = f(i + 1, bad);
			bad += groups[from] == 0;
			bad += groups[to] == 0;
			groups[from]--;
			groups[to]++;
			bad -= groups[from] == 0;
			bad -= groups[to] == 0;
			ret = max(ret, 1 + f(i + 1, bad));
			groups[from]++;
			groups[to]--;

			return ret;
		};

		return f(0, 0);
	}
	vector<int> output = {
		5,
		3,
		4,
		4
	};
	static constexpr int const& inputs = 2;
	vector<int> input1 = {
		5,
		3,
		4,
		3
	};
	vector<vector<vector<int>>> input2 = {
		{{0,1},{1,0},{0,1},{1,2},{2,0},{3,4}},
		{{0,0},{1,2},{2,1}},
		{{0,3},{3,1},{1,2},{2,0}},
		{{1,2},{1,2},{2,2},{0,2},{2,1},{1,1},{1,2}}
	};
};