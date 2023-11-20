#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/minimum-amount-of-time-to-collect-garbage/?envType=daily-question&envId=2023-11-20

class MinimumAmountOfTimeToCollectGarbage
{
public:
	// 198 ms, faster than 13.35% : 102.4 MB, less than 91.88%
	int solution(vector<string> garbage, vector<int> travel) {
		int t = 0;
		unordered_map<char, int> move;
		unordered_map<char, int> cnt;
		int n = size(garbage);
		for (size_t i = 0; i < n; i++) {
			if (i > 0) t += travel[i - 1];
			for (auto c : garbage[i]) {
				cnt[c]++;
				move[c] = t;
			}
		}

		Printer::print(cnt, move);
		int ans = 0;
		for (auto [c, x] : move) {
			ans += x + cnt[c];
		}

		return ans;
	}
	vector<int> output = {
		21,
		37
	};
	static constexpr int const& inputs = 2;
	vector<vector<string>> input1 = {
		{"G","P","GP","GG"},
		{"MMM","PGM","GP"}
	};
	vector<vector<int>> input2 = {
		{2,4,3},
		{3,10}
	};
};