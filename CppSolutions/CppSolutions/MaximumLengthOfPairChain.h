#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/maximum-length-of-pair-chain/

class MaximumLengthOfPairChain
{
public:
	// 159 ms, faster than 66.32% : 22.8 MB, less than 69.55%
	int solution(vector<vector<int>> pairs) {
		int n = size(pairs);
		auto cmp = [](auto& a, auto& b) {return a[0] < b[0]; };
		sort(begin(pairs), end(pairs), cmp);
		Printer::print(pairs);

		int ans = 1;
		vector<int> len(n, 1);
		for (size_t i = 0; i < n; i++) {
			int hop = upper_bound(begin(pairs), end(pairs), pairs[i][1], [](auto& a, auto& b) {return a < b[0]; }) - begin(pairs);
			Printer::print(i, hop);
			for (size_t j = hop; j < n && pairs[j][0] > pairs[i][1]; j++) {
				len[j] = max(len[j], len[i] + 1);
				ans = max(ans, len[j]);
			}
		}

		return ans;
	}
	vector<int> output = {
		2,
		3,
		3
	};
	static constexpr int const& inputs = 1;
	vector<vector<vector<int>>> input1 = {
		{{1,2},{2,3},{3,4}},
		{{1,2},{7,8},{4,5}},
		{{-6,9},{1,6},{8,10},{-1,4},{-6,-2},{-9,8},{-5,3},{0,3}}
	};
};