#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/maximal-network-rank/

class MaximalNetworkRank
{
public:
	// 59 ms, faster than 94.53% : 33.7 MB, less than 53.03%
	int solution(int n, vector<vector<int>> roads) {
		vector<set<int>> adj(n);
		vector<int> cnt(n);

		for (auto& r : roads)
			cnt[r[0]]++, cnt[r[1]]++,
			adj[min(r[0], r[1])].insert(max(r[0], r[1]));

		int ans = 0;
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				ans = max(ans, cnt[i] + cnt[j] - adj[i].contains(j));
			}
		}

		return ans;
	}
	vector<int> output = {
		4,
		5,
		5
	};
	static constexpr int const& inputs = 2;
	vector<int> input1 = {
		4,
		5,
		8
	};
	vector<vector<vector<int>>> input2 = {
		{{0,1},{0,3},{1,2},{1,3}},
		{{0,1},{0,3},{1,2},{1,3},{2,3},{2,4}},
		{{0,1},{1,2},{2,3},{2,4},{5,6},{5,7}}
	};
};