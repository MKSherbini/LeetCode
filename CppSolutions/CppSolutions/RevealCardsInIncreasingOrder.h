#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/reveal-cards-in-increasing-order/

class RevealCardsInIncreasingOrder
{
public:
	// 0 ms, faster than 100% : 10.6 MB, less than 100%
	vector<int> solution(vector<int> deck) {
		sort(begin(deck), end(deck));
		int n = size(deck);
		int i = 0, j = 0;
		vector<int> ans(n);
		bool skip = 0;
		while (j < n) {
			if (!ans[i]) {
				if (!skip)
					ans[i] = deck[j++];
				skip = !skip;
			}

			i++;
			i %= n;
		}

		return ans;
	}

	// too lazy to find pattern
	vector<int> solution2(vector<int> deck) {
		sort(begin(deck), end(deck));
		int n = size(deck);
		int it = 0;
		vector<int> ans(n);
		while (true) {
			for (size_t i = 0; i < n; i += 2) {
				ans[i] = deck[it++];
			}
			break;
		}

		return ans;
	}
	vector<vector<int>> output = {
		{2,13,3,11,5,17,7},
		{1,1000}
	};
	static constexpr int const& inputs = 1;
	vector<vector<int>> input1 = {
		{17,13,11,2,3,5,7},
		{1,1000}
	};
};