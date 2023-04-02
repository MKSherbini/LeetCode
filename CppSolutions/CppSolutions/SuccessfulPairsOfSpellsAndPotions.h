#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/successful-pairs-of-spells-and-potions/

class SuccessfulPairsOfSpellsAndPotions
{
public:
	// 243 ms, faster than 75.28% : 97 MB, less than 99.56%
	vector<int> solution(vector<int> spells, vector<int> potions, int success) {
		int n = size(spells);
		sort(begin(potions), end(potions));

		vector<int> ans(n);
		for (size_t i = 0; i < n; i++)
			ans[i] = end(potions) -
			lower_bound(begin(potions), end(potions), (success + spells[i] - 1) / spells[i]);

		return ans;
	}
	vector<vector<int>> output = {
		{4,0,3},
		{2,0,2}
	};
	static constexpr int const& inputs = 3;
	vector<vector<int>> input1 = {
		{5,1,3},
		{3,1,2}
	};
	vector<vector<int>> input2 = {
		{1,2,3,4,5},
		{8,5,8}
	};
	vector<int> input3 = {
		7,
		16
	};
};