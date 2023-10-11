#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/number-of-flowers-in-full-bloom/?envType=daily-question&envId=2023-10-11

class NumberOfFlowersInFullBloom
{
public:
	// 250 ms, faster than 60.8% : 94.4 MB, less than 25.95%
	vector<int> solution(vector<vector<int>> flowers, vector<int> ppl) {
		int n = size(ppl);
		vector<pair<int, int>> s;
		for (size_t i = 0; i < size(ppl); i++) {
			s.push_back({ ppl[i], i });
		}
		sort(begin(s), end(s));
		Printer::print(s);

		vector<int> cnts(n);
		for (auto& f : flowers) {
			int l = lower_bound(begin(s), end(s), pair{ f[0], 0 }) - begin(s);
			int r = upper_bound(begin(s), end(s), pair{ f[1], n }) - begin(s);
			Printer::print(l, r);
			if (l < n)
				cnts[l]++;
			if (r < n)
				cnts[r]--;
		}

		vector<int> ans(n);
		int x = 0;
		for (size_t i = 0; i < n; i++) {
			x += cnts[i];
			ans[s[i].second] = x;
		}

		return ans;
	}
	vector<vector<int>> output = {
		{1,2,2,2},
		{2,2,1},
		{0,1,1,1,1,1,0}
	};
	static constexpr int const& inputs = 2;
	vector<vector<vector<int>>> input1 = {
		{{1,6},{3,7},{9,12},{4,13}},
		{{1,10},{3,3}},
		{{11, 11},{24, 46},{3, 25},{44, 46}}
	};
	vector<vector<int>> input2 = {
		{2,3,7,11},
		{3,3,2},
		{1, 8, 26, 7, 43, 26, 1 }
	};

};