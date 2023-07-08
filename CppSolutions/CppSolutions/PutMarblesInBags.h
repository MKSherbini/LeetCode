#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/put-marbles-in-bags/

class PutMarblesInBags
{
public:
	// 187 ms, faster than 94.16% : 59.7 MB, less than 95.88%
	int solution(vector<int> weights, int k) {
		int n = size(weights);
		vector<int> splits(n - 1);

		for (int i = 1; i < n; i++) {
			splits[i - 1] = weights[i] + weights[i - 1];
		}

		sort(begin(splits), end(splits));

		k--;
		long long ans = 0;
		for (int i = 0; i < k; i++) {
			ans += splits[n - i - 2] - splits[i];
		}

		return ans;
	}
	vector<int> output = {
		4,
		0
	};
	static constexpr int const& inputs = 2;
	vector<vector<int>> input1 = {
		{1,3,5,1},
		{1,3}
	};
	vector<int> input2 = {
		2,
		2
	};
};